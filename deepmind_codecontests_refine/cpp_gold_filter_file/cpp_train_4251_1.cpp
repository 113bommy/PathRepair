#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll fact[3000005];

ll pow(ll a, ll x) {
  ll res = 1;
  while(x > 0) {
    if(x & 1) res = res * a % mod;
    a = a * a % mod;
    x >>= 1;
  }
  return res;
}

ll nCr(ll n, ll r) {
  return fact[n] * (pow(fact[n-r],mod-2) * pow(fact[r],mod-2) % mod) % mod;
}


int main() {
  ll n,m;
 
  cin >> n >> m;
  fact[0] = 1;
 
  for(ll i = 1; i <= 3000000; i++) fact[i] = fact[i-1] * i % mod;
  
  

  ll ans = 1;
 
    for(ll i = 2; i < 3000000; i++) {
      if(m % i != 0) continue;
    ll k = 0;
    while(m % i == 0) {
      m /= i;
      k++;
    }
    ans = ans * nCr(k+n-1,k) % mod;
      }

    if(m != 1) cout << ans * n % mod << endl;
    else 
      cout << ans << endl;
}
    
    
  
