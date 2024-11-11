#include <bits/stdc++.h>
const int maxn = 200005, K = 4, mod = 1e9 + 7;
int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int dec(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
int mul(int a, int b) { return 1ll * a * b % mod; }
int ksm(int a, int b = mod - 2) {
  int ret = 1;
  for (; b; b >>= 1, a = mul(a, a))
    if (b & 1) ret = mul(ret, a);
  return ret;
}
int N, Q, A[maxn], L, R, D, sum[maxn], sumK[maxn], Inv;
int zz[maxn][K + 5], C[K + 5][K + 5];
int main() {
  Inv = ksm(2);
  scanf("%d%d", &N, &Q);
  C[0][0] = 1;
  for (int i = 1; i <= K; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
  }
  for (int i = 0; i <= K; i++) {
    zz[0][i] = i == 0 ? 1 : 0;
    for (int j = 1; j <= N; j++) zz[j][i] = add(zz[j - 1][i], ksm(j, i));
  }
  for (int i = 1; i <= N; i++)
    scanf("%d", A + i), sum[i] = add(sum[i - 1], A[i]),
                        sumK[i] = add(sumK[i - 1], ksm(A[i], K));
  while (Q--) {
    scanf("%d%d%d", &L, &R, &D);
    int m = R - L + 1;
    int s = dec(sum[R], sum[L - 1]);
    int sK = dec(sumK[R], sumK[L - 1]);
    int a1 = mul(dec(s, mul(mul(mul(m, m - 1), Inv), D)), ksm(m));
    int res = 0;
    for (int j = 0; j <= K; j++)
      res = add(
          res, mul(mul(mul(C[K][j], ksm(D, j)), ksm(a1, K - j)), zz[m - 1][j]));
    puts(res == sK ? "Yes" : "No");
  }
  return 0;
}
