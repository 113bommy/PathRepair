#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int phi = 998244352;
const int g = 3;
struct mat {
  int n, m;
  long long a[105][105];
  mat() {
    n = m = 0;
    memset(a, 0, sizeof(a));
  }
  void pr() {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) cout << a[i][j] << ' ';
      cout << '\n';
    }
  }
  friend mat operator*(const mat &a, const mat &b) {
    mat c;
    c.n = a.n;
    c.m = b.m;
    for (int i = 1; i <= a.n; i++)
      for (int j = 1; j <= b.m; j++)
        for (int k = 1; k <= a.m; k++)
          c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j] % phi) % phi;
    return c;
  }
} acc, bas;
int k;
int n, m;
int b[105];
long long qkpow(int a, long long b) {
  if (b == -1) return -1;
  if (b == 0) return 1;
  if (b == 1) return a;
  long long t = qkpow(a, b / 2);
  t = t * t % mod;
  if (b & 1) t = t * a % mod;
  return t;
}
mat qkpow(mat a, long long b) {
  if (b == 1) return a;
  mat t = qkpow(a, b / 2);
  t = t * t;
  if (b & 1) t = t * a;
  return t;
}
long long bsgs(long long a, long long b, long long mod) {
  unordered_map<int, int> f;
  long long m = ceil(sqrt(mod));
  long long temp = 1;
  for (int i = 1; i <= m; i++) {
    temp = temp * a % mod;
    f[b * temp % mod] = i;
  }
  long long ret = temp;
  for (int i = 1; i <= m; i++, ret = ret * temp % mod)
    if (f.count(ret)) return i * m - f[ret];
  return -1;
}
int main() {
  cin >> k;
  for (int i = 1; i <= k; i++) cin >> b[i];
  cin >> n >> m;
  bas.n = k;
  bas.m = 1;
  bas.a[k][1] = 1;
  acc.n = acc.m = k;
  for (int i = 2; i <= k; i++) acc.a[i - 1][i] = 1;
  for (int i = 1; i <= k; i++) acc.a[k][i] = b[k - i + 1];
  bas = qkpow(acc, n - k) * bas;
  long long now = qkpow(3, bas.a[k][1]);
  cout << qkpow(3, bsgs(now, m, mod));
  return 0;
}
