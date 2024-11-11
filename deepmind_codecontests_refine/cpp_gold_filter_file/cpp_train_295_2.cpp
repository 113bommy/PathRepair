#include<stdio.h>

int main(){
int x,y,z;
int N=0,W=0;
while(scanf("%d,%d,%d",&x,&y,&z)!=EOF){
if(z*z==x*x+y*y)N++;
else if(x==y)W++;
}
printf("%d\n%d\n",N,W);
return 0;
}