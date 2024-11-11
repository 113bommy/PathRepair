#include<bits/stdc++.h>
using namespace std;
int n,k,i,j,A[100000],cost[100000];
int main(){
  cin>>n>>k;
  for(i=0;i<n;i++)
    cin>>A[i];
  cost[0]=0;
  for(i=1;i<n;i++){
    mn=INT_MAX;
    for(j=1;j<=k;j++){
      if(i-j>=0){
        mn=min(abs(A[i]-A[i-j])+cost[i-j],mn);}}
    cost[i]=mn;}
  cout<<cost[n-1];}