#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
 	

  ll n,k; cin >> n >> k;
  map<int,ll> m;
  
  for(int i=0; i<n; i++) {
    ll a,b; cin >> a >> b;
    m[a]+=b;
  }
  
  ll sum = 0;
  for(auto x:m){
   	 sum += m.second;
    if( sum >= k ) {
      cout << x.first << endl;
      break;
    }
  }
     
}