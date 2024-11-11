#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll l,r; 
  cin >> l >> r;
  
  ll m = 2018;
  
  r = min(r, l+4038);
  for (ll i=l; i<r; i++){
    for (ll j=i+1;j<=r;j++){
      int x = i*j%2019
      m = min(m, x);
    }
  }
  cout << m << endl;
}
