#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j;ll cnt;
  int n;
  cin>>n;
  ll a[n];
  for(i=0;i<n;i++)cin>>a[i];
  ll sum=0;
  for(i=0;i<n;i++)sum+=a[i];
  cnt=0;
  ll mi=INT_MAX;
  for(i=0;i<n;i++){
    cnt+=a[i];
    mi=min(max(sum-2*cnt,2*cnt-sum),mi);
  }
  cout<<mi;
}