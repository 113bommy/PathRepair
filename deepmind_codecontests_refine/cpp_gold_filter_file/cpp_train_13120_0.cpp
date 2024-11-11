#include <stdio.h>
int main(void)
{
int i,sum=0;
int flag=0;

char x[1002];
scanf("%s",x);
do{
for(i=0;i<1002;i++){
if(x[i]==0){
  printf("%d\n",sum);
  break;
}else{
sum+=x[i]-0X30;
}
}
sum=0;
scanf("%s",x);
}while(x[0]!=0X30);

return 0;
}