#include "stdio.h"
 
int main()
{
  char str[7];
  scanf("%[^\n]", str);
  
  printf(str[2] == str[3] && str[4] == str[5] ? "Yes\n" : "No\n");
}