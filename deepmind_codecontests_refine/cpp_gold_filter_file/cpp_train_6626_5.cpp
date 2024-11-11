#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll mod = 1000000007;
int main() {
  int n, x;
  cin >> n >> x;
  string s;
  cin >> s;
  if (x <= 1) {
    if (n > 1 || ((x == 0) ^ (s[0] == '0')))
      cout << 0 << "\n";
    else
      cout << 1 << "\n";
  } else {
    vector<vector<ll> > c1(n, vector<ll>(n, 0));
    vector<vector<ll> > c2(n, vector<ll>(n, 0));
    vector<vector<ll> > c3(n, vector<ll>(n, 0));
    ll l1 = 2;
    ll l2 = 2;
    ll l3;
    for (int i = 0; i < n; ++i)
      if (s[i] == '0')
        c1[i][i] = 1;
      else
        c2[i][i] = 1;
    for (int i = 2; i <= x; ++i) {
      for (int d = 0; d < n; ++d)
        for (int f = d; f < n; ++f) {
          ll t1 = c1[d][f];
          if (d == 0) {
            t1 *= l2;
            t1 %= mod;
          }
          ll t2 = c2[d][f];
          if (f == n - 1) {
            t2 *= l1;
            t2 %= mod;
          }
          c3[d][f] = t1 + t2;
          c3[d][f] %= mod;
          for (int k = d; k < f; ++k) {
            c3[d][f] += c2[d][k] * c1[k + 1][f];
            c3[d][f] %= mod;
          }
        }
      swap(c1, c2);
      swap(c2, c3);
      l3 = l1 * l2;
      l3 %= mod;
      swap(l1, l2);
      swap(l2, l3);
    }
    cout << c2[0][n - 1] << "\n";
  }
  return 0;
}
