#include <bits/stdc++.h>
char ch;
inline void read(int &x) {
  x = 0;
  ch = getchar();
  while (ch <= 32) ch = getchar();
  while (ch > 32) {
    x = x * 10 + ch - 48;
    ch = getchar();
  };
};
template <class T>
inline T min(T a, T b) {
  return a < b ? a : b;
};
struct segtree {
  int tr[131072 * 2];
  inline void mod(int x, int val) {
    x += 131072;
    while (x) {
      tr[x] += val;
      x >>= 1;
    };
  };
  inline int getsum(int l, int r) {
    if (l > r) return 0;
    int ret = 0;
    l += 131072 - 1;
    r += 131072 + 1;
    while (l ^ r ^ 1) {
      if (~l & 1) ret += tr[l ^ 1];
      if (r & 1) ret += tr[r ^ 1];
      l >>= 1;
      r >>= 1;
    };
    return ret;
  };
  inline int getnext(int x) {
    x += 131072;
    while (x ^ 1) {
      if (~x & 1 && tr[x ^ 1]) break;
      x >>= 1;
    };
    if (x == 1) return 1000000000;
    x ^= 1;
    while (x < 131072) {
      x <<= 1;
      if (!tr[x]) ++x;
    };
    return x - 131072;
  };
  inline int getprev(int x) {
    x += 131072;
    while (x ^ 1) {
      if (x & 1 && tr[x ^ 1]) break;
      x >>= 1;
    };
    if (x == 1) return -1000000000;
    x ^= 1;
    while (x < 131072) {
      x <<= 1;
      if (tr[x + 1]) ++x;
    };
    return x - 131072;
  };
};
segtree T;
std::vector<int> a1[100005], a2[100005];
struct data {
  int t, s, e, id;
};
inline bool operator<(data a, data b) { return a.t < b.t; };
data a[100005];
int e[100005];
int n, m;
long long ans[100005];
inline void solve() {
  long long nowt = 0;
  long long t1 = a[1].t;
  int id = 1;
  int nowf = 1;
  while (1) {
    int u = T.getsum(nowf + 1, m);
    int d = T.getsum(1, nowf - 1);
    if (!u && !d) {
      if (t1 < 1000000000) {
        nowt = t1;
      } else {
        break;
      };
    } else if (u >= d) {
      int dt = T.tr[nowf + 131072]
                   ? 0
                   : min(1LL * T.getnext(nowf) - nowf, t1 - nowt);
      if (dt <= m) {
        nowt += dt;
        nowf += dt;
      } else {
        break;
      };
    } else {
      int dt = T.tr[nowf + 131072]
                   ? 0
                   : min(1LL * nowf - T.getprev(nowf), t1 - nowt);
      if (dt <= m) {
        nowt += dt;
        nowf -= dt;
      } else {
        break;
      };
    };
    int sz = a2[nowf].size();
    int i;
    for (i = 0; i < sz; i++) {
      ans[a2[nowf][i]] = nowt;
    };
    T.mod(nowf, -sz);
    a2[nowf].clear();
    while (nowt == t1) {
      int x = a[id].id;
      a1[a[id].s].push_back(x);
      T.mod(a[id].s, 1);
      ++id;
      if (id > n) {
        t1 = 1000000000000000000LL;
      } else {
        t1 = a[id].t;
      };
    };
    sz = a1[nowf].size();
    T.mod(nowf, -sz);
    for (i = 0; i < sz; i++) {
      int x = a1[nowf][i];
      a2[e[x]].push_back(x);
      T.mod(e[x], 1);
    };
    a1[nowf].clear();
  };
};
int main() {
  read(n);
  read(m);
  int i;
  for (i = 1; i <= n; i++) {
    int t, s, f;
    read(t);
    read(s);
    read(f);
    a[i] = (data){t, s, f, i};
    ::e[i] = f;
  };
  std::sort(a + 1, a + n + 1);
  solve();
  for (i = 1; i <= n; i++) {
    printf("%I64d\n", ans[i]);
  };
}
