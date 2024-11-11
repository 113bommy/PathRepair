#include <bits/stdc++.h>
using namespace std;
long long const INF = INT_MAX;
const long long MOD = 1e9 + 7;
const int N = 200004;
void SpeedForce() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int simple(int n) {
  int i, sq;
  if (n % 2 == 0) {
    return 0;
  }
  sq = (int)sqrt(n);
  for (i = 3; i <= sq; i++) {
    if ((n % i) == 0) {
      return 0;
    }
  }
  return 1;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long is_prime(long long n) {
  if (n <= 1 || n > 3 && (n % 2 == 0 || n % 3 == 0)) return 0;
  for (long long i = 5, t = 2; i * i <= n; i += t, t = 6 - t)
    if (n % i == 0) return 0;
  return 1;
}
long long binpow(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2) {
      res = (res * x) % MOD;
    }
    x = (x * x) % MOD;
    n /= 2;
  }
  return res;
}
string a, s;
long long n, m, i, j, x, y, l, r, mid, ans;
long long f[N], b[N];
void solve() {
  cin >> a >> s;
  n = a.length();
  m = s.length();
  j = 0;
  ans = 0;
  for (i = 0; i < n; i++) {
    if (i)
      f[i] = f[i - 1];
    else
      f[i] = 0;
    if (j < m && a[i] == s[j]) {
      j++;
      f[i]++;
      if (f[i] == m) ans = max(ans, n - 1 - i);
    }
  }
  j = m - 1;
  for (i = n - 1; i >= 0; i--) {
    if (i != n - 1)
      b[i] = b[i + 1];
    else
      b[i] = 0;
    if (j >= 0 && a[i] == s[j]) {
      j--;
      b[i]++;
      if (b[i] == m) ans = max(ans, i);
    }
  }
  for (i = 0; i < n; i++) {
    x = m - f[i];
    l = i + 1;
    r = n - 1;
    y = -1;
    while (l <= r) {
      mid = (l + r) / 2;
      if (b[mid] >= x) {
        y = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    if (y != -1) ans = max(ans, y - 1 - i);
  }
  cout << ans;
}
int main() {
  SpeedForce();
  int T = 1;
  while (T--) {
    solve();
  }
}
