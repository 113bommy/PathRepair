#include<iostream>
using namespace std;
int main(){
int a,b,c,k,x[1000][4],p[500];
while(true){
for(int i=0;i<500;i++){p[i]=2;}
cin>>a>>b>>c;
if(a==0 && b==0 && c==0){break;}
cin>>k;
for(int i=0;i<k;i++){
cin>>x[i][0]>>x[i][1]>>x[i][2]>>x[i][3];
if(x[i][3]==1){p[x[i][0]]=1;p[x[i][1]]=1;p[x[i][2]]=1;}
}
for(int i=0;i<k;i++){
if(p[x[i][0]]==1 && p[x[i][1]]==1&& x[i][3]==0){p[x[i][2]]=0;}
if(p[x[i][0]]==1 && p[x[i][2]]==1&& x[i][3]==0){p[x[i][1]]=0;}
if(p[x[i][1]]==1 && p[x[i][2]]==1&& x[i][3]==0){p[x[i][0]]=0;}
}
for(int i=1;i<=a+b+c;i++){cout<<p[i]<<endl;}
return 0;
}