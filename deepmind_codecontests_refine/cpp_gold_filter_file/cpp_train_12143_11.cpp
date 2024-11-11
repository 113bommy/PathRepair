#include <bits/stdc++.h>
using namespace std;
const int N = 55;
const int S = 1 << 23;
const int mod = 1e9 + 7;
int n;
int fa[N], sz[N], cnt[S], pw[S], home[N], E[N];
char mp[N][N];
template <typename T>
inline void chkmax(T &x, T y) {
  x = max(x, y);
}
template <typename T>
inline void chkmin(T &x, T y) {
  x = min(x, y);
}
template <typename T>
inline void read(T &x) {
  T f = 1;
  x = 0;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -f;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + c - '0';
  x *= f;
}
inline void inc(int &x, int y) { x = x + y < mod ? x + y : x + y - mod; }
inline void dec(int &x, int y) { x = x - y >= 0 ? x - y : x - y + mod; }
inline int find(int x) { return fa[x] == x ? x : (fa[x] = find(fa[x])); }
inline void merge(int u, int v) {
  if (find(u) == find(v)) return;
  fa[find(u)] = find(v);
  sz[find(v)] += sz[find(u)];
  return;
}
int main() {
  read(n);
  for (int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 1;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", mp[i] + 1);
    for (int j = 1; j <= n; ++j)
      if (mp[i][j] == 'A') merge(i, j);
  }
  int scc = 0;
  for (int i = 1; i <= n; ++i)
    if (find(i) == i && sz[i] > 1) home[i] = scc++;
  for (int u = 1; u <= n; ++u)
    for (int v = u + 1; v <= n; ++v) {
      if (mp[u][v] == 'X') {
        int fu = find(u), fv = find(v);
        if (fu == fv) {
          puts("-1");
          return 0;
        }
        if (sz[fu] > 1 && sz[fv] > 1)
          E[home[fu]] |= (1 << home[fv]), E[home[fv]] |= (1 << home[fu]);
      }
    }
  cnt[0] = 1;
  int all = 1 << scc;
  for (int s = 1; s < all; ++s) {
    int t = s & -s;
    cnt[s] = (cnt[s ^ t] + cnt[s ^ t ^ (s & E[__builtin_ctz(t)])]) % mod;
  }
  for (int i = 0; i <= all; ++i) pw[i] = 1;
  for (int k = 0;; ++k) {
    int cur = 0;
    for (int i = 0; i < all; ++i) {
      if ((n - __builtin_popcount(i)) & 1)
        dec(cur, pw[i]);
      else
        inc(cur, pw[i]);
      pw[i] = (long long)pw[i] * cnt[i] % mod;
    }
    if (cur != 0) {
      printf("%d\n", n - 1 + k);
      return 0;
    }
  }
  return 0;
}
