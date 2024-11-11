#include <bits/stdc++.h>
using namespace std;
bool debug = 1;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
long long ln, lk, lm;
const int mod = 1051131;
long long fastPow(long long x, long long y) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
int s, a[(1 << 25) + 5], hf;
long long t;
void dfs(int n, int p, int q) {
  if (n == 1) {
    a[1] = fastPow(p + q, t) * a[1] % mod;
    return;
  }
  n /= 2;
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    int x = a[i], y = a[i + n];
    a[i] = (x + y) % mod;
    a[i + n] = (x - y + mod) % mod;
  }
  dfs(n, p * 2 % mod, ((long long)(n - 1) * p % mod + q) % mod);
  long long r = (((long long)(1 - n) % mod + mod) % mod * p % mod + q) % mod;
  r = fastPow(r, t);
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    int x = a[i], y = (long long)a[i + n] * r % mod;
    a[i] = (long long)(x + y) * hf % mod;
    a[i + n] = (long long)(x - y + mod) % mod * hf % mod;
  }
}
int main() {
  hf = (mod + 1) / 2;
  scanf("%d%lld%d", &m, &t, &s);
  for (int(i) = 1; (i) <= (int)(s); (i)++) {
    scanf("%d", a + i);
  }
  for (int i = s + 1; i <= (1 << m); i++) {
    a[i] = (101 * a[i - s] + 10007) % mod;
  }
  dfs(1 << m, 1, 0);
  int ans = 0;
  for (int(i) = 1; (i) <= (int)(1 << m); (i)++) ans ^= a[i];
  printf("%d\n", ans);
  return 0;
}
