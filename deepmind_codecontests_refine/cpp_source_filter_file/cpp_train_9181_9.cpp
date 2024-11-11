#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 314;
const int INF = 1e9;
const double PI = acos(-1);
const int MOD = 1e9 + 7;
const double eps = 1e-9;
int d[N], b[N], p[N], s[N];
pair<int, int> h;
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) b[i] = 0;
  for (int i = 0; i < m; ++i) {
    cin >> p[i] >> s[i];
    b[s[i]] = max(b[s[i]], p[i]);
  }
  for (int i = n - 1; i >= 0; --i) b[i] = max(b[i], b[i + 1]);
  int p = 0;
  int ans = 0;
  while (p < n) {
    ans++;
    int npos = p;
    int mx = 0;
    while (npos < n) {
      mx = max(mx, d[npos]);
      if (mx > b[npos - p + 1]) break;
      ++npos;
    }
    if (npos == p) {
      cout << "-1\n";
      return;
    }
    p = npos;
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
}
