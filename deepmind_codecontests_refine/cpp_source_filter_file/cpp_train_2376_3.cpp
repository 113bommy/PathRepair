#include<stdio.h>
int main(){
int h,w,a[555][555],i,j,n=0,x1[200000],x2[200000],y1[200000],y2[200000];
scanf("%d%d",&h,&w);
for(i=1;i<=h;i++){
for(j=1;j<=w;j++)
scanf("%d",&a[i][j]);
}
for(i=1;i<=h;i++){
for(j=1;j<w;j++){
if(a[i][j]%2==1){
y1[n]=i;
y2[n]=i;
x1[n]=j;
x2[n]=j+1;
n++;
a[i][j]--;
a[i][j+1]++;
}
for(i=1;i<h;i++){
if(a[i][w]%2==1){
y1[n]=i;
y2[n]=i+1;
x1[n]=w;
x2[n]=w;
n++;
a[i][w]--;
a[i+1][w]++;
}
}
printf("%d\n",n);
for(i=0;i<n;i++)
printf("%d %d %d %d\n",y1[i],x1[i],y2[i],x2[i]);
return 0;
}
