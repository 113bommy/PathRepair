#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll n,k,m=0;
  cin>>n>>k;
  ll a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(i!=0){
      if(a[i]+a[i-1]>=k){
        m=i;
      }
    }
  }
  if(m==0)cout<<"Impossible";
  else{
    cout<<"Possible"<<endl;
    for(int i=1;i<m;i++) cout<<i<<endl;
    for(int i=n-1;i>=m;i--) cout<<i<<endl;
  }
}