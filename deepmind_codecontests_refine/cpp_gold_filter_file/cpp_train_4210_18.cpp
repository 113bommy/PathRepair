#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int c[45][45];
long long m;
struct mat {
  long long a[85][85];
  mat() { memset(a, 0, sizeof(a)); }
  mat operator*(const mat q) {
    mat c;
    for (int i = 1; i <= m; ++i)
      for (int k = 1; k <= m; ++k)
        if (a[i][k])
          for (int j = 1; j <= m; ++j) {
            c.a[i][j] += a[i][k] * q.a[k][j];
            if (c.a[i][j] >= mod) c.a[i][j] %= mod;
          }
    return c;
  }
};
mat qpow(mat x, long long n) {
  mat ans;
  for (int i = 1; i <= 84; ++i) ans.a[i][i] = 1;
  while (n) {
    if (n & 1) ans = ans * x;
    x = x * x;
    n >>= 1;
  }
  return ans;
}
void init() {
  for (int i = 0; i <= 41; ++i) c[i][0] = c[i][i] = 1;
  for (int i = 1; i <= 41; ++i)
    for (int j = 1; j < i; ++j) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
}
int main() {
  long long n, k;
  init();
  scanf("%lld %lld", &n, &k);
  mat ans;
  m = 2 * k + 3;
  ans.a[1][1] = 1;
  for (int i = 2; i <= m; ++i) {
    ans.a[i][1] = 0;
    ans.a[1][i] = c[k][(i - 2) % (k + 1)];
  }
  for (int i = 2; i <= k + 2; ++i)
    for (int j = 2; j <= i; ++j)
      ans.a[i][j] = ans.a[i][j + k + 1] = ans.a[i + k + 1][j] = c[i - 2][j - 2];
  ans = qpow(ans, n - 1);
  long long sum = 0;
  for (int i = 1; i <= m; ++i) sum = (sum + ans.a[1][i]) % mod;
  printf("%lld\n", sum);
  return 0;
}
