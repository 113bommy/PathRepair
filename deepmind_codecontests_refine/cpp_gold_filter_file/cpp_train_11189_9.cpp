#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
struct edge {
  int to, next, v;
} e[N * 2];
int head[N], tot;
int n, q;
int d[N], deg[N];
int las, len, *aim[N];
bool cmp(int *a, int *b) { return *a > *b; }
void add(int x, int y, int v) {
  e[++tot] = (edge){y, head[x], v};
  head[x] = tot;
}
struct tree {
  int S, d[N];
  int top[N], bot[N];
  int f[N][20], hei[N];
  int v[N][20], sum, ans[N];
  int de[N], dp[N], fav[N];
  void getfa(int x, int fa) {
    f[x][0] = fa;
    for (int i = head[x]; i; i = e[i].next)
      if (e[i].to != fa) {
        getfa(e[i].to, x);
        fav[e[i].to] = e[i].v;
      }
  }
  void build() {
    getfa(S, 0);
    len = 0;
    for (int i = 1; i <= n; i++)
      if (deg[i] == 1 && i != S) aim[++len] = d + i;
    sort(aim + 1, aim + len + 1, cmp);
    for (int i = 1; i <= len; i++) {
      int j = aim[i] - d, k = j;
      for (; !bot[k] && k;) {
        bot[k] = j;
        hei[j] += fav[k];
        k = f[k][0];
      }
    }
    len = 0;
    for (int i = 1; i <= n; i++)
      if (deg[i] == 1 && i != S) aim[++len] = hei + i, ++sum;
    sort(aim + 1, aim + len + 1, cmp);
    for (int i = 1; i <= len; i++) {
      int j = aim[i] - hei, k = j;
      for (; !*v[k] && k; *v[k] = i, k = f[k][0])
        ;
      ans[i] = ans[i - 1] + hei[j];
      de[i] = hei[j];
      dp[i] = bot[j];
    }
    for (int j = 1; j <= 17; j++)
      for (int i = 1; i <= n; i++) {
        f[i][j] = f[f[i][j - 1]][j - 1];
        v[i][j] = min(v[i][j - 1], v[f[i][j - 1]][j - 1]);
      }
  }
  int work(int x, int y) {
    if (2 * y - 1 > sum) return ans[len];
    if (*v[x] <= 2 * y - 1) return ans[2 * y - 1];
    int tot = ans[2 * y - 1] + d[bot[x]];
    for (int i = 17; i >= 0; i--)
      if (v[x][i] > 2 * y - 1) x = f[x][i];
    tot -=
        d[x] + min(d[bot[x]] - d[x],
                   dp[2 * y - 1] != bot[x] ? de[2 * y - 1] : d[bot[x]] - d[x]);
    return tot;
  }
} A, B;
void getdep(int x, int fa, int dep, int *d) {
  d[x] = dep;
  for (int i = head[x]; i; i = e[i].next)
    if (e[i].to != fa) getdep(e[i].to, x, dep + e[i].v, d);
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i < n; i++) {
    int x, y, v;
    scanf("%d%d%d", &x, &y, &v);
    add(x, y, v);
    add(y, x, v);
    deg[x]++;
    deg[y]++;
  }
  getdep(1, 0, 0, d);
  A.S = max_element(d + 1, d + n + 1) - d;
  getdep(A.S, 0, 0, A.d);
  B.S = max_element(A.d + 1, A.d + n + 1) - A.d;
  getdep(B.S, 0, 0, B.d);
  A.build();
  B.build();
  int ans = 0;
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    x = (x + ans + n - 1) % n + 1;
    y = (y + ans + n - 1) % n + 1;
    ans = max(A.work(x, y), B.work(x, y));
    printf("%d\n", ans);
  }
}
