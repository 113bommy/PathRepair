#include <bits/stdc++.h>
using namespace std;
long long spf[9];
long long fac[9];
void sieve() {
  spf[1] = 1;
  for (long long i = 2; i < 9; i++) spf[i] = i;
  for (long long i = 4; i < 9; i += 2) spf[i] = 2;
  for (long long i = 3; i * i < 9; i++) {
    if (spf[i] == i) {
      for (long long j = i * i; j < 9; j += i)
        if (spf[j] == j) spf[j] = i;
    }
  }
}
map<long long, long long> getfactor(long long a) {
  map<long long, long long> m;
  while (a > 1) {
    m[spf[a]]++;
    a /= spf[a];
  }
  return m;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long inverse(long long a, long long p) { return power(a, p - 2, p); }
long long ncr(long long n, long long r, long long p) {
  if (r == 0) return 1;
  return (fac[n] * inverse(fac[r], p) % p * inverse(fac[n - r], p) % p) % p;
}
void solve() {
  long long n, m;
  cin >> m >> n;
  pair<long long, long long> p[n + 1];
  p[0] = make_pair(0, 0);
  vector<long long> v(n + 1);
  v[0] = 0;
  long long maxi = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> p[i].second >> p[i].first;
    v[i] = p[i].second;
    maxi = max(p[i].first, maxi);
  }
  sort(v.begin(), v.end());
  long long pre[n + 1];
  memset(pre, 0, sizeof(pre));
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    pre[i] += pre[i - 1] + v[i];
  }
  if (m == 1) {
    cout << v[n] << '\n';
    return;
  }
  long long gg = 0;
  long long count = m - 2;
  for (long long i = 1; i <= n; i++) {
    long long sum = p[i].first + p[i].second;
    auto it = lower_bound(v.begin(), v.end(), p[i].first);
    if (it == v.end()) {
      sum += count * p[i].first;
      ans = max(sum, ans);
      continue;
    }
    long long k = it - v.begin();
    long long ind;
    if (count >= n - k + 1) {
      ind = k - 1;
      sum += (count - n + k - 1) * p[i].first;
    } else
      ind = n - count;
    sum += pre[n] - pre[ind];
    long long hh = lower_bound(v.begin(), v.end(), p[i].second) - v.begin();
    if (hh >= ind + 1) {
      sum -= p[i].second;
      if (v[ind] > p[i].first)
        sum += v[ind];
      else
        sum += p[i].first;
    }
    ans = max(sum, ans);
  }
  if (m <= n) ans = max(pre[n] - pre[n - m - 1], ans);
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
