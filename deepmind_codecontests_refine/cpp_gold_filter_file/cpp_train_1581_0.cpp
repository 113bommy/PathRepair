#include <bits/stdc++.h>
using namespace std;
const int N = (int)5e5 + 7;
int n, m;
int Rt = 1, ch[N][26], trie_cnt = 1;
int pos[N];
int ans[N];
char s[N];
vector<pair<int, int>> V[N], Q[N];
vector<int> G[N];
struct Bit {
  int a[N];
  inline void modify(int x, int v) {
    for (int i = x; i < N; i += i & -i) {
      a[i] += v;
    }
  }
  inline int sum(int x) {
    int ans = 0;
    for (int i = x; i; i -= i & -i) {
      ans += a[i];
    }
    return ans;
  }
} bit;
inline int ID(char c) { return c - 'a'; }
int in[N], ot[N], dfs_clock;
void dfs(int u) {
  in[u] = ++dfs_clock;
  for (int i = 0; i < 26; i++) {
    if (!ch[u][i]) continue;
    dfs(ch[u][i]);
  }
  ot[u] = dfs_clock;
}
struct Ac {
  int ch[N][26], f[N], tot, sz, subVal;
  inline int newNode() {
    tot++;
    f[tot] = 0;
    memset(ch[tot], 0, sizeof(ch[tot]));
    return tot;
  }
  void init(int _sz, int _subVal) {
    sz = _sz;
    subVal = _subVal;
    tot = -1;
    newNode();
  }
  inline int idx(int c) { return c - subVal; }
  int addStr(char *s) {
    int u = 0;
    for (int i = 0; s[i]; i++) {
      int c = idx(s[i]);
      if (!ch[u][c]) ch[u][c] = newNode();
      u = ch[u][c];
    }
    return u;
  }
  void build() {
    queue<int> que;
    for (int c = 0; c < sz; c++) {
      int v = ch[0][c];
      if (!v)
        ch[0][c] = 0;
      else
        f[v] = 0, que.push(v);
    }
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      for (int c = 0; c < sz; c++) {
        int v = ch[u][c];
        if (!v)
          ch[u][c] = ch[f[u]][c];
        else
          f[v] = ch[f[u]][c], que.push(v);
      }
    }
  }
  void getGraph() {
    for (int i = 1; i <= tot; i++) {
      G[f[i]].push_back(i);
    }
  }
} ac;
void go(int u, int cur) {
  V[cur].push_back(make_pair(in[u], ot[u]));
  for (int i = 0; i < 26; i++) {
    if (!ch[u][i]) continue;
    go(ch[u][i], ac.ch[cur][i]);
  }
}
int son[N], sz[N];
void gao(int u) {
  son[u] = -1;
  sz[u] = 1;
  for (auto &v : G[u]) {
    gao(v);
    sz[u] += sz[v];
    if (son[u] == -1 || sz[v] > sz[son[u]]) {
      son[u] = v;
    }
  }
}
void flip(int u, int op) {
  for (auto &t : V[u]) {
    bit.modify(t.first, op);
    bit.modify(t.second + 1, -op);
  }
}
void modify(int u, int op) {
  flip(u, op);
  for (auto &v : G[u]) {
    modify(v, op);
  }
}
void solve(int u, bool keep) {
  for (auto &v : G[u]) {
    if (v == son[u]) continue;
    solve(v, false);
  }
  if (son[u]) solve(son[u], true);
  for (auto &v : G[u]) {
    if (v == son[u]) continue;
    modify(v, 1);
  }
  flip(u, 1);
  for (auto &q : Q[u]) {
    ans[q.second] = bit.sum(q.first);
  }
  if (!keep) {
    modify(u, -1);
  }
}
int main() {
  ac.init(26, 'a');
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      char c[4];
      scanf("%s", c);
      if (!ch[Rt][ID(*c)]) ch[Rt][ID(*c)] = ++trie_cnt;
      pos[i] = ch[Rt][ID(*c)];
    } else {
      int j;
      char c[4];
      scanf("%d%s", &j, c);
      int cur = pos[j];
      if (!ch[cur][ID(*c)]) ch[cur][ID(*c)] = ++trie_cnt;
      pos[i] = ch[cur][ID(*c)];
    }
  }
  dfs(Rt);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int x;
    scanf("%d", &x);
    scanf("%s", s);
    int p = ac.addStr(s);
    Q[p].push_back(make_pair(in[pos[x]], i));
  }
  ac.build();
  go(Rt, 0);
  ac.getGraph();
  gao(0);
  solve(0, false);
  for (int i = 1; i <= m; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
