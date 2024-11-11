#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ll a;
  cin >> a;
  ll ans,k=0;
  ll n=a;
  while(a>9){
    a/=10;
    k++;
  }
  ans=9*k+a-1;
  if(n%pow(10,k)==0)ans++;
  cout << ans;
}
