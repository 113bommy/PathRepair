#include <bits/stdc++.h>
using namespace std;
const int mo = 1000000007;
const int N = 255;
int n, m, p[15], c[105];
int f[N], a[N], b[N], d[N];
int X[N], Y[N], Z[N * 2];
long long T;
void mult(int *A, int *B) {
  memcpy(X, A, sizeof(X));
  memcpy(Y, B, sizeof(Y));
  memset(Z, 0, sizeof(Z));
  for (int i = (int)(0); i <= (int)(N - 1); i++)
    for (int j = (int)(0); j <= (int)(N - 1); j++)
      Z[i + j] = (Z[i + j] + 1ll * X[i] * Y[j]) % mo;
  for (int i = (int)(N * 2 - 1); i >= (int)(N); i--)
    if (Z[i]) {
      int t = Z[i];
      Z[i] = 0;
      for (int j = (int)(0); j <= (int)(m - 1); j++)
        Z[i - c[j]] = (Z[i - c[j]] + t) % mo;
    }
  memcpy(A, Z, N << 2);
}
void power(long long t) {
  if (t == 1) {
    memcpy(d, b, sizeof(d));
    return;
  }
  power(t / 2);
  mult(d, d);
  if (t & 1) mult(d, b);
}
int main() {
  scanf("%d%d%lld", &n, &m, &T);
  for (int i = (int)(0); i <= (int)(n - 1); i++) scanf("%d", &p[i]);
  for (int i = (int)(0); i <= (int)(m - 1); i++) scanf("%d", &c[i]);
  f[0] = 1;
  for (int i = (int)(1); i <= (int)(N - 1); i++)
    for (int j = (int)(0); j <= (int)(m - 1); j++)
      if (c[j] <= i) f[i] = (f[i] + f[i - c[j]]) % mo;
  for (int i = (int)(0); i <= (int)(n - 1); i++) {
    memset(b, 0, sizeof(b));
    b[1] = 1;
    power(p[i]);
    for (int j = (int)(0); j <= (int)(N - 1); j++) a[j] = (a[j] + d[j]) % mo;
  }
  memcpy(b, a, sizeof(b));
  power(T);
  int ans = 0;
  for (int i = (int)(0); i <= (int)(N - 1); i++)
    ans = (ans + 1ll * f[i] * d[i]) % mo;
  printf("%d", ans);
}
