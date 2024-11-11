#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long n, k, a, b;
pair<long long, long long> solve(long long s, long long t) {
  long long mn = 100000000000, mx = 0;
  for (long long i = 0; i < n; i++) {
    long long tt = (t + i * k) % (n * k);
    long long l = tt - s;
    if (l < 0) l += n * k;
    long long g = gcd(n * k, l);
    mn = min(mn, n * k / g);
    mx = max(mx, n * k / g);
  }
  return make_pair(mn, mx);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k >> a >> b;
  auto v1 = solve(a, b);
  auto v2 = solve(k - a, b);
  auto v3 = solve(k - a, k - b);
  auto v4 = solve(a, k - b);
  vector<long long> vec1 = {v1.first, v2.first, v3.first, v4.first};
  vector<long long> vec2 = {v1.second, v2.second, v3.second, v4.second};
  cout << *min_element(vec1.begin(), vec1.end()) << ' '
       << *max_element(vec2.begin(), vec2.end());
  return 0;
}
