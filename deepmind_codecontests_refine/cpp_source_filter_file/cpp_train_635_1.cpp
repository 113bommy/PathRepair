#include <bits/stdc++.h>
using namespace std;
const unsigned long long inv5 = 57646075230342349ull, mod = (1ull << 58) - 1,
                         maxn = 2e5 + 5;
unsigned long long T[10][10];
unsigned long long f[maxn][10];
void F(unsigned long long f[maxn][10], const int &n, const int &h) {
  for (int p = 1; p < n; p *= 10)
    for (int k = 0; k < n; k += p * 10)
      for (int i = k; i < k + p; i++) {
        for (int j = (0); j <= (9); j++) {
          for (int k = (0); k <= (9); k++) T[j][k] = 0;
          for (int k = (0); k <= (9); k++) {
            int K = h == 1 ? j * k % 10 : (10 - j * k % 10) % 10;
            for (int l = (0); l <= (9 - K); l++) T[j][l + K] += f[i + k * p][l];
            for (int l = (10 - K); l <= (9); l++)
              T[j][l + K - 10] += f[i + k * p][l];
          }
          if (h == -1)
            for (int k = (0); k <= (9); k++) T[j][k] = (T[j][k] >> 1) * inv5;
        }
        for (int j = (0); j <= (9); j++)
          for (int k = (0); k <= (9); k++) f[i + j * p][k] = T[j][k];
      }
}
unsigned long long A[10], B[10];
inline void mul(unsigned long long *c, unsigned long long *a,
                unsigned long long *b) {
  for (int i = (0); i <= (9); i++) A[i] = a[i], B[i] = b[i], c[i] = 0;
  for (int i = (0); i <= (9); i++)
    for (int j = (0); j <= (9); j++)
      c[i + j >= 10 ? i + j - 10 : i + j] += A[i] * B[j];
}
int m, n = 1, maxs;
unsigned long long X[10], ans[10];
void pksm(unsigned long long *c, unsigned long long *f, int k) {
  for (int i = (0); i <= (9); i++) X[i] = f[i], ans[i] = 0;
  ans[0] = 1;
  while (k) {
    if (k & 1) mul(ans, ans, X);
    mul(X, X, X);
    k >>= 1;
  }
  for (int i = (0); i <= (9); i++) c[i] = ans[i];
}
int main() {
  scanf("%d", &m);
  for (int i = (1); i <= (m); i++) {
    int x;
    scanf("%d", &x);
    f[x][0]++;
    maxs = max(maxs, x);
  }
  while (n < maxs) n *= 10;
  F(f, n, 1);
  for (int i = (0); i <= (n - 1); i++) pksm(f[i], f[i], m);
  F(f, n, -1);
  for (int i = (0); i <= (m - 1); i++) {
    printf("%llu\n", (f[i][0] - f[i][2] - f[i][5] + f[i][1]) & mod);
  }
  return 0;
}
