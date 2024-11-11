#include<bits/stdc++.h>
using namespace std;
int n[200][3],x,y[200],z[200];
int main(){
cin>>x;
for(int i=0;i<x;i++){cin>>n[i][0]>>n[i][1]>>n[i][2];}
for(int i=0;i<3;i++){memset(z,0,sizeof(z));
for(int k=0;k<200;k++){z[n[k][i]]++;}
for(int j=0;j<x;j++){if(z[n[j][i]]==1){y[j]+=n[j][i];}}
}
for(int i=0;i<x;i++){cout<<y[i]<<endl;}}