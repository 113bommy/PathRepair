#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int N = 1e5 + 5;
const int MOD = 998244353;
int inverse(int a) {
  int rv = 1;
  int b = MOD - 2;
  while (b) {
    if (b & 1) rv = (rv * 1LL * a) % MOD;
    a = (a * 1LL * a) % MOD;
    b /= 2;
  }
  return rv;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> p(n);
  for (int &e : p) {
    cin >> e;
    e = 1LL * e * inverse(100) % MOD;
  }
  int m = 1;
  int res = 0;
  for (int i = 0; i < n; i++) {
    (res += m) %= MOD;
    m = (LL)m * p[i] % MOD;
  }
  res = (LL)res * inverse(m) % MOD;
  cout << res << endl;
}
