#include<iostream>
using namespace std;
int main(){
int n,m,i,j,k,l,x[9999][2],y[9999][2],x2,y2,c,a;
while(true){
cin>>m;
if(m==0){break;}
for(i=0;i<m;i++){cin>>x[i][0]>>y[i][0];}
cin>>n;
for(i=0;i<n;i++){cin>>x[i][1]>>y[i][1];}
for(i=0;i<m;i++){
for(j=0;j<n;j++){
a=0;x2=x[j][1]-x[i][0];y2=y[j][1]-y[i][0];
for(k=0;k<m;k++){c=0;
for(l=0;l<n;l++){
if(x[k][0]+x2==x[l][1] && y[k][0]+y2==y[l][1]){c++;break;}
}
if(c==0){break;}
a++;
if(a==m){goto z;}
}
}
}
z:;
cout<<x2<<' '<<y2<<endl;
}
}