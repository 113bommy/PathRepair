#include <bits/stdc++.h>
using namespace std;
long long i, j, k, m, n, o, p, js, jl, jk, ans, pre, tim, x, y, r;
long long l[220000], t[220000];
queue<long long> q;
int main() {
  scanf("%lld%lld", &n, &r);
  ans = 0;
  pre = 0;
  tim = 0;
  for (int i = 1; i <= n; i++) scanf("%lld", &l[i]);
  for (int i = 1; i <= n; i++) scanf("%lld", &t[i]);
  for (int i = 1; i <= n; i++) {
    if (l[i] > t[i]) {
      printf("-1");
      exit(0);
    }
    if (pre >= l[i]) {
      pre -= l[i];
      tim += l[i];
      continue;
    }
    l[i] -= pre;
    t[i] -= pre;
    tim += pre;
    pre = 0;
    if (l[i] * 2 <= t[i]) {
      tim += l[i] * 2;
      continue;
    }
    x = t[i] - l[i];
    y = l[i] - x;
    tim += 2 * x;
    ans += y / r;
    if (ans < 100000)
      for (int j = 1; j <= y / r; j++) {
        q.push(tim);
        tim += r;
      }
    if (y % r != 0) {
      ans++;
      pre = r - y % r;
      if (ans < 100000) q.push(tim);
      tim += y % r;
    }
  }
  printf("%lld\n", ans);
  if (ans <= 100000)
    for (int i = 1; i <= ans; i++) {
      printf("%lld ", q.front());
      q.pop();
    }
  return 0;
}
