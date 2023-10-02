#include <stdlib.h>

typedef struct s_table 
{
	int			 content;
	struct s_table  *next;
}				t_table;

void	lst_addback(t_table **lst, int content)
{
	t_table *ptr;
	t_table *new;

	if (lst == NULL)
		return ;
	ptr = *lst;
	new = (t_table *)molloc(sizeof(t_table));
	new->content = content;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
	return ;
}

int solve(int *nums, int numsSize, int remain, int idx, t_table **head)
{
	if (idx > numsSize)
		return 0;
	if (remain - nums[idx] > 0)
	{
		idx++;
		while (solve(nums, numsSize, remain, idx))
		{
			idx++;
		}
	}
	else if ((remain - nums[idx]) < 0)
		return (0);
	else
		return (solve(nums, numsSize, remain, idx + 1));
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int	 chk;
	int	 *result;
	t_table *table;

	table = NULL;
	chk = solve(nums, numsSize, target, 0, &table);
	result = (int *)malloc(sizeof(int) * );

}