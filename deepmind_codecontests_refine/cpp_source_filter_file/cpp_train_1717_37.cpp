#include <bits/stdc++.h>
using namespace std;
long long n, k;
int l, m;
unsigned long long p[65];
queue<int> q;
struct matrix {
  long long a[2][2];
  matrix() { a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0; }
  void unit() { a[0][0] = a[1][1] = 1; }
  matrix operator*(const matrix& p) {
    matrix ans;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
          ans.a[i][j] += a[i][k] * p.a[k][j];
          if (ans.a[i][j] >= m) ans.a[i][j] %= m;
        }
      }
    }
    return ans;
  }
};
long long fi() {
  if (n == 1) return 2;
  if (n == 2) return 3;
  long long t = n;
  t -= 2;
  matrix ans, p;
  p.a[0][0] = 1, p.a[1][0] = 1, p.a[0][1] = 1;
  ans.unit();
  while (t) {
    if (t & 1) ans = ans * p;
    p = p * p;
    t >>= 1;
  }
  return (3 * ans.a[0][0] + 2 * ans.a[1][0]) % m;
}
long long quickpow(long long x, long long y) {
  long long ans = 1;
  while (y) {
    if (y & 1) {
      ans = ans * x;
      if (ans >= m) ans %= m;
    }
    x *= x;
    if (x >= m) x %= m;
    y >>= 1;
  }
  return ans;
}
void solve() {
  if (p[l] - 1 < (unsigned long long)k && l != 64) {
    puts("0");
    return;
  }
  while (k) {
    q.push(k & 1);
    k >>= 1;
  }
  long long x = fi(), y = (quickpow(2, n) - x + m) % m, ans = 1;
  for (int i = 0; i < l; ++i) {
    if (!q.empty()) {
      if (q.front())
        ans = ans * y;
      else
        ans = ans * x;
      q.pop();
    } else {
      ans = ans * x;
    }
    if (ans >= m) ans %= m;
  }
  printf("%I64d\n", ans);
}
int main() {
  cin >> n >> k >> l >> m;
  p[0] = 1;
  for (int i = 1; i < 64; ++i) p[i] = p[i - 1] * 2;
  solve();
  return 0;
}
