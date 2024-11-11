#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long n, m;
long long mult(long long x, long long y) {
  x %= mod;
  y %= mod;
  long long gun = x * y;
  if (gun >= mod) gun %= mod;
  return gun;
}
long long add(long long x, long long y) {
  long long now = x + y;
  if (now >= mod) now %= mod;
  return now;
}
long long sub(long long x, long long y) {
  long long now = x - y;
  if (now < 0) now %= mod;
  if (now < 0) now += mod;
  return now;
}
long long calc(long long low, long long high) {
  if (low > m) return 0;
  high = min(high, m);
  long long now, now2;
  if (high % 2) {
    now = mult(high, (high + 1) / 2);
  } else {
    now = mult(high / 2, high + 1);
  }
  if (low % 2) {
    now2 = mult(low, (low + 1) / 2);
  } else {
    now2 = mult(low / 2, low + 1);
  }
  long long ans = sub(now, now2);
  return ans;
}
int main() {
  long long i, j, k, x, y;
  long long ans = 0;
  cin >> n >> m;
  if (n == 1) {
    cout << m - 1 << endl;
    return 0;
  }
  ans += mult(n, m);
  ans = sub(ans, n);
  for (i = 2; i <= sqrt(n) + 1 && i <= m; i++) {
    long long now = n / i;
    now = mult(now, i);
    if (n / i <= i) now = 0;
    ans = sub(ans, now);
    long long low = n / i;
    long long high = n / (i - 1);
    long long now2 = calc(low, high);
    now2 = mult(now2, i - 1);
    ans = sub(ans, now2);
  }
  cout << ans << endl;
  return 0;
}
