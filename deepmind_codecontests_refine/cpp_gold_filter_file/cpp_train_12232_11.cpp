#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const long double eps = 1e-11;
const long double pi = acos(-1);
const long long oo = 1 << 30;
const long long loo = 1ll << 62;
const long long MAXN = 810005;
const long long INF = 0x3f3f3f3f;
inline long long read() {
  long long f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
pair<long long, long long> p[MAXN], q[MAXN], stk[MAXN];
long long check(pair<long long, long long> x, pair<long long, long long> y) {
  if (x.first && x.second && y.first && y.second &&
      x.first * y.second == x.second * y.first)
    return x.first < y.first;
  else
    return 0;
}
long long cross(pair<long long, long long> x, pair<long long, long long> y,
                pair<long long, long long> z) {
  return (y.first - x.first) * (z.second - x.second) -
         (y.second - x.second) * (z.first - x.first);
}
signed main() {
  long long n = read(), m = read();
  read(), read();
  pair<long long, long long> mx = make_pair(0, 0), o = make_pair(0, 0);
  for (long long i = 1; i <= n; i++) q[i].first = read(), q[i].second = read();
  for (long long i = 1; i <= m; i++)
    p[i].first = read(), p[i].second = read(), upmax(mx.first, p[i].first),
    upmax(mx.second, p[i].second);
  p[++m] = make_pair(mx.first, 0), p[++m] = make_pair(0, mx.second);
  sort(p + 1, p + m + 1,
       [&](pair<long long, long long> x, pair<long long, long long> y) {
         return cross(o, x, y) > 0;
       });
  sort(q + 1, q + n + 1,
       [&](pair<long long, long long> x, pair<long long, long long> y) {
         return cross(o, x, y) > 0;
       });
  long long top = 0;
  for (long long i = 1; i <= m; i++) {
    while (top > 1 &&
           (cross(stk[top - 1], stk[top], p[i]) < 0 || check(stk[top], p[i])))
      top--;
    stk[++top] = p[i];
  }
  for (long long i = 1, nw = 1; i <= n; i++) {
    while (cross(o, q[i], stk[nw]) < 0) nw++;
    if (cross(o, q[i], stk[nw]) + cross(o, stk[nw - 1], q[i]) >=
        cross(o, stk[nw - 1], stk[nw])) {
      puts("Max");
      return 0;
    }
  }
  puts("Min");
  return 0;
}
