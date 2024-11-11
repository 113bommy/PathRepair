#include <bits/stdc++.h>
using namespace std;
int n, q, tot, lastans;
const int N = 100005;
int head[N], to[N << 1], nt[N << 1], len[N << 1];
void add(int f, int t, int d) {
  to[++tot] = t;
  len[tot] = d;
  nt[tot] = head[f];
  head[f] = tot;
}
struct SHU {
  int c, root, pos;
  int fa[N][17], dep[N], top[N], maxdep[N], dis[N], son[N], s[N], ans[N],
      col[N], LEN[N];
  vector<int> v[N];
  void dfs0(int x, int f, int opt) {
    if (opt) {
      fa[x][0] = f;
      dep[x] = dep[f] + 1;
      for (int i = 1; fa[x][i - 1]; ++i) fa[x][i] = fa[fa[x][i - 1]][i - 1];
    }
    maxdep[x] = dis[x];
    if (!opt && dis[pos] < dis[x]) pos = x;
    for (int i = head[x]; i; i = nt[i])
      if (to[i] != f) {
        dis[to[i]] = dis[x] + len[i];
        dfs0(to[i], x, opt);
        maxdep[x] = max(maxdep[x], maxdep[to[i]]);
        if (opt && maxdep[son[x]] < maxdep[to[i]]) son[x] = to[i];
      }
  }
  void dfs1(int x, int t) {
    top[x] = t;
    v[t].push_back(x);
    if (son[x]) dfs1(son[x], t);
    for (int i = head[x]; i; i = nt[i])
      if (to[i] != fa[x][0] && to[i] != son[x])
        dfs1(to[i], to[i]), LEN[to[i]] = maxdep[to[i]] - dis[x];
  }
  int YYCH(int x) {
    pos = 0;
    dis[x] = 0;
    dfs0(x, 0, 0);
    root = pos;
    dis[root] = 0;
    dfs0(root, 0, 1);
    dfs1(root, root);
    LEN[root] = maxdep[x];
    for (int i = 1; i <= n; ++i)
      if (top[i] == i) s[++c] = i;
    std::sort(s + 1, s + 1 + c, [&](int a, int b) { return LEN[a] > LEN[b]; });
    for (int i = 1; i <= c; ++i) {
      ans[i] = ans[i - 1] + LEN[s[i]];
      for (int j = s[i]; j; j = son[j]) col[j] = i;
    }
    return root;
  }
  int suan(int x, int y, int *a) {
    int now = x;
    for (int i = 16; i >= 0; --i)
      if (col[fa[now][i]] > y) now = fa[now][i];
    now = fa[now][0];
    return ans[y] + maxdep[x] - a[now];
  }
  int ask(int x, int y) {
    y = 2 * y - 1;
    if (c <= y) return ans[c];
    if (col[x] <= y) return ans[y];
    return max(suan(x, y - 1, dis), suan(x, y, maxdep));
  }
} T1, T2;
int main() {
  cin >> n >> q;
  for (int i = 1, x, y, z; i < n; ++i)
    scanf("%d%d%d", &x, &y, &z), add(x, y, z), add(y, x, z);
  T2.YYCH(T1.YYCH(1));
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    x = (x + lastans - 1) % n + 1;
    y = (y + lastans - 1) % n + 1;
    printf("%d\n", lastans = max(T1.ask(x, y), T2.ask(x, y)));
  }
  return 0;
}
