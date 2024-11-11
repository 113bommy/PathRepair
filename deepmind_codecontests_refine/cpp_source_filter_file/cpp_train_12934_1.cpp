#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' or '9' < c) f = (c == '-' ? -1 : f), c = getchar();
  while ('0' <= c and c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
int t, n, p[220000], c[220000], flag[220000], sam[220000], a[220000], tot;
void dfs(int u) {
  if (flag[u]) return;
  flag[u] = 1;
  a[++tot] = u;
  dfs(p[u]);
}
inline bool check(int dep) {
  if (dep == tot) return true;
  for (int i = 1; i <= tot; ++i) sam[i] = i;
  for (int i = 1; i <= tot; ++i) {
    int nx = i + dep;
    if (nx > tot) nx = nx % tot;
    if (c[a[i]] == c[a[nx]]) {
      if (sam[nx] == sam[i]) return true;
      sam[nx] = sam[i];
    }
  }
  return false;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &p[i]), flag[i] = 0;
    for (int i = 1; i <= n; ++i) scanf("%d", &c[i]);
    int ans = 1e9;
    for (int i = 1; i <= n; ++i) {
      if (flag[i]) continue;
      tot = 0;
      dfs(i);
      int jk = sqrt(tot);
      ans = min(ans, tot);
      for (int i = 1; i <= jk; ++i) {
        if (tot % i == 0) {
          if (check(i)) {
            ans = min(ans, i);
            break;
          } else {
            if (check(tot / i)) ans = min(ans, tot);
          }
        }
      }
      if (ans == 1) break;
    }
    printf("%d\n", ans);
  }
  return 0;
}
