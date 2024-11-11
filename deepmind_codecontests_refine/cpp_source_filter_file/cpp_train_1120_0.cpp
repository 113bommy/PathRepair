#include <iostream>
using namespace std;
typedef long long l;
l n,k,r=0;l h[400005]={0};l L[12]={0};l M=998244353;
int main(){
  cin>>n>>k;h[1]=1;h[2]=-1;
  for(int i=0;i<k;i++)cin>>L[i][0]>>L[i][1];
  for(int i=1;i<n;i++){r=(r+h[i]+100*M)%M;
    for(int j=0;j<k;j++){h[L[j][0]+i]+=r;h[L[j][1]+i+1]-=r;}
  }  cout<<((r+h[n])+100*M)%M<<endl;}