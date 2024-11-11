#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
const int P = 998244353;
const int INF = 0x3f3f3f3f;
inline int read() {
  int x(0), w(1);
  char c = getchar();
  while (c ^ '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') w = -1, c = getchar();
  while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0', c = getchar();
  return x * w;
}
char s[N], t[N];
int ls, lt, n, len, inv, fa[N * 6], ans[N];
vector<int> f[6], g[6], tmp;
int R[N << 2], a[N << 2], b[N << 2];
inline int qpow(int x, int y) {
  int res = 1;
  while (y > 0) {
    if (y & 1) res = (1ll * (res) * (x) % P);
    y >>= 1, x = (1ll * (x) * (x) % P);
  }
  return res;
}
inline void init() {
  n = 1, len = ls + ls - 1;
  while (n <= len) n <<= 1;
  for (int i = 1; i < n; ++i)
    R[i] = (R[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0);
  inv = qpow(n, P - 2);
}
inline void NTT(vector<int>& a, int Tp) {
  for (int i = 0; i < n; ++i)
    if (i < R[i]) swap(a[i], a[R[i]]);
  for (int i = 1; i < n; i <<= 1) {
    int w0 = (Tp == 0) ? qpow(3, (P - 1) / i / 2)
                       : qpow(qpow(3, (P - 1) / i / 2), P - 2);
    for (int j = 0; j < n; j += (i << 1)) {
      int w = 1;
      for (int k = j; k < j + i; ++k) {
        int tmp = (1ll * (a[k + i]) * (w) % P);
        a[k + i] =
            ((a[k]) - (tmp) < 0) ? ((a[k]) - (tmp) + P) : ((a[k]) - (tmp));
        a[k] = ((a[k]) + (tmp) >= P) ? ((a[k]) + (tmp)-P) : ((a[k]) + (tmp));
        w = (1ll * (w) * (w0) % P);
      }
    }
  }
  if (Tp) {
    for (int i = 0; i < n; ++i) a[i] = (1ll * (a[i]) * (inv) % P);
  }
}
int find(int x) { return (fa[x] == x) ? x : fa[x] = find(fa[x]); }
inline void merge(int x, int y) {
  int a = find(x), b = find(y);
  if (a == b) return;
  fa[a] = b;
  ++ans[x / 6];
}
int main() {
  scanf("%s%s", s, t);
  ls = strlen(s), lt = strlen(t);
  for (int i = 0; i <= (ls - lt + 1) * 6; ++i) {
    fa[i] = i;
  }
  init();
  for (int u = 0; u < 6; ++u) {
    f[u].resize(n);
    g[u].resize(n);
    for (int i = 0; i < ls; ++i) {
      f[u][i] = (s[i] == u + 'a');
    }
    for (int i = 0; i < lt; ++i) {
      g[u][lt - i - 1] = (t[i] == u + 'a');
    }
    NTT(f[u], 0);
    NTT(g[u], 0);
  }
  for (int u = 0; u < 6; ++u) {
    for (int v = 0; v < 6; ++v) {
      if (u == v) continue;
      tmp.resize(n);
      for (int i = 0; i < n; ++i) {
        tmp[i] = (1ll * (f[u][i]) * (g[v][i]) % P);
      }
      NTT(tmp, 1);
      for (int i = lt - 1; i < ls; ++i) {
        if (tmp[i] > 0) {
          merge((i - lt + 1) * 6 + u, (i - lt + 1) * 6 + v);
        }
      }
    }
  }
  for (int i = 0; i + lt <= ls; ++i) {
    printf("%d ", ans[i]);
  }
  printf("\n");
  return 0;
}
