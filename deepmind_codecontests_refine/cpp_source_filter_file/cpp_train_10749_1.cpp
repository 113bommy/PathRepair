#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int now = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c == '-' && (f = -1), c = getchar())
    ;
  for (; isdigit(c); now = now * 10 + c - 48, c = getchar())
    ;
  return now * f;
}
const int mod = 998244353;
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a < b ? a - b + mod : a - b; }
inline int mul(int a, int b) { return 1LL * a * b % mod; }
int qpow(int a, int b) {
  int ret = 1;
  for (; b; b >>= 1) {
    if (b & 1) ret = mul(ret, a);
    a = mul(a, a);
  }
  return ret;
}
const int N = 1e5 + 10;
const int M = 22;
int g[M][M];
vector<int> es[M];
char s1[N], s2[N];
int mp[M], rch[M], f[1 << M];
int bitcnt(int x) {
  int ret = 0;
  for (int i = x; i; i -= i & -i) ret++;
  return ret;
}
int solve(int G) {
  int n = 0, cnt = 0;
  for (int x = 0; x < 20; x++)
    if ((G >> x) & 1) n++, mp[x] = cnt++;
  for (int x = 0; x < 20; x++) {
    if ((G >> x) & 1) {
      rch[mp[x]] = 0;
      for (auto &y : es[x]) rch[mp[x]] |= (1 << mp[y]);
    }
  }
  int LDAG = 0, MK = (1 << n);
  for (int i = 0; i < MK; i++) f[i] = 0;
  f[0] = 1;
  for (int i = 1; i < MK; i++) {
    for (int j = 0; j < n; j++) {
      if ((i >> j) & 1) {
        f[i] |= f[i ^ (1 << j)] && ((i & rch[j]) == 0);
      }
    }
    if (f[i]) LDAG = max(LDAG, bitcnt(i));
  }
  return 2 * n - LDAG - 1;
}
int fa[M];
int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }
int main() {
  int T = read();
  while (T--) {
    int n = read();
    scanf("%s%s", s1 + 1, s2 + 1);
    for (int i = 0; i < 20; i++) es[i].clear();
    for (int i = 0; i < 20; i++) fa[i] = i;
    memset(g, 0, sizeof(g));
    for (int i = 1; i <= n; i++) {
      int x = s1[i] - 'a', y = s2[i] - 'a';
      if (x == y || g[x][y]) continue;
      es[x].emplace_back(y);
      g[x][y] = 1;
      int fx = get(x), fy = get(y);
      if (fx != fy) fa[fx] = fy;
    }
    int ans = 0;
    for (int i = 0; i < 20; i++) {
      int G = 0;
      for (int j = 0; j < 20; j++) {
        if (fa[j] == i) G |= (1 << j);
      }
      if (G) ans += solve(G);
    }
    printf("%d\n", ans);
  }
  return 0;
}
