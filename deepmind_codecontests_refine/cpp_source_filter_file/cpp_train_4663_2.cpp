#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll n,a;
  cin>>n;
  ll ans=1;
  for(ll i=2;i*i=<n;i++){
    if(n%i==1){
      if(i*i==n-1) ans++; 
      else ans+=2;
    }
    else if(n%i==0){
      a=n;
      while(a%i==0){
        a/=i;
      }
      if(a%i==1) ans++;
    }
  }
  if(n!=2) ans++;
  cout<<ans<<endl;
  
}
 