#include <bits/stdc++.h>
using namespace std;
int n, m, T;
int l[200010], r[200010], s[200010], t[200010], id[100010];
int f[1010][1010];
int ans[200010];
int x[200010], y[200010];
inline int cmp(int x, int y) { return l[x] > l[y]; }
int main() {
  scanf("%d%d%d", &n, &m, &T);
  for (int i = 1; i <= m; i++) scanf("%d%d", &x[i], &y[i]);
  for (int i = 1; i <= T; i++)
    scanf("%d%d%d%d", &l[i], &r[i], &s[i], &t[i]), id[i] = i;
  sort(id + 1, id + T + 1, cmp);
  memset(f, 63, sizeof(f));
  int last = 1;
  for (int i = m; i; i--) {
    f[x[i]][y[i]] = f[y[i]][x[i]] = i;
    for (int j = 1; j <= n; j++) {
      f[x[i]][j] = min(f[x[i]][j], f[y[i]][j]);
      f[y[i]][j] = min(f[y[i]][j], f[x[i]][j]);
    }
    while (last <= T && l[id[last]] == i) {
      int u = id[last++];
      ans[u] = f[s[u]][t[u]] <= r[u];
    }
  }
  for (int i = 1; i <= T; i++) puts(ans[i] ? "Yes" : "No");
}
