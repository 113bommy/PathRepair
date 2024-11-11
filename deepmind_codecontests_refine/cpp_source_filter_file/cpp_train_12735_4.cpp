#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
inline void remax(T1 &A, T2 B) {
  if (A < B) A = B;
}
template <class T1, class T2>
inline void remin(T1 &A, T2 B) {
  if (A > B) A = B;
}
string ToString(long long num) {
  string ret;
  bool neg = false;
  if (num < 0) num *= ~0, neg = true;
  do {
    ret += ((num % 10) + '0');
    num /= 10;
  } while (num);
  if (neg) ret += '-';
  reverse(ret.begin(), ret.end());
  return ret;
}
long long ToNumber(string s) {
  long long r = 0, p = 1;
  int e = (s[0] == '-');
  for (int i = (int)s.size() - 1; i >= e; --i) r += (s[i] - '0') * p, p *= 10;
  if (e) r *= ~0;
  return r;
}
long long Gcd(long long a, long long b) {
  while (a %= b ^= a ^= b ^= a)
    ;
  return b;
}
long long Power(long long base, unsigned long long power) {
  long long ret = 1;
  while (power) {
    if (power & 1) ret *= base;
    power >>= 1;
    base *= base;
  }
  return ret;
}
long long PowerMod(long long base, unsigned long long power, long long mod) {
  if (!power) return 1 % mod;
  if (power & 1) return (base * PowerMod(base, power - 1, mod)) % mod;
  return PowerMod((base * base) % mod, power >> 1, mod);
}
int Log(long long num, long long base) {
  int ret = 0;
  while (num) {
    ++ret;
    num /= base;
  }
  return ret;
}
int tree[(2 << 17) - 1];
void update(int ind, int l, int r, int a, int val) {
  if (l > a || r < a) return;
  if (a == l && a == r) {
    tree[ind] = val;
    return;
  }
  int m = l + r >> 1;
  update(ind + ind + 1, l, m, a, val);
  update(ind + ind + 2, m + 1, r, a, val);
  tree[ind] = max(tree[ind + ind + 1], tree[ind + ind + 2]);
}
int query(int ind, int l, int r, int a, int b) {
  if (l > b || r < a) return 0;
  if (l >= a && r <= b) return tree[ind];
  int m = l + r >> 1;
  return max(query(ind + ind + 1, l, m, a, b),
             query(ind + ind + 2, m + 1, r, a, b));
}
int sparse[100000][18];
int depth[100000];
int n;
void build() {
  for (int i = 1; i < 18; ++i)
    for (int j = 0; j < n; ++j)
      if (~sparse[j][i - 1])
        sparse[j][i] = sparse[sparse[j][i - 1]][i - 1];
      else
        sparse[j][i] = ~0;
}
int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  if (depth[u] > depth[v])
    for (int i = 17; ~i; --i)
      if (depth[u] - (1 << i) >= depth[v]) u = sparse[u][i];
  if (u != v) {
    for (int i = 17; ~i; --i)
      if (sparse[u][i] != sparse[v][i]) {
        u = sparse[u][i];
        v = sparse[v][i];
      }
    u = sparse[u][0];
  }
  return u;
}
vector<int> adj[100000];
int sz[100000];
int chain[100000];
int head[100000];
int allPosition[100000];
int chainInd, pos;
void hld(int u = 0, int par = ~0) {
  int mx = 0, ind;
  chain[u] = chainInd;
  if (head[chainInd] == ~0) head[chainInd] = u;
  allPosition[u] = pos++;
  for (int &v : adj[u])
    if (v != par && sz[v] > mx) {
      mx = sz[v];
      ind = v;
    }
  if (!mx) return;
  hld(ind, u);
  for (int &v : adj[u])
    if (v != par && v != ind) {
      ++chainInd;
      hld(v, u);
    }
}
pair<int, int> edges[99999];
void update(int ind, int val) {
  int u = edges[ind].first;
  int v = edges[ind].second;
  if (depth[u] < depth[v]) swap(u, v);
  update(0, 0, n - 1, allPosition[u], val);
}
int queryUp(int u, int v) {
  int uChain, vChain = chain[v], ret = 0;
  while (true) {
    uChain = chain[u];
    if (uChain == vChain)
      return max(ret, query(0, 0, n - 1, allPosition[v], allPosition[u]));
    remax(ret, query(0, 0, n - 1, allPosition[head[uChain]], allPosition[u]));
    u = head[uChain];
    u = sparse[u][0];
  }
  return ret;
}
int query(int u, int v) {
  int l = lca(u, v);
  return max(queryUp(u, l), queryUp(v, l));
}
void dfs(int u = 0, int par = ~0, int d = 0) {
  sparse[u][0] = par;
  sz[u] = 1;
  depth[u] = d;
  for (int &v : adj[u])
    if (v != par) {
      dfs(v, u, d + 1);
      sz[u] += sz[v];
    }
}
inline void run() {
  int m;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &edges[i - 1].first, &edges[i - 1].second);
    adj[--edges[i - 1].first].emplace_back(--edges[i - 1].second);
    adj[edges[i - 1].second].emplace_back(edges[i - 1].first);
  }
  dfs();
  memset(head, ~0, sizeof head);
  hld();
  build();
  scanf("%d", &m);
  while (m--) {
    int a;
    scanf("%d", &a);
    if (a != 3) {
      int b;
      scanf("%d", &b);
      update(--b, --a);
    } else {
      int u, v;
      scanf("%d%d", &u, &v);
      if (query(--u, --v))
        puts("-1");
      else
        printf("%d\n", depth[u] + depth[v] - depth[lca(u, v)] * 2);
    }
  }
  memset(tree, 0, sizeof tree);
  for (int i = 0; i < n;) adj[i++].clear();
  chainInd = pos = 0;
}
int main() {
  run();
  return 0;
}
