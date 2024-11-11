#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
struct edge {
  int to, nex;
} e[maxn << 1];
int head[maxn], cnt = 1;
void add(int a, int b) {
  e[++cnt] = (edge){b, head[a]};
  head[a] = cnt;
}
int vis[maxn], t[maxn << 2];
int dep[maxn], fa[maxn];
void dfs(int u) {
  dep[u] = dep[fa[u]] + 1;
  vis[u] = 1;
  for (int i = head[u]; i; i = e[i].nex) {
    int v = e[i].to;
    if (!vis[v]) {
      t[i] = t[i ^ 1] = 1;
      fa[v] = u;
      dfs(v);
    }
  }
}
int path[maxn], tot;
void wr(int a, int b) {
  path[++tot] = a;
  while (a != b) {
    a = fa[a];
    path[++tot] = a;
  }
  return;
}
void pr() {
  cout << tot << ' ';
  for (int i = 1; i <= tot; ++i) cout << path[i] << ' ';
  cout << '\n';
  tot = 0;
}
int lca(int x, int y) {
  while (dep[x] > dep[y]) x = fa[x];
  while (dep[x] < dep[y]) y = fa[y];
  while (x != y) x = fa[x], y = fa[y];
  return x;
}
void print(int a, int b, int c, int d) {
  cout << "YES\n";
  int x = lca(b, d);
  if (dep[a] > dep[c]) swap(a, c), swap(b, d);
  wr(x, c);
  reverse(path + 1, path + tot + 1);
  pr();
  wr(c, a);
  wr(d, x);
  pr();
  path[++tot] = c, wr(b, x);
  pr();
  exit(0);
}
map<pair<int, int>, pair<int, int> > mp;
void check(int a, int b) {
  if (dep[a] < dep[b]) swap(a, b);
  int d = a;
  while (d != b) {
    int c = fa[d];
    if (mp.count(make_pair(c, d)))
      print(b, a, mp[make_pair(c, d)].first, mp[make_pair(c, d)].second);
    else
      mp[make_pair(c, d)] = make_pair(b, a);
    d = c;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int a, b;
    cin >> a >> b;
    add(a, b), add(b, a);
  }
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) dfs(i);
  for (int u = 1; u <= n; ++u)
    for (int i = head[u]; i; i = e[i].nex)
      if (!t[i]) check(u, e[i].to), t[i] = t[i ^ 1] = 1;
  cout << "NO\n";
  return 0;
}
