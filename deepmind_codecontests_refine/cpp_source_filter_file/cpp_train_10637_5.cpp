#include <bits/stdc++.h>
using namespace std;
const int imax = 1e9 + 7;
const long long lmax = 1e18;
vector<int> v;
int calc() {
  long long i, n, val, ans = 0, m, d;
  cin >> n;
  v.resize(n);
  for (i = 0; i < ((int)v.size()); ++i) cin >> v[i];
  const long long Mod = 998244353;
  for (i = 0; i < n; ++i) {
    cin >> v[i];
    m = 1;
    while (val > 0) {
      d = val % 10;
      val /= 10;
      ans += (d * n * m) % Mod;
      ans %= Mod;
      m = (m * 10) % Mod;
      ans += (d * n * m) % Mod;
      ans %= Mod;
      m = (m * 10) % Mod;
    }
  }
  cout << ans;
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  calc();
  return 0;
}
