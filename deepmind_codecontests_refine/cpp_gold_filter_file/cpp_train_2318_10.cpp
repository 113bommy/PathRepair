#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
const int M = (1 << 20) + 5;
const int N = 1e6 + 5;
inline int read() {
  int x = 0, rev = 0, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') rev = 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  return rev ? -x : x;
}
int n, m, K, d[25], f[N], g[N], F[M], G[M], ans = -1, ansl, ansr, s1, t1;
char s[25], t[25];
int main() {
  n = read(), m = read(), K = read();
  memset(F, 127 / 3, sizeof F);
  cin >> s >> t;
  for (int i = 0; i < K; i++) {
    d[i] = i;
    if (s[i] == '1') s1++, f[0] |= (1 << i);
    if (t[i] == '1') t1++, g[0] |= (1 << i);
  }
  F[f[0]] = 0, G[g[0]] = 0;
  for (int i = 1; i <= n; i++) {
    swap(d[read() - 1], d[read() - 1]);
    for (int k = 0; k < K; k++) {
      if (s[k] == '1') f[i] |= (1 << d[k]);
      if (t[k] == '1') g[i] |= (1 << d[k]);
    }
    F[f[i]] = min(F[f[i]], i);
    G[g[i]] = max(G[g[i]], i);
  }
  for (int o = (1 << K) - 1; o >= 0; o--) {
    if (G[o] - F[o] >= m) {
      int both = __builtin_popcount(o);
      if (ans < (K + both * 2 - t1 - s1)) {
        ans = K + both * 2 - t1 - s1, ansl = F[o] + 1, ansr = G[o];
      }
    }
    for (int k = 0; k < K; k++) {
      if (o & (1 << k)) {
        F[o ^ (1 << k)] = min(F[o], F[o ^ (1 << k)]);
        G[o ^ (1 << k)] = max(G[o], G[o ^ (1 << k)]);
      }
    }
  }
  cout << ans << endl << ansl << " " << ansr << endl;
  return 0;
}
