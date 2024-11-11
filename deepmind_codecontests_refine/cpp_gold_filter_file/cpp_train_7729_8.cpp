#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - '0', c = getchar();
  return x * f;
}
int f[N], vis[N];
vector<int> g[N];
int main() {
  int T = read();
  while (T--) {
    int n = read(), m = read();
    for (int i = 1; i <= n; i++) f[i] = vis[i] = 0, g[i].clear();
    for (int i = 1; i <= m; i++) {
      int u = read(), v = read();
      g[v].push_back(u);
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
      int ok = 0;
      if (!vis[i])
        for (int to : g[i])
          if (!vis[to] && !ok)
            for (int v : g[to])
              if (!vis[v]) {
                ok = 1;
                break;
              }
      if (ok) {
        ans.push_back(i);
        vis[i] = 1;
      }
    }
    cout << ans.size() << endl;
    for (int x : ans) cout << x << " ";
    cout << endl;
  }
}
