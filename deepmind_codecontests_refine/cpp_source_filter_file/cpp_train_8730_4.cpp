#include<iostream>
using namespace std;int main(){for(int i,c,k,n,j;cin>>n;k=0){i=0;i<1e4;i++,c=0){for(j=i;j>0;j/=10)c+=j%10;if(c==n)k++;}cout<<k<<endl;}}