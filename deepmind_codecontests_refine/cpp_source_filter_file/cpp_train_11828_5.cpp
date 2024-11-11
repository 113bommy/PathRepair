#include <bits/stdc++.h>
using namespace std;
const int N = 250009, K = 250009;
int n, k, M, f[29][N], fac[N], inv_fac[N];
int ksm(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % M;
    b >>= 1, a = 1ll * a * a % M;
  }
  return res;
}
void init() {
  scanf("%d %d %d", &n, &k, &M);
  fac[0] = 1;
  for (int i = 1; i <= K; i++) fac[i] = 1ll * fac[i - 1] * i % M;
  inv_fac[K] = ksm(fac[K], M - 2);
  for (int i = K - 1; i >= 0; i--)
    inv_fac[i] = 1ll * inv_fac[i + 1] * (i + 1) % M;
}
int lowbit(int x) { return x & (-x); }
int solve(int cur, int S) {
  if (f[cur][S] != -1) return f[cur][S];
  if (!S) {
    f[cur][S] = fac[n];
    for (int i = 1; i <= cur; i++)
      f[cur][S] = 1ll * f[cur][S] * (k - i + 1) % M;
    return f[cur][S];
  }
  f[cur][S] = 0;
  int U = S - lowbit(S);
  for (int T = U; T; T = (T - 1) & U)
    f[cur][S] = (f[cur][S] + 1ll * inv_fac[S - T] * solve(cur + 1, T) % M) % M;
  f[cur][S] = (f[cur][S] + 1ll * inv_fac[S] * solve(cur + 1, 0) % M) % M;
  return f[cur][S];
}
void work() {
  if (k & 1)
    printf("%d\n", ksm(k, n));
  else {
    memset(f, -1, sizeof(f));
    int res = (ksm(k, n) - solve(0, n) + M) % M;
    printf("%d\n", res);
  }
}
int main() {
  init();
  work();
  return 0;
}
