#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll n,j=0;
  cin>>n;
  vector<ll> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  sort(a.begin(),a.end());
  for(int i=1;i<n;i++){
    if(a[i-1]*2<a[i]){
      j=i;
    }
    a[i]+=a[i-1];
  }
  cout<<n-j;
}