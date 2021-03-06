/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobion <arobion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:24:06 by arobion           #+#    #+#             */
/*   Updated: 2018/05/13 16:31:52 by arobion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 1080
# define WRITE_SIZE 4096
# define HASH_TABLE_SIZE 65536
# define READ_SIZE 65536

static char			g_err_message[13] =
{
	':',
	' ',
	'N',
	'o',
	't',
	' ',
	'f',
	'o',
	'u',
	'n',
	'd',
	'.',
	'\n'
};

typedef struct		s_save
{
	char			*save_line;
	int				size;
	struct s_save	*next;
}					t_save;

typedef struct		s_entry
{
	int				key;
	int				val;
	struct s_entry	*next;
}					t_entry;

typedef struct		s_table
{
	char			buff[WRITE_SIZE];
	int				index_buff;
	int				size;
	struct s_entry	**entry;
}					t_table;

int					hr_strlen(const char *str);
void				store(t_table *table, char *line, int key, int val);
int					allocate_table(t_table *table, int size);
int					hash(char *str, int i, int table_size);
void				search(t_table *table, char *line, int key);
void				fill_buff(t_table *table, char *str, int index);
void				fill_buff_not_found(t_table *table, char *str, int index);
int					fill_line(char **line);
void				store_phase(t_table *table, char *line, int *i);
void				search_phase(t_table *tabvle, char *line, int *i);
void				free_all(t_table *table, char *line);
int					is_end(char *line, int index);

#endif
