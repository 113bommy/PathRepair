#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 10;
vector<vector<int> > G(maxn);
vector<pair<int, int> > tri[maxn], ask[maxn];
int dfs_clock = 0, in[maxn], out[maxn];
char s[maxn];
int bit[maxn];
inline int lowbit(const int x) { return x & (-x); }
void add(int x, int val) {
  while (x <= dfs_clock) bit[x] += val, x += lowbit(x);
}
int getsum(int x) {
  int res = 0;
  while (x) res += bit[x], x -= lowbit(x);
  return res;
}
const int mx = 26;
struct ACM {
  int ch[maxn][mx], f[maxn], val[maxn];
  int rt, sz;
  int newnode() {
    for (int i = 0; i < mx; ++i) ch[sz][i] = -1;
    val[sz] = 0;
    return sz++;
  }
  inline int idx(const char c) { return c - 'a'; }
  void init() { sz = 0, rt = newnode(); }
  int insert(const char *s) {
    int u = rt;
    for (int i = 0; s[i]; ++i) {
      int c = idx(s[i]);
      if (ch[u][c] == -1) ch[u][c] = newnode();
      u = ch[u][c];
    }
    return u;
  }
  void build() {
    queue<int> q;
    f[rt] = rt;
    for (int c = 0; c < mx; ++c) {
      if (~ch[rt][c]) {
        f[ch[rt][c]] = rt, q.push(ch[rt][c]);
      } else {
        ch[rt][c] = rt;
      }
    }
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      G[f[u]].push_back(u);
      for (int c = 0; c < mx; ++c) {
        if (~ch[u][c]) {
          f[ch[u][c]] = ch[f[u]][c], q.push(ch[u][c]);
        } else {
          ch[u][c] = ch[f[u]][c];
        }
      }
    }
  }
  void dfs(int u) {
    in[u] = ++dfs_clock;
    for (auto &v : G[u]) dfs(v);
    out[u] = dfs_clock;
  }
} ac;
int ans[maxn];
void dfs(int u, int cur) {
  add(in[u], 1);
  for (auto &v : ask[cur]) {
    ans[v.second] = getsum(out[v.first]) - getsum(in[v.first] - 1);
  }
  for (auto &v : tri[cur]) {
    dfs(ac.ch[u][v.first], v.second);
  }
  add(out[u], -1);
}
int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 1, op, x; i <= n; ++i) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%s", s);
      x = 0;
    } else {
      scanf("%d%s", &x, s);
    }
    tri[x].emplace_back(s[0] - 'a', i);
  }
  scanf("%d", &m);
  ac.init();
  for (int i = 1, x; i <= m; ++i) {
    scanf("%d%s", &x, s);
    ask[x].emplace_back(ac.insert(s), i);
  }
  ac.build();
  ac.dfs(0);
  dfs(0, 0);
  for (int i = 1; i <= m; ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
