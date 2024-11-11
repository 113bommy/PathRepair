#include <bits/stdc++.h>
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool flag = false;
  while (!isdigit(c)) {
    if (c == '-') flag = true;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
  if (flag) x = -x;
}
using namespace std;
inline int Rand(int mod) { return 1ull * rand() * rand() % mod; }
int n, m;
struct edge {
  int nxt, to;
  edge() {}
  edge(int jzp, int zzz) { nxt = jzp, to = zzz; }
} e[101000 << 1];
int head[101000], ecnt;
inline void addedge(int from, int to) {
  e[++ecnt] = edge(head[from], to);
  head[from] = ecnt;
}
int vtot, dep[101000], fa[101000];
bool vis[101000], instk[101000];
bool dfs_check(int cur) {
  vis[cur] = true;
  instk[cur] = true;
  ++vtot;
  for (int i = head[cur]; i; i = e[i].nxt) {
    int to = e[i].to;
    if (instk[to]) continue;
    if (vis[to]) return instk[cur] = false;
    dep[to] = dep[cur] + 1;
    fa[to] = cur;
    if (!dfs_check(to)) return instk[cur] = false;
  }
  instk[cur] = false;
  return true;
}
inline bool check(int rt) {
  dep[rt] = fa[rt] = vtot = 0;
  for (int i = 1; i <= n; ++i) vis[i] = false;
  if (!dfs_check(rt)) return false;
  return vtot == n;
}
int fath[101000];
int find(int cur) {
  return fath[cur] == cur ? cur : fath[cur] = find(fath[cur]);
}
int anc[101000];
void Update(int cur, int jzp) {
  cur = find(cur);
  while (dep[cur] > dep[jzp]) {
    if (anc[cur])
      fath[cur] = fa[cur], cur = find(fa[cur]);
    else
      anc[cur] = jzp, cur = find(fa[cur]);
  }
}
void dfs_fan(int cur) {
  instk[cur] = true;
  for (int i = head[cur]; i; i = e[i].nxt) {
    int to = e[i].to;
    if (dep[to] > dep[cur] + 1) continue;
    if (instk[to])
      Update(cur, to);
    else
      dfs_fan(to);
  }
  instk[cur] = false;
}
bool isans[101000];
int ans[101000], atot;
void dfs_ans(int cur) {
  if (fath[cur] == cur && anc[cur] && isans[anc[cur]])
    isans[cur] = true, ans[++atot] = cur;
  for (int i = head[cur]; i; i = e[i].nxt) {
    int to = e[i].to;
    if (dep[to] != dep[cur] + 1) continue;
    dfs_ans(to);
  }
}
inline void work() {
  read(n), read(m);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    read(u), read(v);
    addedge(u, v);
  }
  int rt = Rand(n) + 1, ct = 0;
  while (!check(rt) && ct <= 90) ++ct, rt = Rand(n) + 1;
  if (check(rt)) {
    for (int i = 1; i <= n; ++i) fath[i] = i;
    dfs_fan(rt);
    isans[rt] = true;
    ans[atot = 1] = rt;
    dfs_ans(rt);
    sort(ans + 1, ans + 1 + atot);
    if (atot * 5 <= n)
      puts("-1");
    else
      for (int i = 1; i <= atot; ++i)
        printf("%d%c", ans[i], i == atot ? '\n' : ' ');
  } else {
    puts("-1");
  }
}
inline void clear() {
  for (int i = 1; i <= n; ++i) {
    isans[i] = vis[i] = instk[i] = false;
    anc[i] = head[i] = dep[i] = fa[i] = 0;
  }
  ecnt = 0;
}
int main() {
  srand((long long)new char);
  int _;
  read(_);
  while (_--) work(), clear();
  return 0;
}
