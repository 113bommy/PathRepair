#include<stdio.h>
int main(){
int n,t,s,r;
t=0;s=0;
int a[100],b[100];
scanf("%d",&n);
for(int k=0;k<n;k++){
scanf("%d",&a[k]);
}
for(int k=0;k<n;k++){
scanf("%d",&b[k]);
}
for(int k=0;k<n;k++){
t=t+a[k];
s=t;
for(int l=k;l<n;l++){
s=s+b[l];
}
if(s>r)r=s;
}
printf("%d",r);
return 0;
}
