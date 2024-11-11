#include <bits/stdc++.h>
using namespace std;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= 1000000007;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
  }
  return res;
}
template <typename T>
inline bool chkmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct Hash {
  friend struct std::hash<Hash>;
  const static long long M1 = 1e9 + 7;
  const static long long M2 = 1e9 + 9;
  const static long long P1 = 233;
  const static long long P2 = 823;
  static vector<long long> p1, p2, ip1, ip2;
  long long hv1, hv2;
  int size;
  Hash(long long hv1, long long hv2, int size)
      : hv1((hv1 % M1 + M1) % M1), hv2((hv2 % M2 + M2) % M2), size(size) {}
  Hash() : Hash(0, 0, 0) {}
  Hash(int ch) : Hash(ch + 1, ch + 1, 1) {}
  static long long pow(long long a, long long b, long long moder) {
    long long res = 1;
    for (; b; b >>= 1) {
      if (b & 1) res = res * a % moder;
      a = a * a % moder;
    }
    return res;
  }
  static void init(int n) {
    p1.resize(n + 1);
    p2.resize(n + 1);
    ip1.resize(n + 1);
    ip2.resize(n + 1);
    p1[0] = 1, p2[0] = 1;
    for (int i = 1; i <= n; i++)
      p1[i] = p1[i - 1] * P1 % M1, p2[i] = p2[i - 1] * P2 % M2;
    ip1[n] = pow(p1[n], M1 - 2, M1);
    ip2[n] = pow(p2[n], M2 - 2, M2);
    for (int i = n; i; i--) {
      ip1[i - 1] = ip1[i] * P1 % M1;
      ip2[i - 1] = ip2[i] * P2 % M2;
    }
  }
  bool operator==(const Hash &op) const {
    return hv1 == op.hv1 && hv2 == op.hv2;
  }
  Hash operator+(const Hash &op) const {
    return Hash(hv1 * p1[op.size] + op.hv1, hv2 * p2[op.size] + op.hv2,
                size + op.size);
  }
  Hash remove_left(const Hash &op) const {
    return Hash(hv1 - op.hv1 * p1[size - op.size],
                hv2 - op.hv2 * p2[size - op.size], size - op.size);
  }
  Hash remove_right(const Hash &op) const {
    return Hash((hv1 - op.hv1) * ip1[op.size], (hv2 - op.hv2) * ip2[op.size],
                size - op.size);
  }
} hup[50000], hdown[50000];
vector<long long> Hash::ip1, Hash::ip2, Hash::p1, Hash::p2;
namespace std {
template <>
struct hash<Hash> {
  size_t operator()(const Hash &s) const { return s.hv1 ^ s.hv2; }
};
}  // namespace std
vector<pair<int, pair<int, bool>>> g[50000];
map<pair<int, int>, int> e2c;
vector<pair<int, int>> query[50000];
int ans[50000], n, q;
int dep[50000];
int fa[50000][20];
int vis[50000];
void dfs(int u, int f) {
  for (int i = 1; i < 20; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (auto x : g[u]) {
    int v = x.first;
    if (v != f) {
      fa[v][0] = u;
      dep[v] = dep[u] + 1;
      hup[v] = Hash(x.second.first) + hup[u];
      hdown[v] = hdown[u] + Hash(x.second.first);
      dfs(v, u);
    }
  }
}
int go_up(int u, int d) {
  for (int i = 0; i < 20; i++)
    if (d & (1 << i)) u = fa[u][i];
  return u;
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int d = dep[u] - dep[v];
  u = go_up(u, d);
  if (u == v) return u;
  for (int i = 19; i >= 0; i--)
    if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
  return fa[u][0];
}
int dis(int u, int v) { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }
Hash get_hash(int u, int v) {
  int w = lca(u, v);
  return hup[u].remove_right(hup[w]) + hdown[v].remove_left(hdown[w]);
}
int go(int u, int v, int d) {
  int w = lca(u, v);
  int dd = dep[u] - dep[w];
  if (d <= dd)
    return go_up(u, d);
  else
    return go_up(v, dep[v] - dep[w] - (d - dd));
}
int nxt(int u, int v) {
  int w = go(u, v, 1);
  return e2c[make_pair(u, w)];
}
struct Trie {
  struct Node {
    int num = 0, tot = 0, left_tot = 0;
    Hash hash;
    Node *ch[26] = {nullptr};
    Node() {}
  };
  Node *root;
  unordered_map<Hash, Node *> hh;
  Node *add(Node *cur, int u, int fa) {
    if (!cur) cur = new Node();
    cur->num++;
    for (auto x : g[u]) {
      if (x.first == fa || vis[x.first]) continue;
      cur->ch[x.second.first] = add(cur->ch[x.second.first], x.first, u);
    }
    return cur;
  }
  Trie() : root(new Node()) {}
  void add(int u, int fa, int c) { root->ch[c] = add(root->ch[c], u, fa); }
  void dfs(Node *cur, Hash h, int tot) {
    hh[h] = cur;
    cur->left_tot = tot;
    cur->tot = cur->num;
    cur->hash = h;
    tot += cur->num;
    for (int i = 0; i < 26; i++)
      if (cur->ch[i]) {
        dfs(cur->ch[i], h + Hash(i), tot);
        cur->tot += cur->ch[i]->tot;
        tot += cur->ch[i]->tot;
      }
  }
  void init() { dfs(root, Hash(), 0); }
  int count_left(int u, int v) const {
    const int d = dis(u, v);
    int l = 1, r = d;
    int res = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (hh.count(get_hash(u, go(u, v, mid))))
        l = mid + 1, res = mid;
      else
        r = mid - 1;
    }
    int w = go(u, v, res);
    Node *cur = hh.find(get_hash(u, w))->second;
    int ans = cur->left_tot;
    if (res < d) {
      ans += cur->num;
      int ch = nxt(w, v);
      for (int i = 0; i < ch; i++)
        if (cur->ch[i]) ans += cur->ch[i]->tot;
    }
    return ans;
  }
};
int head, tail, que[50000], tot_siz, siz[50000];
int rt, per[50000];
void getrt(int u) {
  head = tail = 0;
  que[tail++] = u;
  rt = u;
  per[u] = 0;
  while (head != tail) {
    u = que[head++];
    for (auto x : g[u]) {
      int v = x.first;
      if (v == per[u] || vis[v]) continue;
      per[v] = u;
      que[tail++] = v;
    }
  }
  tot_siz = tail;
  int rt_cnt = 0x3f3f3f3f;
  while (tail) {
    u = que[--tail];
    siz[u] = 1;
    int cnt = 0;
    for (auto x : g[u]) {
      int v = x.first;
      if (v == per[u] || vis[v]) continue;
      siz[u] += siz[v];
      chkmax(cnt, siz[v]);
    }
    chkmax(cnt, tot_siz - siz[u]);
    if (chkmin(rt_cnt, cnt)) rt = u;
  }
}
int cmp(int a, int b, int c, int d) {
  int dd = dis(a, b);
  int l = 1, r = dd, res = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (get_hash(a, go(a, b, mid)) == get_hash(c, go(c, d, mid)))
      res = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  if (res == dd) return 0;
  return nxt(go(a, b, res), b) < nxt(go(c, d, res), d) ? -1 : 1;
}
void divide(int u) {
  getrt(u);
  vis[rt] = 1;
  Trie tr;
  static Trie sub[50000];
  for (auto x : g[rt]) {
    int v = x.first;
    if (!vis[v]) {
      sub[v] = Trie();
      sub[v].add(x.first, rt, x.second.first);
      sub[v].init();
      tr.add(x.first, rt, x.second.first);
    }
  }
  tr.init();
  for (int i = 0; i < tot_siz; i++) {
    u = que[i];
    for (auto x : query[u]) {
      int v = x.first, id = x.second;
      if (dis(u, v) < dis(u, rt)) {
        int w = go(u, rt, dis(u, v));
        int tmp = cmp(u, w, u, v);
        if (tmp < 0) {
          int xx = go(rt, u, 1);
          ans[id] += tot_siz - sub[xx].root->tot;
        }
      } else {
        int w = go(u, v, dis(u, rt));
        int tmp = cmp(u, rt, u, w);
        if (tmp < 0) {
          ans[id] += tot_siz;
          int xx = go(rt, u, 1);
          ans[id] -= sub[xx].root->tot;
        } else if (tmp == 0) {
          if (w != v && u != rt) ans[id]++;
          ans[id] += tr.count_left(w, v);
          if (u != rt) {
            int xx = go(rt, u, 1);
            ;
            ans[id] -= sub[xx].count_left(w, v);
          }
        }
      }
    }
  }
  for (auto x : g[rt]) {
    if (!vis[x.first]) {
      divide(x.first);
    }
  }
}
int main() {
  Hash::init(50000);
  n = read(), q = read();
  for (int i = 1; i < n; i++) {
    static char s[10];
    int u, v;
    scanf("%d %d %s", &u, &v, s);
    e2c[make_pair(u, v)] = e2c[make_pair(v, u)] = s[0] - 'a';
    g[u].push_back(make_pair(v, make_pair(s[0] - 'a', 1))),
        g[v].push_back(make_pair(u, make_pair(s[0] - 'a', 1)));
  }
  for (int i = 0; i < q; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    query[u].push_back(make_pair(v, i));
  }
  dfs(1, 0);
  divide(1);
  for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
  return 0;
}
