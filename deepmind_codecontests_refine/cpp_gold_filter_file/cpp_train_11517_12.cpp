#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10, maxm = 4e5 + 10;
struct edge {
  int to, next;
  edge() {}
  edge(int to, int next) : to(to), next(next) {}
} e[maxm << 1];
int tot = 1, pre[maxn], n, m, cnt = 0, ans = 0, dep[maxn], fa[maxn];
int F[maxm], M[maxm], E[maxm];
bool vis[maxm << 1], visp[maxn];
int read();
void add(int, int);
void dfs(int, int);
int main() {
  memset(pre, -1, sizeof(pre)), memset(vis, 0, sizeof(vis)),
      memset(visp, 0, sizeof(visp));
  n = read(), m = read();
  for (int i = 1, f, t; i <= m; i++) {
    f = read(), t = read();
    add(f, t), add(t, f);
  }
  for (int i = 1; i <= n; i++)
    if (!visp[i]) dfs(i, 0);
  printf("%d\n", ans);
  for (int i = 1; i <= ans; i++) {
    printf("%d %d %d\n", F[i], M[i], E[i]);
  }
  return 0;
}
void dfs(int s, int from) {
  visp[s] = true;
  for (int i = pre[s]; ~i; i = e[i].next) {
    int ito = e[i].to;
    if (visp[ito]) continue;
    dep[ito] = dep[s] + 1, fa[ito] = s;
    dfs(ito, i);
  }
  bool flag = true;
  for (int i = pre[s]; ~i; i = e[i].next) {
    int ito = e[i].to;
    if (dep[s] < dep[ito] && !vis[i]) {
      if (flag)
        F[++ans] = ito, M[ans] = s;
      else
        E[ans] = ito;
      flag ^= 1, vis[i] = vis[i ^ 1] = true;
    }
  }
  if (!flag) {
    E[ans] = fa[s];
    if (!fa[s]) ans--;
    vis[from] = vis[from ^ 1] = true;
  }
}
void add(int from, int to) {
  e[++tot] = edge(to, pre[from]);
  pre[from] = tot;
}
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0', c = getchar();
  return x * f;
}
