#include <bits/stdc++.h>
using namespace std;
const int N = 104;
int n, l, m, t;
long long a[N], b[N][N], mod = 1000000007;
int x[N], z[N * N * N];
void muls(long long b[N][N]) {
  long long c[N][N];
  memset(c, 0, sizeof(c));
  for (int i = 0; i < m; i++)
    for (int k = 0; k < m; k++)
      for (int j = 0; j < m; j++) c[i][j] = (c[i][j] + b[i][k] * b[k][j]) % mod;
  memcpy(b, c, sizeof(c));
}
void mul(long long a[N], long long b[N][N]) {
  long long c[N];
  memset(c, 0, sizeof(c));
  for (int i = 0; i < m; i++)
    for (int k = 0; k < m; k++) c[i] = (c[i] + a[k] * b[k][i]) % mod;
  memcpy(a, c, sizeof(c));
}
int main() {
  scanf("%d %d %d", &n, &l, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    ++a[t % m];
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    z[i] = t;
    ++x[t % m];
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    z[i] += t;
    z[i] %= m;
  }
  for (int i = 0; i < m; i++)
    for (int j = 0; j < m; j++) b[i][j] = x[(j - i + m) % m];
  for (int i = l - 2; i; i >>= 1) {
    if (i & 1) mul(a, b);
    muls(b);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans = (ans + a[(m - z[i]) % m]) % mod;
  }
  printf("%lld\n", ans);
}
