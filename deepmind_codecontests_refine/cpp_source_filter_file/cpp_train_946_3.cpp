#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
const double pi = acos(-1.0);
struct node {
  int to, nxt;
} sq[200200];
int n, all = 0, head[100100], fa[100100], q;
double ans = 0.0, sum[100100], p[100100];
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while ((ch < '0') || (ch > '9')) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ((ch >= '0') && (ch <= '9')) {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * f;
}
void add(int u, int v) {
  all++;
  sq[all].to = v;
  sq[all].nxt = head[u];
  head[u] = all;
}
void dfs(int u, int fu) {
  ans += p[fu] * (1 - p[u]);
  fa[u] = fu;
  int i;
  for (i = head[u]; i; i = sq[i].nxt) {
    int v = sq[i].to;
    if (v == fu) continue;
    sum[u] += (1 - p[v]);
    dfs(v, u);
  }
}
int main() {
  n = read();
  for (register int i = 1; i <= n; i++) scanf("%lf", &p[i]);
  p[0] = 1.0;
  for (register int i = 1; i <= n - 1; i++) {
    int u = read() + 1, v = read() + 1;
    add(u, v);
    add(v, u);
  }
  dfs(1, 0);
  q = read();
  while (q--) {
    int u = read() + 1;
    double nowp;
    scanf("%lf", &nowp);
    ans -= (p[fa[u]] * (1 - p[u]) + p[u] * sum[u]);
    ans += (p[fa[u]] * (1 - nowp) + nowp * sum[u]);
    sum[fa[u]] += (nowp - p[u]);
    p[u] = nowp;
    printf("%.6lf\n", ans);
  }
  return 0;
}
