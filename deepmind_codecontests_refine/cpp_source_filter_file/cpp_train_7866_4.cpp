#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 100;
long long a[N], m, n, b[N];
set<long long> s;
bool check(long long* a, long long n, long long l) {
  long long x = a[0];
  s.clear();
  for (long long i = 0; i < n; i++) s.insert(a[i]);
  while (s.find((x - l + m) % m) != s.end()) {
    x = (x - l + m) % m;
  }
  long long f = x;
  while (s.find(x) != s.end()) {
    s.erase(s.find(x));
    x = (x + l) % m;
  }
  if (s.empty()) {
    cout << f << " " << l << "\n";
    return true;
  }
  cout << "-1\n";
  return false;
}
long long tav(long long n, long long k, long long mod) {
  long long ans = 1;
  while (k > 0) {
    if (k % 2) ans = (ans + n) % mod;
    n = (n * 2) % mod;
    k >>= 1;
  }
  return ans;
}
long long solve(long long* a, long long n, long long l) {
  if (n == 1) return 1;
  s.clear();
  for (long long i = 0; i < n; i++) {
    s.insert(a[i]);
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    if (s.count((a[i] + l) % m)) ans++;
  }
  ans = n - ans;
  l = (l * tav(ans, m - 2, m)) % m;
  return l;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n;
  if (n == m) {
    cout << 0 << " " << 1 << "\n";
    return 0;
  }
  bool rev = false;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long sz = n;
  if (m - n < n) {
    rev = true;
    s.clear();
    for (long long i = 0; i < n; i++) {
      s.insert(a[i]);
      b[i] = a[i];
    }
    sz = 0;
    for (long long i = 0; i < m; i++) {
      if (!s.count(i)) a[sz++] = i;
    }
  }
  long long l = solve(a, sz, a[1] - a[0]);
  if (!rev)
    check(a, n, l);
  else
    check(b, n, l);
  return 0;
}
