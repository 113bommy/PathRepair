#include <stdio.h>

int a,b;
char op;

int main()
{
  scanf("%d %c %d",&a,&op,&b);
  if(op == '+') a+=b;
  else a-=b;
  printf("%d",a);
  return 0;
}