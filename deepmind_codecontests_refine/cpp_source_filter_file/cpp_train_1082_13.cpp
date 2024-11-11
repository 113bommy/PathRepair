#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector<long long> p, r, pp, rr;
inline bool ok(long long x) {
  long long cnt = 0, o = pp.back();
  pp.pop_back();
  if (rr.empty()) return true;
  if (o + x < rr.back()) return false;
  if (o < rr.back()) {
    long long y = rr.back() - o;
    cnt = max((x - y) / 2LL, x - 2LL * y);
  } else
    cnt = x;
  while (!rr.empty() && rr.back() >= o - cnt) rr.pop_back();
  return true;
}
inline bool solve(long long x) {
  pp = p, rr = r;
  while (!pp.empty())
    if (!ok(x)) return false;
  if (rr.empty()) return true;
  return false;
}
int main() {
  int x;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> x, p.push_back(x);
  for (int i = 0; i < m; i++) cin >> x, r.push_back(x);
  long long s = -1, e = 1e10 + 1;
  while ((e - s) > 1) {
    long long mid = (e + s) / 2;
    if (solve(mid))
      e = mid;
    else
      s = mid;
  }
  cout << e << endl;
}
