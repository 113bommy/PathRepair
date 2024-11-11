#include <stdio.h>
#include<math.h>
#include <string.h>
#include <ctype.h>

int main(){
int a[1001],i,n,m,f,t;

while(1){
scanf("%d %d",&n,&m);
if(n==0&&m==0)break;
for(i=1;i<=n;i++)a[i]=i;
i=1;
f=0;
t=0;
while(1){
if(t==n-1)break;
if(a[i]!=0)f++;
if(f==m){
a[i]=0;
t++;
f=0;
}
i++;
if(i==n+1)i=1;
}
for(i=1;i<=n;i++){
if(a[i]!=0){
printf("%d\n",a[i]);
}
}
}
return 0;
}