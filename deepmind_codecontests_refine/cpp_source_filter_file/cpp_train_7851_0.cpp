#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e9;
long long powm(long long a, long long p, long long m) {
  long long r = 1 % m;
  while (p) {
    if (p & 1) r = r * a % m;
    p >>= 1;
    a = a * a % m;
  }
  return r;
}
int n, m, l, r, k, a[100000], b[100001][101] = {}, c[100200][101] = {};
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (n); ++i) scanf("%d", a + i);
  for (int i = 0; i < (101); ++i)
    for (int j = i; j < n + 101; ++j)
      if (i == 0 || j == i)
        c[j][i] = 1;
      else
        c[j][i] = (1ll * c[j - 1][i] + c[j - 1][i - 1]) % mod;
  for (int i = 0; i < (m); ++i) {
    scanf("%d%d%d", &l, &r, &k);
    b[l - 1][k] = (b[l - 1][k] + 1) % mod;
    for (int j = k; j >= 0; --j)
      b[r][j] = (b[r][j] - c[k - j + r - l][k - j] + mod) % mod;
  }
  for (int i = 100; i >= 0; --i) {
    for (int j = 1; j < n; ++j) {
      b[j][i] = (b[j - 1][i] + b[j][i]) % mod;
      if (i > 0) b[j][i - 1] = (b[j][i - 1] + b[j][i]) % mod;
    }
    if (i > 0) b[0][i - 1] += b[0][i];
  }
  for (int i = 0; i < (n); ++i) printf("%d ", a[i] + b[i][0]);
  puts("");
  return 0;
}
