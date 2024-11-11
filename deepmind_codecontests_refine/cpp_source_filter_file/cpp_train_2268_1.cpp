#   include <stdio.h>
int main (void)
{
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  if((a==b&&a!=c)||(a==c&&a!=b)||(b==c&&b!=a)
     printf("Yes\n");
  else
     printf("No\n");
  return 0;
}