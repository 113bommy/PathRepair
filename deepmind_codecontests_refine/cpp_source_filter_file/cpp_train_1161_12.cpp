#include <bits/stdc++.h>
using namespace std;
const int mxn = 262144, M = 60, md = 998244353;
int rd() {
  int x = 0, flg = 1;
  char c = getchar();
  for (; (c < 48 || c > 57) && c != '-'; c = getchar())
    ;
  if (c == '-') flg = -1, c = getchar();
  for (; c > 47 && c < 58; x = x * 10 + c - 48, c = getchar())
    ;
  return x * flg;
}
int n, m, ans = 1, head[mxn], fct[mxn];
struct ed {
  int to, nxt;
} edge[mxn << 1];
void addedge(int u, int v) {
  edge[++m] = (ed){v, head[u]}, head[u] = m;
  edge[++m] = (ed){u, head[v]}, head[v] = m;
}
void dfs(int u, int fa) {
  int cnt = 0;
  for (int i = head[u], v; i; i = edge[i].nxt)
    if ((v = edge[i].to) != fa) dfs(v, u), ++cnt;
  if (u > 1)
    ans = 1ll * ans * fct[cnt + 1] % md;
  else
    ans = 1ll * ans * n * fct[cnt] % md;
}
int main() {
  n = rd(), fct[0] = 1;
  for (int i = 1; i <= n; ++i) fct[i] = 1ll * fct[i - 1] * i % md;
  for (int i = 1, x, y; i < n; ++i) x = rd(), y = rd(), addedge(x, y);
  dfs(1, 0);
  printf("%d\n", ans);
  return 0;
}
