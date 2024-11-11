#include <bits/stdc++.h>
using namespace std;
map<pair<long long, int>, pair<long long, int> > f;
pair<long long, int> solve(long long n, int mx) {
  if (n == 0) return make_pair(0, 0);
  if (n < 10) {
    pair<long long, int> ans = make_pair(1, 0);
    if (n < mx) ans.second = n - mx;
    return ans;
  }
  pair<long long, int> now = make_pair(n, mx);
  if (f.find(now) != f.end()) return f[now];
  long long t = 1;
  while (t <= n / 10) t *= 10;
  pair<long long, int> ans = make_pair(0, 0);
  while (true) {
    int nx = mx;
    int d = n / t;
    if (d > nx) nx = d;
    pair<long long, int> x = solve(n % t, nx);
    ans.first += x.first;
    n -= n % t;
    if (x.second < 0)
      n += x.second;
    else {
      n -= nx;
      if (nx > 0) ans.first++;
    }
    if (d == 0) break;
  }
  ans.second = n;
  f[now] = ans;
  return ans;
}
int main() {
  long long n;
  scanf("%I64d", &n);
  pair<long long, int> ans = solve(n, 0);
  printf("%I64d\n", ans.first);
  return 0;
}
