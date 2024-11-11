#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
const int MAX_LOG = 20;
const int mod = 1e9 + 7;
int N, K, k, a, b, c, ret, up[MAX], down[MAX], id[MAX], ord[MAX << 1],
    dep[MAX << 1], rmq[MAX_LOG][MAX];
vector<pair<int, int> > e[MAX];
inline void Add(int &a, int b) {
  a += b;
  while (a >= mod) a -= mod;
}
inline int Mul(int a, int b) { return (long long)a * b % mod; }
inline void dfs(int x, int p, int d) {
  id[x] = k;
  ord[k] = x;
  dep[k++] = d;
  for (__typeof((e[x]).begin()) it = (e[x]).begin(); it != (e[x]).end(); it++)
    if (it->first != p) dfs(it->first, x, d + 1), ord[k] = x, dep[k++] = d;
}
inline int mx(int a, int b) {
  if (dep[a] < dep[b]) return a;
  return b;
}
inline void Init() {
  dfs(1, 1, 0);
  for (register int i = 0; i < k; i++) rmq[0][i] = i;
  for (register int lg = 0; lg < MAX_LOG - 1; lg++)
    for (register int i = 0; i < k; i++)
      rmq[lg + 1][i] = mx(rmq[lg][i], rmq[lg][i + (1 << lg)]);
}
inline int Query(int l, int r) {
  int len = r - l, lg = 31 - __builtin_clz(len);
  return mx(rmq[lg][l], rmq[lg][r - (1 << lg)]);
}
inline int lca(int u, int v) {
  if (id[u] > id[v]) swap(u, v);
  return ord[Query(id[u], id[v] + 1)];
}
inline int q_pow(int t, int p) {
  int ret = 1;
  while (p) {
    if (p & 1) ret = Mul(ret, t);
    t = Mul(t, t);
    p >>= 1;
  }
  return ret;
}
inline void fin_ret(int x, int p) {
  for (__typeof((e[x]).begin()) it = (e[x]).begin(); it != (e[x]).end(); it++)
    if (it->first != p) {
      fin_ret(it->first, x);
      up[x] += up[it->first];
      down[x] += down[it->first];
    }
}
inline void fin_cal(int x, int p) {
  for (__typeof((e[x]).begin()) it = (e[x]).begin(); it != (e[x]).end(); it++)
    if (it->first != p) {
      if (it->second == 1) {
        Add(ret, q_pow(2, up[it->first]));
        Add(ret, mod - 1);
      } else if (it->second == -1) {
        Add(ret, q_pow(2, down[it->first]));
        Add(ret, mod - 1);
      }
      fin_cal(it->first, x);
    }
}
int main() {
  scanf("%d", &N);
  for (register int i = 1; i <= N - 1; i++) {
    scanf("%d %d %d", &a, &b, &c);
    e[a].push_back(make_pair(b, c));
    e[b].push_back(make_pair(a, -c));
  }
  Init();
  a = 1;
  scanf("%d", &K);
  while (K--) {
    scanf("%d", &b);
    if (a == b) continue;
    int m = lca(a, b);
    up[a]++;
    up[m]--;
    down[m]--;
    down[b]++;
    a = b;
  }
  fin_ret(1, 1);
  fin_cal(1, 1);
  printf("%d\n", ret);
  return 0;
}
