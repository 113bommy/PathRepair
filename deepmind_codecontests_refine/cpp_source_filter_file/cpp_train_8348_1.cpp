#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
const int M = 200000;
const long long P = 1000000007LL;
int l[N + 5], r[N + 5], n;
long long inv[N + 5];
long long ans, sum = 1;
long long fastpow(long long x) {
  long long res = 1, n = P - 2;
  x %= P;
  while (n) {
    if (n & 1) res = res * x % P;
    x = x * x % P;
    n >>= 1;
  }
  return res;
}
int head[N + 5], nxt[M + 5], to[M + 5], tot;
inline void addedge(int u, int v) {
  nxt[++tot] = head[u];
  to[head[u] = tot] = v;
}
int dep[N + 5], hson[N + 5];
int dfs1(int u, int fa) {
  dep[u] = dep[fa] + 1;
  int cnt = 1, _max = 0, _hson = 0;
  for (int e = head[u]; ~e; e = nxt[e]) {
    int v = to[e];
    if (v != fa) {
      int re = dfs1(v, u);
      if (re > _max) {
        _max = re;
        _hson = v;
      }
      cnt += re;
    }
  }
  hson[u] = _hson;
  return cnt;
}
int top[N + 5];
void dfs2(int u, int fa) {
  if (hson[u]) {
    top[hson[u]] = top[u];
    dfs2(hson[u], u);
  }
  for (int e = head[u]; ~e; e = nxt[e]) {
    int v = to[e];
    if (v != fa && v != hson[u]) {
      top[v] = v;
      dfs2(v, u);
    }
  }
}
template <typename T, const int N>
struct Binary_Indexed_Tree {
  int n;
  T C1[N + 5], C2[N + 5];
  void init(int _n) { n = _n; }
  void __add1(int p, T d) {
    while (p <= n) {
      C1[p] = (C1[p] + d) % P;
      p += p & -p;
    }
  }
  void __add2(int p, T d) {
    while (p <= n) {
      C2[p] = (C2[p] + d) % P;
      p += p & -p;
    }
  }
  void add(int L, int R, T d) {
    int p = L;
    __add1(p, d);
    __add2(p, p * d % P);
    p = R + 1;
    __add1(p, -d);
    __add2(p, p * (-d) % P);
  }
  T __sum1(int p) {
    T res = 0;
    while (p) {
      res = (res + C1[p]) % P;
      p -= p & -p;
    }
    return res;
  }
  T __sum2(int p) {
    T res = 0;
    while (p) {
      res = (res + C2[p]) % P;
      p -= p & -p;
    }
    return res;
  }
  T sum(int L, int R) {
    return ((R + 1) * __sum1(R) % P - __sum2(R) -
            (L * __sum1(L - 1) % P - __sum2(L - 1))) %
           P;
  }
};
Binary_Indexed_Tree<long long, N> BIT[40];
int now = -1;
void dfs3(int u, int fa, Binary_Indexed_Tree<long long, N> &BIT1,
          Binary_Indexed_Tree<long long, N> &BIT2, vector<int> &vc) {
  vc.push_back(u);
  if (hson[u]) dfs3(hson[u], u, BIT1, BIT2, vc);
  for (int e = head[u]; ~e; e = nxt[e]) {
    int v = to[e];
    if (v != fa && v != hson[u]) {
      vector<int> _vc;
      Binary_Indexed_Tree<long long, N> &_BIT1 = BIT[++now];
      Binary_Indexed_Tree<long long, N> &_BIT2 = BIT[++now];
      _BIT1.init(n);
      _BIT2.init(n);
      dfs3(v, u, _BIT1, _BIT2, _vc);
      for (auto it : _vc) {
        ans = (ans + BIT1.sum(l[it], r[it]) * inv[it] % P -
               BIT2.sum(l[it], r[it]) * inv[it] % P *
                   (dep[u] - dep[it] + dep[u] - dep[top[u]]) % P) %
              P;
      }
      for (auto it : _vc) {
        BIT1.add(l[it], r[it], (dep[it] - dep[top[u]]) * inv[it] % P);
        BIT2.add(l[it], r[it], inv[it]);
        vc.push_back(it);
        _BIT1.add(l[it], r[it], -(dep[it] - dep[v]) * inv[it] % P);
        _BIT2.add(l[it], r[it], -inv[it]);
      }
      --now;
      --now;
    }
  }
  ans = (ans + BIT1.sum(l[u], r[u]) * inv[u] % P -
         BIT2.sum(l[u], r[u]) * inv[u] % P * (dep[u] - dep[top[u]]) % P) %
        P;
  BIT1.add(l[u], r[u], (dep[u] - dep[top[u]]) * inv[u] % P);
  BIT2.add(l[u], r[u], inv[u]);
}
int main() {
  int u, v;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", l + i, r + i);
    inv[i] = fastpow(r[i] - l[i] + 1);
    sum = sum * (r[i] - l[i] + 1) % P;
  }
  tot = -1;
  memset(head, -1, (n + 4) * sizeof(int));
  for (int i = 1; i <= n - 1; ++i) {
    scanf("%d %d", &u, &v);
    addedge(u, v);
    addedge(v, u);
  }
  dfs1(1, 0);
  top[1] = 1;
  dfs2(1, 0);
  BIT[++now].init(n);
  BIT[++now].init(n);
  static vector<int> vc;
  dfs3(1, 0, BIT[0], BIT[1], vc);
  ans = (ans * sum % P + P) % P;
  printf("%I64d\n", ans);
  return 0;
}
