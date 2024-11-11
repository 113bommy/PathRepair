#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3fffffff;
const long long mod = 1000000007;
const int maxn = 5000 + 5;
int head[maxn];
struct edge {
  int from, to, next;
} e[maxn * 2];
int tol = 0;
void add(int u, int v) {
  e[++tol].to = v, e[tol].next = head[u], head[u] = tol;
}
int deg[maxn];
int d[maxn][maxn][2];
int dfs(int u, int f) {
  int tot = 0, flag = 1;
  d[u][0][0] = 0;
  d[u][0][1] = 0;
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].to;
    if (v == f) continue;
    flag = 0;
    int now = dfs(v, u);
    tot += now;
    for (int i = tot; i >= 0; i--) {
      int mx[2] = {inf, inf};
      for (int j = 0; j <= min(now, i); j++) {
        mx[0] = min(mx[0], min(d[u][i - j][0] + d[v][j][0],
                               d[u][i - j][0] + d[v][j][1] + 1));
        mx[1] = min(mx[1], min(d[u][i - j][1] + d[v][j][0] + 1,
                               d[u][i - j][1] + d[v][j][1]));
      }
      d[u][i][0] = mx[0], d[u][i][1] = mx[1];
    }
  }
  if (flag) {
    d[u][0][0] = d[u][1][1] = 0;
    d[u][0][1] = inf;
    return 1;
  } else
    return tot;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
    deg[a]++, deg[b]++;
  }
  int root = -1;
  for (int i = 1; i < n + 1; i++)
    if (deg[i] > 1) root = i;
  for (int i = 0; i < maxn; i++)
    for (int j = 0; j < maxn; j++)
      for (int k = 0; k < 2; k++) d[i][j][k] = inf;
  int sum = dfs(root, -1);
  printf("%d\n", min(d[root][sum / 2][0], d[root][sum / 2][1]));
  return 0;
}
