#include <stdio.h>
int main()
{
  int a,b,cou;
  for(cou=0;cou<7;cou++){
    scanf("%d %d",&a,&b);
    printf("%d\n",a-b);
  }
  return 0;
}