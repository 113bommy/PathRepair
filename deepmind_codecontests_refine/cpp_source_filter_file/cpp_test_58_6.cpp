#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double EPS = 1e-8;
const int INF_INT = 1e9 + 100;
const long long INF_LL = 1e18;
const int maxn = 5e3 + 10;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
const int mod3 = 1e9 + 33;
const int K = 318;
void solve() {
  int n;
  cin >> n;
  string s[2];
  cin >> s[0] >> s[1];
  int f = 0;
  for (int i = 0; i < n; ++i) {
    if (s[0][i] == '1' && s[1][i] == '1') f = 1;
  }
  if (f || s[1][n - 1])
    cout << "NO\n";
  else
    cout << "YES\n";
}
int32_t main() {
  cout << fixed << setprecision(10);
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
