#include <bits/stdc++.h>
using namespace std;
using vi = vector<long long>;
using vvi = vector<vi>;
using vs = vector<string>;
using pii = pair<long long, long long>;
using vpii = vector<pair<long long, long long>>;
const long long inf = 3e18;
const double eps = 1e-9;
long long n, m, k;
long long f(long long n) { return (1 + n) * n / 2; }
bool check(long long v) {
  long long cost = 0;
  cost += v;
  long long llen = k - 1, rlen = n - k;
  long long seglen = v - 1;
  long long lv = f(seglen), rv = f(seglen);
  if (seglen > llen) lv -= f(seglen - llen);
  if (seglen > rlen) rv -= f(seglen - rlen);
  if (seglen < llen) lv += llen - seglen;
  if (seglen < rlen) rv += rlen - seglen;
  cost += lv;
  cost += rv;
  return cost <= m;
}
signed main() {
  cin >> n >> m >> k;
  long long l = 0, r = 1e9 + 100;
  for (long long i = 0; i < 32; ++i) {
    long long mid = (l + r) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << l << endl;
}
