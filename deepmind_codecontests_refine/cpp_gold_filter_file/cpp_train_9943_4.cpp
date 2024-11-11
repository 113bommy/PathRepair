#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
bool vis[maxn];
int father[maxn], siz[maxn], son[maxn], color[maxn], n, tot, pre[maxn],
    last[maxn], other[maxn], x, y, cnt[maxn], num;
long long ans[maxn], temp;
void add(int x, int y) {
  pre[++tot] = last[x];
  last[x] = tot;
  other[tot] = y;
}
void dfs1(int x, int fa) {
  int p = last[x];
  siz[x] = 1;
  father[x] = fa;
  while (p) {
    if (other[p] != fa) {
      dfs1(other[p], x);
      siz[x] += siz[other[p]];
      if (siz[son[x]] < siz[other[p]]) son[x] = other[p];
    }
    p = pre[p];
  }
}
void calc(int x, int opt) {
  cnt[color[x]] += opt;
  if (opt > 0) {
    if (cnt[color[x]] == num) temp += color[x];
    if (cnt[color[x]] > num) {
      num = cnt[color[x]];
      temp = color[x];
    }
  }
  int p = last[x];
  while (p) {
    if (!vis[other[p]] && other[p] != father[x]) calc(other[p], opt);
    p = pre[p];
  }
}
void dfs2(int x, int isson) {
  int p = last[x];
  while (p) {
    if (other[p] != father[x] && other[p] != son[x]) dfs2(other[p], 0);
    p = pre[p];
  }
  if (son[x]) {
    dfs2(son[x], 1);
    vis[son[x]] = true;
  }
  calc(x, 1);
  ans[x] = temp;
  if (son[x]) vis[son[x]] = false;
  if (!isson) {
    calc(x, -1);
    num = 0;
    temp = 0;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &color[i]);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
  }
  dfs1(1, 0);
  dfs2(1, 0);
  for (int i = 1; i < n; ++i) printf("%lld ", ans[i]);
  printf("%lld\n", ans[n]);
  return 0;
}
