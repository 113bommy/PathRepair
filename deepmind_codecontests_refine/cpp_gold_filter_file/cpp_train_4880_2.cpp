#include <stdio.h>

int main(){
int n,i,j;
int a,b,c,f;

scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d",&a);
b=0;
f=0;
for(j=1;j<10;j++){
scanf("%d",&c);
if(a>c&&b>c)f=1;
else if(a<c&&b<c){
if(a>b)a=c;
else b=c;
}
else{
if(a>b)b=c;
else a=c;
}
}
if(f==0){
printf("YES\n");
}
else if(f==1){
printf("NO\n");
}
}
return 0;
}