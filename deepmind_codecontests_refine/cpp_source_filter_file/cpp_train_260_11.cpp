#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
const long long mod = 1e9 + 7;
const int getint() {
  char c;
  int f = 0;
  while (c = getchar(), c > '9' || c < '0')
    ;
  while (f = (f << 1) + (f << 3) + c - '0', c = getchar(), c >= '0' && c <= '9')
    ;
  return f;
}
int n, m, sx;
int S[N], F[N], Q[N];
char T[N];
int a[N];
inline int min(int a, int b) { return a > b ? b : a; }
inline int pop_count(int x) {
  int cnt = 0;
  while (x) x -= x & -x, ++cnt;
  return cnt;
}
inline void XOR(int *t, int rev) {
  for (register int k = 2; k <= n + 1; ++k) {
    int L = 1 << (k - 1), h_len = 1 << (k - 2);
    for (register int i = 0; i < sx; i += L) {
      for (register int j = 0; j < h_len; ++j) {
        int t1 = t[i + j], t2 = t[i + j + h_len];
        switch (rev) {
          case 1: {
            t[i + j] = (t1 + t2) % mod;
            t[i + j + h_len] = (t1 - t2) % mod;
            break;
          }
          case -1: {
            t[i + j] = 1ll * (t1 + t2) * (mod - mod / 2ll) % mod;
            t[i + j + h_len] =
                1ll * (t1 - t2 + mod) % mod * (mod - mod / 2ll) % mod;
            break;
          }
        }
      }
    }
  }
}
signed main() {
  n = getint(), m = getint();
  for (register int i = 0; i < n; ++i) {
    scanf("%s", T);
    for (register int j = 0; j < m; ++j) {
      a[j] |= (T[j] - '0') << i;
    }
  }
  sx = 1 << n;
  for (register int i = 0; i < sx; ++i)
    F[i] = min(pop_count(i), pop_count(sx - 1 - i));
  for (register int i = 0; i < m; ++i) ++Q[a[i]];
  XOR(F, 1);
  XOR(Q, 1);
  for (register int i = 0; i < sx; ++i) F[i] = 1ll * F[i] * Q[i] % mod;
  XOR(F, -1);
  int ans = 0x3f3f3f3f;
  for (register int i = 0; i < sx; ++i) ans = min(ans, F[i]);
  printf("%d\n", ans);
  return 0;
}
