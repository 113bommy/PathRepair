#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int N = 1e5 + 10;
const long long mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
int f[N], n, m, g[N], h[N], vis[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  m = 0;
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; i++) {
    cin >> f[i];
    if (f[i] == i) {
      h[++m] = i;
      vis[i] = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[f[i]]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << m << endl;
  for (int i = 1; i <= n; i++) {
    cout << vis[f[i]] << " ";
  }
  cout << endl;
  for (int i = 1; i <= m; i++) {
    cout << h[i] << " ";
  }
  cout << endl;
}
