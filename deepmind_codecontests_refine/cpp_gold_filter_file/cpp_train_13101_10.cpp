#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll n,c,k;
  cin>>n>>c>>k;
  vector<ll> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  sort(a.begin(),a.end());
  ll cnt=1,knt=a[0],count=1;
  for(int i=1;i<n;i++){
    if(a[i]-knt<=k&&cnt<c){
      cnt++;
    }else{
      count++;
      knt=a[i];
      cnt=1;
    }
  }
  cout<<count;
}