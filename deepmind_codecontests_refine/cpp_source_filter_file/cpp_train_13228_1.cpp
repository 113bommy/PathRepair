#include<cstdio>
int main(void){
int a[100][100];
int b[100];
int c[100];
int n,m;
scanf("%d %d",&n,&m);
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
scanf("%d",&a[i][j]);
}
}
for(int i=0;i<m;i++)scanf("%d",&b[i]);
for(int i=0;i<n;i++){
c[i]=0;
for(int j=0;j<m;j++){
c[i]=a[i][j]*b[j]+c[i]
}
printf("%d\n",c[i]);
}
}