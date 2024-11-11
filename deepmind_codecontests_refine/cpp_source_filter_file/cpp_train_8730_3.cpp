#include <stdio.h>
int main(void){
int n;
while(scanf("%d",&n)!=EOF){
int count=0;
for(int a=9;a>=0;a--){
for(int b=9;b>=0;b--){
for(int c=9;c>=0;c--){
for(int d=9;d>=0;d--){
if(a+b+c+d==n){
count++;
}
}
}
}
}
}
printf("%d\n",count);
return 0;
}