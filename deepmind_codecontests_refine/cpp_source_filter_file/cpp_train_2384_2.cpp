#include<cstdio>
#include<algorithm>
main(){
while(true){
int x[15000],n,i,j,k,l,m,y[15000],b,c,d,p[15000],minx;
scanf("%d", &n);
if(n==0){break;}
for(i=0;i<n;i++){scanf("%d", &y[i]);p[i] = x[i] = y[i];}
c=0;d=0;m=n;d=m;
minx=99999;
for(i=0;i<n;i++){
for(j=1;j<=3;j++){
if(i>=1 && (y[i-1]!=j && y[i+1]!=j)){goto z;}
p[i] = x[i] = j;
b=1;d=n;
while(true){c=0;
for(k=0;k<m;k++){
if(p[k]==p[k+1]){b++;}
else{
if(b >= 4){
for(l = k + 1; l < m; l++){p[l-b] = p[l];}
d -= b;c++;
for(l=d;l<m;l++){p[l]=0;}
}
b=1;}   
m=d;}
if(c==0){break;}
else{c=0;}
}
minx=min(minx,m);x[i]=y[i];
for(int k=0;k<n;k++){p[k]=y[k];}
z:;
}
}
printf("%d\n", minx);}
}