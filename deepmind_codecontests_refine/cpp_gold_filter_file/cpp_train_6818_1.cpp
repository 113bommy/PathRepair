#include <bits/stdc++.h>
using namespace std;
const int N = 100005, INF = INT_MAX >> 1;
int n, m, a[N], f[N], b[N], l[N], p[N], g[N], ans[N];
bool vis[N];
inline void get(int i, int k, int &x) {
  int pos = lower_bound(b + 1, b + m + 1, k) - b - 1;
  vis[pos] = 1;
  x = ans[i] = b[pos];
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], f[i] = INF;
  a[++n] = INF;
  f[n] = INF;
  cin >> m;
  for (int i = 1; i <= m; i++) cin >> b[i];
  sort(b + 1, b + m + 1);
  for (int i = 1; i <= n; i++)
    if (a[i] != -1) {
      int j = lower_bound(f + 1, f + n + 1, a[i]) - f - 1;
      l[i] = j + 1;
      p[i] = g[j];
      f[j + 1] = a[i];
      g[j + 1] = i;
    } else
      for (int j = n, k = m; k > 0; --k) {
        while (f[j] >= b[k]) --j;
        f[j + 1] = b[k];
        g[j + 1] = i;
      }
  int i = l[n], j = n, x = a[n];
  while (i--)
    if (a[j] != -1) {
      if (a[p[j]] == -1)
        get(p[j], a[j], x);
      else
        x = a[p[j]];
      j = p[j];
    } else {
      bool ok = 0;
      for (int k = j - 1; k > 0; --k)
        if (a[k] != -1 && l[k] == i && a[k] < x) {
          x = a[j = k];
          ok = 1;
          break;
        }
      if (ok) continue;
      for (int k = j - 1; k > 0; --k)
        if (a[k] == -1) {
          get(k, x, x), j = k;
          break;
        }
    }
  for (int i = 1, j = 1; i <= n; i++)
    if (a[i] == -1) {
      if (ans[i]) continue;
      while (vis[j]) ++j;
      vis[j] = 1;
      ans[i] = b[j];
    } else
      ans[i] = a[i];
  for (int i = 1; i < n; i++) printf("%d ", ans[i]);
  return 0;
}
