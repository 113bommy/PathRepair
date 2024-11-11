#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(long long n) {
  if (n == 0) return false;
  return (ceil(log2(n)) == floor(log2(n)));
}
long long power(long long x, unsigned long long y, long long m) {
  long long res = 1;
  x = x;
  while (y > 0) {
    if (y & 1) res = (res * x) % m;
    y = y >> 1;
    x = (x * x) % m;
  }
  return res % m;
}
bool isprime(long long x) {
  if (x < 2) return false;
  for (long long i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}
vector<long long> primeFactors(long long n) {
  vector<long long> v;
  long long x = 0;
  while (n % 2 == 0) {
    x++;
    n = n / 2;
    v.push_back(2);
  }
  for (long long i = 3; i <= sqrt(n); i = i + 2) {
    long long y = 0;
    while (n % i == 0) {
      y++;
      n = n / i;
      v.push_back(i);
    }
  }
  if (n > 2) v.push_back(n);
  return v;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  long long a[n][m];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) cin >> a[i][j];
  }
  map<long long, vector<long long>> mp;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      mp[(i + j)].push_back(a[i][j]);
    }
  }
  long long x = m + n - 2;
  long long ans = 0;
  for (long long i = 0; i < (x + 1) / 2; i++) {
    vector<long long> v = mp[i];
    vector<long long> u = mp[x - i];
    long long p = 0, q = 0;
    for (long long j = 0; j < v.size(); j++) {
      if (v[j] == 0)
        p++;
      else
        q++;
    }
    for (long long j = 0; j < u.size(); j++) {
      if (u[j] == 0)
        p++;
      else
        q++;
    }
    ans += min(p, q);
  }
  cout << ans << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
