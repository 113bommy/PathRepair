#include <bits/stdc++.h>
using namespace std;
const int MOD = 0;
const double eps = 1e-3;
const unsigned int MAXN = 2e5 + 59;
const int INF = 0x3f3f3f3f;
const long long INFll = 0x3f3f3f3f3f3f3f;
int n, kase;
int a[MAXN];
int b[MAXN];
int c[MAXN];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    c[b[i]] = i;
  }
  int ans = 0;
  for (int t = 0, i = 1; i <= n; ++i) {
    t = max(t, c[a[i]]);
    if (t > c[a[i]]) ans++;
  }
  cout << ans << endl;
  return 0;
}
