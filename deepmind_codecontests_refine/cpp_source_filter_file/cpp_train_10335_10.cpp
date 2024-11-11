#include <bits/stdc++.h>
using namespace std;
const int N = 1000002, L = 5002;
int n, m, l[N];
long long p, a[L][L], fac[L], C[N], f[N][2];
void pre() {
  a[0][0] = 1;
  for (int i = 1; i < L; ++i)
    for (int j = 1; j <= min(m, i); ++j)
      a[i][j] = (a[i - 1][j - 1] + a[i - 1][j] * (j - 1) % p) % p;
  fac[0] = 1;
  for (int i = 1; i < L; ++i) fac[i] = fac[i - 1] * i % p;
  C[0] = 1;
  for (int i = 1; i <= m; ++i) C[i] = C[i - 1] * (m - i + 1) % p;
}
int main() {
  scanf("%d%d%I64d", &n, &m, &p);
  pre();
  for (int i = 1; i <= n; ++i) scanf("%d", &l[i]);
  int qwq = 0;
  long long sum = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= min(m, l[i]); ++j)
      f[qwq][j] =
          (C[j] * sum % p - f[qwq ^ 1][j] * fac[j] % p) * a[l[i]][j] % p;
    sum = 0;
    for (int j = 1; j <= min(m, l[i]); ++j) sum = (sum + f[qwq][j]) % p;
    qwq ^= 1;
    for (int j = 1; j <= min(m, l[i - 1]); ++j) f[qwq][j] = 0;
  }
  printf("%I64d\n", sum);
  return 0;
}
