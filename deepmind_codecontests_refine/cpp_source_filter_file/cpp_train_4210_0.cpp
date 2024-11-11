#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long n, m;
struct mat {
  long long m[88][88];
} ans, a;
void init(mat &a) {
  memset(a.m, 0, sizeof(a.m));
  for (int i = 0; i < 2 * m + 3; i++) a.m[i][i] = 1;
}
mat mul(mat a, mat b) {
  mat c;
  memset(c.m, 0, sizeof(c.m));
  for (int i = 0; i < 2 * m + 3; i++) {
    for (int k = 0; k < 2 * m + 3; k++) {
      if (a.m[i][k] == 0) continue;
      for (int j = 0; j < 2 * m + 3; j++) {
        c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % mod;
        if (c.m[i][j] < 0) c.m[i][j] += mod;
      }
    }
  }
  return c;
}
mat mat_pow(mat a, int k) {
  mat b;
  init(b);
  while (k > 0) {
    if (k & 1) b = mul(a, b);
    a = mul(a, a);
    k >>= 1;
  }
  return b;
}
long long power(long long a, long long b) {
  return b ? power(a * a % mod, b / 2) * (b % 2 ? a : 1) % mod : 1;
}
long long C(int n, int k) {
  long long x = 1, y = 1;
  for (int i = 1; i <= k; i++) {
    x = x * (n - i + 1) % mod;
    y = y * i % mod;
  }
  return x * power(y, mod - 2) % mod;
}
int main() {
  memset(a.m, 0, sizeof(a.m));
  cin >> n >> m;
  a.m[0][0] = a.m[0][m + 1] = 1;
  for (int i = 1; i < 2 + m; i++) {
    for (int j = 1; j < 2 + m; j++) {
      if (j <= i)
        a.m[i][j] = C(i - 1, j - 1);
      else
        continue;
    }
  }
  for (int i = 1; i < 2 + m; i++) {
    for (int j = 2 + m; j < 3 + 2 * m; j++) {
      if (j - m - 2 <= i - 1)
        a.m[i][j] = C(i - 1, j - 2 - m);
      else
        continue;
    }
  }
  for (int i = 2 + m; i < 3 + 2 * m; i++) {
    for (int j = 1; j < 2 + m; j++) {
      if (j - 1 <= i - m - 2)
        a.m[i][j] = C(i - 2 - m, j - 1);
      else
        continue;
    }
  }
  memset(ans.m, 0, sizeof(ans.m));
  for (int i = 1; i < 2 * m + 3; i++) ans.m[i][0] = 1;
  ans = mul(mat_pow(a, n), ans);
  cout << ans.m[0][0];
}
