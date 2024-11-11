#include <bits/stdc++.h>
using namespace std;
int f[105][45], head[105], la[45];
int n, k, i, j, ans, u, v, cnt;
struct ff {
  int to, nxt;
} e[2 * 105];
void add(int u, int v) {
  e[++cnt] = (ff){v, head[u]};
  head[u] = cnt;
}
void dfs(int now, int fa) {
  if (e[head[now]].nxt == 0 && fa) {
    f[now][0] = f[now][k + 1] = 1;
    return;
  }
  bool flag = 1;
  for (int i = head[now]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa) continue;
    dfs(v, now);
    if (flag) {
      for (int j = 0; j <= 2 * k; j++) f[now][j + 1] = f[v][j];
      flag = 0;
    } else {
      for (int j = 0; j <= 2 * k + 1; j++) la[j] = f[now][j], f[now][j] = 0;
      for (int j = 0; j <= 2 * k; j++)
        for (int h = 1; h <= 2 * k + 1; h++)
          if (j + h <= 2 * k) {
            int Min = min(j + 1, h);
            f[now][Min] =
                (f[now][Min] + 1ll * la[h] * f[v][j] % 1000000007) % 1000000007;
          } else {
            int Max = max(j + 1, h);
            f[now][Max] =
                (f[now][Max] + 1ll * la[h] * f[v][j] % 1000000007) % 1000000007;
          }
    }
  }
  for (int i = 1; i <= 2 * k + 1; i++)
    f[now][0] = (f[now][0] + f[now][i]) % 1000000007;
}
int main() {
  scanf("%d%d", &n, &k);
  for (i = 1; i < n; i++) {
    scanf("%d%d", &u, &v);
    add(u, v), add(v, u);
  }
  dfs(1, 0);
  for (i = 0; i <= k; i++) ans = (ans + f[1][i]) % 1000000007;
  if (ans == 0) ans = 1;
  printf("%d\n", ans);
  return 0;
}
