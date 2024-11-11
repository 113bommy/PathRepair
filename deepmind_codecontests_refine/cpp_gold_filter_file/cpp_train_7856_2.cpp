#include <bits/stdc++.h>
using namespace std;
int n, m, k, limit = 1, s, ANS, pos[1000050], t[1000050];
char S[1000050], T[1000050], opt[4] = {'A', 'G', 'C', 'T'};
int a[1000050], b[1000050], c[1000050], ans[1000050];
int ksm(int u, int v) {
  int sum = 1;
  while (v) {
    if (v & 1) sum = (long long)sum * u % 998244353;
    v >>= 1;
    u = (long long)u * u % 998244353;
  }
  return sum;
}
void NTT(int *nw, int opt) {
  for (int i = 0; i < limit; ++i)
    if (i < pos[i]) swap(nw[i], nw[pos[i]]);
  for (int mid = 1; mid < limit; mid <<= 1) {
    int base = ksm(3, (998244353 - 1) / (mid << 1));
    if (opt == -1) base = ksm(base, 998244353 - 2);
    for (int len = mid << 1, i = 0; i < limit; i += len) {
      int w = 1;
      for (int j = 0; j < mid; j++, w = (long long)w * base % 998244353) {
        int x = nw[i + j];
        int y = (long long)w * nw[i + j + mid] % 998244353;
        nw[i + j] = (x + y) % 998244353;
        nw[i + j + mid] = (x - y + 998244353) % 998244353;
      }
    }
  }
}
int main() {
  scanf("%d%d%d%s%s", &n, &m, &k, S, T);
  --n;
  --m;
  reverse(T, T + m + 1);
  while (limit <= n + m) limit <<= 1, s++;
  for (int i = 0; i < limit; ++i)
    pos[i] = (pos[i >> 1] >> 1) | ((i & 1) << (s - 1));
  for (int w = 0; w < 4; ++w) {
    for (int i = 0; i < limit; ++i) a[i] = b[i] = t[i] = 0;
    for (int i = 0; i <= m; ++i)
      if (T[i] == opt[w]) a[i] = 1;
    for (int i = 0; i <= n; ++i)
      if (S[i] == opt[w]) t[max(0, i - k)]++, t[min(n, i + k) + 1]--;
    for (int i = 0; i <= n; ++i, t[i] += t[i - 1])
      if (t[i]) b[i] = 1;
    NTT(a, 1);
    NTT(b, 1);
    for (int i = 0; i < limit; ++i) c[i] = (long long)a[i] * b[i] % 998244353;
    NTT(c, -1);
    int inv = ksm(limit, 998244353 - 2);
    for (int i = 0; i <= n; ++i) ans[i] += (long long)c[i] * inv % 998244353;
  }
  for (int i = 0; i <= n; ++i)
    if (ans[i] > m) ++ANS;
  printf("%d", ANS);
  return 0;
}
