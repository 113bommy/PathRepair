#include <bits/stdc++.h>
using namespace std;
const int maxn = 101000;
const int mod = 1e9 + 7;
long long n, k, a, b;
long long x, y;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long suan(long long a, long long b) {
  long long g = gcd(a, b);
  b /= g;
  return b;
}
void solve() {
  x = 1e9;
  y = -10000;
  cin >> n >> k >> a >> b;
  long long l, t;
  if (n == 1) {
    if (a > b) {
      l = k - a - b;
      if (l > 0) {
        t = suan(l, n * k);
        x = min(x, t);
        y = max(y, t);
      }
      l = a - b;
      t = suan(l, n * k);
      x = min(x, t);
      y = max(y, t);
    } else if (a == b) {
      l = k - a - b;
      t = suan(l, n * k);
      x = min(x, t);
      y = max(y, t);
    } else {
      l = k - a - b;
      if (l > 0) {
        t = suan(l, n * k);
        x = min(x, t);
        y = max(y, t);
      }
      l = abs(a - b);
      t = suan(l, n * k);
      x = min(x, t);
      y = max(y, t);
    }
  } else {
    for (long long i = -1; i <= n + 10; i++) {
      l = b - a + i * k;
      if (l <= 0) continue;
      if (l > n * k) break;
      t = suan(l, n * k);
      x = min(x, t);
      y = max(y, t);
    }
    for (long long i = -1; i <= n + 10; i++) {
      l = a + b + i * k;
      if (l <= 0) continue;
      if (l > n * k) break;
      t = suan(l, n * k);
      x = min(x, t);
      y = max(y, t);
    }
    for (long long i = -1; i <= n + 10; i++) {
      l = i * k - a - b;
      if (l <= 0) continue;
      if (l > n * k) break;
      t = suan(l, n * k);
      x = min(x, t);
      y = max(y, t);
    }
    for (long long i = -1; i <= n + 10; i++) {
      l = a - b + i * k;
      if (l <= 0) continue;
      if (l > n * k) break;
      t = suan(l, n * k);
      x = min(x, t);
      y = max(y, t);
    }
  }
  cout << x << " " << y << endl;
}
int main() {
  solve();
  return 0;
}
