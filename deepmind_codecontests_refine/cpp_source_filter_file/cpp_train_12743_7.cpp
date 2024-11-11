#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,popcnt,abm,mmx")
using namespace std;
bool isvowel(char c) {
  c = tolower(c);
  if (c == 'a' || c == 'e' || c == 'i' || c == 'y' || c == 'o' || c == 'u')
    return 1;
  return 0;
}
const double eps = 0.000001;
const long double pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const long long MOD = 1e18 + 9;
const long long INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 3e5 + 123;
const int PRI = 555557;
const int pri = 997;
int tests = 1;
int n, k;
double a[2002], s, ans = 1e9;
inline void Solve() {
  cin >> n;
  for (int i = 1; i <= n * 2; i++) {
    cin >> a[i];
    a[i] -= (int)a[i];
    if (fabs(a[i]) < 1e-5) ++k;
    s += a[i];
  }
  for (int i = 0; i <= n; i++)
    if (i + k >= n) ans = min(ans, fabs(s - i));
  cout << fixed << setprecision(4) << ans;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  while (tests--) {
    Solve();
  }
  return 0;
}
