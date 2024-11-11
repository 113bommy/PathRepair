#include <bits/stdc++.h>
using namespace std;
const long long N = 100005, xian = (long long)1500000 * 1500000;
long long q[N], ans[N], n;
pair<long long, long long> a[N];
inline long long cal(pair<long long, long long> x) {
  return x.first * x.first + x.second * x.second;
}
pair<long long, long long> solve(long long l, long long r) {
  if (l == r) return a[q[l]];
  long long mid = (l + r) >> 1;
  while (1) {
    random_shuffle(&q[l], &q[r + 1]);
    pair<long long, long long> t1 = solve(l, mid), t2 = solve(mid + 1, r);
    pair<long long, long long> t3 = make_pair(t1.first + t2.first,
                                              t1.second + t2.second),
                               t4 = make_pair(t1.first - t2.first,
                                              t1.second - t2.second);
    pair<long long, long long> t = cal(t3) < cal(t4) ? t3 : t4;
    if (cal(t) <= xian) return t;
  }
}
pair<long long, long long> sol(long long l, long long r) {
  if (l == r) return a[q[l]];
  long long mid = (l + r) >> 1;
  while (1) {
    pair<long long, long long> t1 = sol(l, mid), t2 = sol(mid + 1, r);
    pair<long long, long long> t3 = make_pair(t1.first + t2.first,
                                              t1.second + t2.second),
                               t4 = make_pair(t1.first - t2.first,
                                              t1.second - t2.second),
                               t;
    if (cal(t3) < cal(t4))
      t = t3;
    else {
      t = t4;
      ans[mid + 1] *= -1;
      ans[r + 1] *= -1;
    }
    if (cal(t) <= xian) return t;
  }
}
long long an[N];
signed main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld%lld", &a[i].first, &a[i].second);
    q[i] = i;
    ans[i] = 1;
  }
  solve(1, n);
  sol(1, n);
  ans[0] = 1;
  for (long long i = 1; i <= n; i++) ans[i] *= ans[i - 1];
  for (long long i = 1; i <= n; i++) an[q[i]] = ans[i];
  for (long long i = 1; i <= n; i++)
    if (an[i] == 1) {
      putchar('1');
      putchar(' ');
    } else {
      putchar('-');
      putchar('1');
      putchar(' ');
    }
}
