#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 10;
const long long M = 1e14;
const long long big = 1e17;
const long long hsh2 = 1964325029;
const long long mod = 998244353;
const long double EPS = 1e-20;
const long long block = 1e14;
const long long shift = 2e3;
const long double pi = acos(-1.0);
long long a, b;
long double solve1(long long a, long long b) {
  long long db = a + b;
  long long l = 0, r = 1e9, k = 1;
  while (l <= r) {
    long long m = (l + r) >> 1ll;
    if (db >= 2ll * b * m)
      k = m, l = m + 1;
    else
      r = m - 1;
  }
  if (k == 0) return 1e9;
  long double an = (db + 0.0) / (2.0 * (k + 0.0));
  return an;
}
long double solve2(long long a, long long b) {
  long long db = a - b;
  if (db < 0) return 1e9;
  long long l = 0, r = 1e9, k = 1;
  while (l <= r) {
    long long m = (l + r) >> 1ll;
    if (db >= 2ll * b * m)
      k = m, l = m + 1;
    else
      r = m - 1;
  }
  if (k == 0) return 1e9;
  long double an = (db + 0.0) / (2.0 * (k + 0.0));
  return an;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> a >> b;
  long double ans1 = solve1(a, b), ans2 = solve2(a, b);
  if (min(ans1, ans2) == 1e9) cout << -1, exit(0);
  cout << fixed << setprecision(9) << min(ans1, ans2);
}
