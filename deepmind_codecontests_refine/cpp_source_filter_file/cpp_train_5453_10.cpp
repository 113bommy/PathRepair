#include <bits/stdc++.h>
using namespace std;
int fi[100002], ne[200002], to[200002], tot;
int dep[100002];
void add(int x, int y) {
  ne[++tot] = fi[x];
  fi[x] = tot;
  to[tot] = y;
}
void dfs(int p, int fa) {
  for (int i = fi[p]; i; i = ne[i])
    if (to[i] != fa) {
      dep[to[i]] = dep[p] + 1;
      dfs(to[i], p);
    }
}
int main() {
  int n, x, y;
  long double ans = 0.0L;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) scanf("%d%d", &x, &y), add(x, y), add(y, x);
  dep[1] = 1;
  dfs(1, -1);
  for (int i = 1; i <= n; i++) ans += 1.0L / dep[i];
  printf("%.8Lf\n", ans);
  return 0;
}
