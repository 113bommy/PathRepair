#include <bits/stdc++.h>
using namespace std;
struct line {
  long long k = 0, m = 0;
  line(){};
  line(long long a, long long b) { k = a, m = b; }
};
const long long inf = 1e18;
long double cross(line a, line b) {
  if (a.k == b.k)
    return -inf;
  else {
    return (b.m - a.m + 0.0) / (a.k - b.k + 0.0);
  }
}
vector<long double> pr;
vector<line> lines;
long long get(long long x) {
  long long l = 0, r = pr.size();
  while (r - l > 1) {
    long long m = (l + r) / 2;
    if (pr[m] <= x)
      l = m;
    else
      r = m;
  }
  return lines[l].k * x + lines[l].m;
}
void upd(line l) {
  while (!lines.empty() &&
         l.k * pr.back() + l.m < lines.back().k * pr.back() + lines.back().m) {
    lines.pop_back();
    pr.pop_back();
  }
  long long coord;
  if (lines.empty()) {
    coord = -inf;
  } else {
    coord = cross(l, lines.back());
  }
  pr.push_back(coord);
  lines.push_back(l);
}
int32_t main() {
  long long n;
  cin >> n;
  vector<long long> a(n), b(n), dp(n);
  for (long long& i : a) cin >> i;
  for (long long& i : b) cin >> i;
  upd(line(b[0], dp[0]));
  for (long long i = 1; i < n; ++i) {
    dp[i] = get(a[i]);
    upd(line(b[i], dp[i]));
  }
  cout << dp.back();
}
