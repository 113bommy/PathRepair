#include <bits/stdc++.h>
using namespace std;
map<pair<long long, long long>, set<pair<long long, long long> > > all;
long long x[1005];
long long y[1005];
long long F(long long x, long long y) {
  if (y == 0) return x;
  return F(y, x % y);
}
int main() {
  long long N, i, ans = 0, t, j, a, b, t2, c, d;
  scanf("%lld", &N);
  for (i = 0; i < N; i++) scanf("%lld %lld", &x[i], &y[i]);
  for (i = 0; i < N; i++) {
    for (j = i + 1; j < N; j++) {
      if (x[i] == x[j])
        all[make_pair(0, 1)].insert(make_pair(0, x[i]));
      else if (y[i] == y[j])
        all[make_pair(1, 0)].insert(make_pair(y[i], 0));
      else {
        t = (x[i] - x[j]) * (y[i] - y[j]) / abs((x[i] - x[j])) /
            abs((y[i] - y[j]));
        a = (y[i] - y[j]);
        b = (x[i] - x[j]);
        t2 = F(abs(a), abs(b));
        a = abs(a) / t2 * t;
        b = abs(b) / t2;
        c = b * y[i] - a * x[i];
        d = b;
        if (c == 0)
          all[make_pair(a, b)].insert(make_pair(0, 1));
        else {
          t = c / abs(c);
          all[make_pair(a, b)].insert(
              make_pair(abs(c) / F(abs(c), d) * t, d / F(abs(c), d)));
        }
      }
    }
  }
  a = 0;
  for (auto i : all) {
    t = i.second.size();
    a += t;
    ans -= (t) * (t - 1) / 2;
  }
  ans += a * (a - 1) / 2;
  printf("%lld\n", ans);
  return 0;
}
