#include <bits/stdc++.h>
using namespace std;
const int N = 2000005;
int tot, ne[N], fi[N], zz[N], sl[N], dis[N], S, T, n, m, x[N], y[N], flag[N],
    w[N], cur[N], k, c, d;
queue<int> Q;
void jb(int x, int y, int z, int v) {
  ne[++tot] = fi[x];
  fi[x] = tot;
  zz[tot] = y;
  sl[tot] = z;
  w[tot] = v;
  ne[++tot] = fi[y];
  fi[y] = tot;
  zz[tot] = x;
  sl[tot] = 0;
  w[tot] = -v;
}
int bfs() {
  Q.push(S);
  memset(dis, 0x3f3f3f3f, sizeof dis);
  dis[S] = 0;
  while (!Q.empty()) {
    int now = Q.front();
    Q.pop();
    flag[now] = 0;
    for (int i = fi[now]; i; i = ne[i])
      if (sl[i] && dis[zz[i]] > dis[now] + w[i]) {
        dis[zz[i]] = dis[now] + w[i];
        if (!flag[zz[i]]) {
          flag[zz[i]] = 1;
          Q.push(zz[i]);
        }
      }
  }
  return dis[T] <= 1e9;
}
int dfs(int x, int y) {
  int s = 0, b;
  flag[x] = 1;
  if (x == T) return y;
  for (int &i = cur[x]; i; i = ne[i])
    if (!flag[zz[i]] && sl[i] && dis[zz[i]] == dis[x] + w[i] &&
        (b = min(y, dfs(zz[i], min(y, sl[i]))))) {
      sl[i] -= b;
      sl[i ^ 1] += b;
      s += b;
      y -= b;
      if (!y) return s;
    }
  return s;
}
int gao() {
  int ans = 0;
  while (bfs()) {
    for (int i = S; i <= n + 1 + n * (n + k); i++) cur[i] = fi[i];
    ans += dfs(S, 1e9) * dis[T];
    memset(flag, 0, sizeof flag);
  }
  return ans;
}
int main() {
  scanf("%d%d%d%d%d", &n, &m, &k, &c, &d);
  S = 0, T = 1;
  tot = 1;
  for (int i = 1; i <= k; i++) {
    int x;
    scanf("%d", &x);
    jb(S, x + 1, 1, 0);
  }
  for (int i = 1; i <= m; i++) scanf("%d%d", &x[i], &y[i]);
  for (int i = 0; i <= n + k; i++) {
    jb(2 + i * n, T, k, 0);
    if (i == n + k) break;
    for (int j = 1; j <= m; j++)
      for (int l = 0; l < k; l++)
        jb(x[j] + 1 + i * n, y[j] + 1 + i * n + n, 1, (l * 2 + 1) * d + c),
            jb(y[j] + 1 + i * n, n + x[j] + 1 + i * n, 1, (l * 2 + 1) * d + c);
    for (int j = 1; j <= n; j++) jb(j + 1 + i * n, j + 1 + i * n + n, k, c);
  }
  printf("%d\n", gao());
}
