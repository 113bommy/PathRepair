#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e12 + 10;
long long Mod;
void mul(long long a[2][2], long long b[2][2], long long c[2][2]) {
  long long d[2][2];
  memset(d, 0, sizeof(d));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        d[i][j] += (a[i][k] * b[k][j]) % Mod;
        d[i][j] %= Mod;
      }
    }
  }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) c[i][j] = d[i][j];
  return;
}
int fib(long long x) {
  long long top, d[200], m1[2][2], m[2][2];
  int i;
  top = -1;
  while (x > 0) {
    top++;
    d[top] = x % 2;
    x = x / 2;
  }
  m1[0][0] = 1;
  m1[0][1] = 1;
  m1[1][0] = 1;
  m1[1][1] = 0;
  m[0][0] = 1;
  m[0][1] = 0;
  m[1][0] = 0;
  m[1][1] = 1;
  for (int i = top; i >= 0; i--) {
    mul(m, m, m);
    if (d[i] == 1) mul(m, m1, m);
  }
  return m[1][0];
}
long long cnt(long long l, long long r, long long x) {
  return r / x - (l - 1) / x;
}
int main() {
  ios::sync_with_stdio(false);
  long long l, r, k;
  cin >> Mod >> l >> r >> k;
  long long ans = 0;
  for (long long i = 1; i * i <= r; i++) {
    if (cnt(l, r, i) >= k) ans = max(ans, i);
    if (cnt(l, r, r / i) >= k) ans = max(ans, r / i);
  }
  long long s = 1, e = inf;
  while (e - s > 1ll) {
    long long mid = (s + e) / 2ll;
    if (cnt(l, r, mid) >= k)
      s = mid;
    else
      e = mid;
  }
  s++;
  cerr << s << " " << ans << " " << ans - s << endl;
  cerr << l % s << " " << r % s << endl;
  cerr << l % ans << " " << r % ans << endl;
  cerr << cnt(l, r, s) << " " << cnt(l, r, ans) << endl;
  cout << fib(max(s, ans)) << endl;
  return 0;
}
