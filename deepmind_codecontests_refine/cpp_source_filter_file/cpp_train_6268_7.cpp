#include <bits/stdc++.h>
using namespace std;
const int MAXn = 3e5 + 5;
const long long INF = 1e18;
const long long mod = 998244353;
long long bin_expo(long long a, long long b, long long m) {
  long long res = 1LL;
  while (b > 0) {
    if (b % 2 == 1) {
      res = (res * a) % m;
    }
    a = (a * a) % m;
    b = b / 2;
  }
  return res;
}
int main() {
  long long n;
  cin >> n;
  map<long long, long long> m;
  vector<vector<long long> > v(n);
  for (int i = 0; i < n; i++) {
    long long k;
    cin >> k;
    while (k--) {
      long long a;
      cin >> a;
      v[i].push_back(a);
      m[a]++;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long temp = 0;
    for (int j = 0; j < (int)v[i].size(); j++) {
      temp += (m[v[i][j]] * bin_expo(n, mod - 2, mod)) % mod;
    }
    long long k = v[i].size();
    temp = (temp * bin_expo(k, mod - 2, mod)) % mod;
    ans = (ans + temp) % mod;
  }
  ans = (ans * bin_expo(n, mod - 2, mod)) % mod;
  cout << ans;
}
