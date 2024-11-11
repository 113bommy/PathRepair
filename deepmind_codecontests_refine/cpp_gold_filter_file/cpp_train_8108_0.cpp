#include <stdio.h>

int main(){
int n,i;
int a,b,f,t;

while(1){
scanf("%d",&n);
if(n==0)break;
a=0;
b=0;
f=0;
t=0;
for(i=0;i<n;i++){
scanf("%d %d",&a,&b);
if(a==b){
f+=a;
t+=b;
}
else if(a>b){
f+=a+b;
}
else if(a<b){
t+=a+b;
}
}
printf("%d %d\n",f,t);
}

return 0;
}