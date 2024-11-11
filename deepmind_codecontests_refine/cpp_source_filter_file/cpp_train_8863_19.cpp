#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
const long long p = 998244353;
long long c[maxn][maxn], w[maxn], inv[maxn];
long long qpow(long long a, long long b) {
  long long r = 1, t = a;
  while (b > 0) {
    if (b & 1) r = r * t % p;
    t = t * t % p;
    b >>= 1;
  }
  return r;
}
void init() {
  c[0][0] = 1;
  for (int i = 1; i < maxn; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
    }
  }
  for (int i = 1; i < maxn; i++) inv[i] = qpow(i, p - 2);
}
long long getf(long long x) {
  long long ans = 0, t = 1;
  if (x % 2) t *= -1;
  for (int i = 0; i <= x; i++) {
    ans = (ans + c[x][i] * inv[2 * x - i + 1] % p * t + p) % p;
    t *= -1;
  }
  ans = ans * qpow(2, x) % p;
  return ans;
}
int main() {
  init();
  long long n, k, l;
  cin >> n >> k >> l;
  for (int i = 1; i <= n; i++) {
    long long t = 1;
    if ((i - k) % 2) t *= -1;
    for (int j = k; j <= i; j++) {
      w[i] = (w[i] + p + c[n][j] * c[n - j][i - j] % p * t) % p;
      t *= -1;
    }
  }
  long long ans = 0;
  for (int i = k; i <= n; i++) {
    ans = (ans + w[i] * l % p * getf(i) % p + p) % p;
  }
  cout << ans << endl;
}
