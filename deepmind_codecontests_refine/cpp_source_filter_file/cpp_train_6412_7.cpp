#include <bits/stdc++.h>
using namespace std;
const long long N = 500000 + 5;
const long long M = 10000 + 5;
const long long mod = 1e9 + 7;
const long long inf = 1e9;
inline long long read() {
  long long s = 0;
  register bool neg = 0;
  register char c = getchar();
  for (; c < '0' || c > '9'; c = getchar()) neg |= (c == '-');
  for (; c >= '0' && c <= '9'; s = s * 10 + (c ^ 48), c = getchar())
    ;
  s = (neg ? -s : s);
  return s;
}
long long a, b, s1[N], s2[N], ans = inf;
inline bool check(long long n) {
  priority_queue<pair<long long, long long>,
                 vector<pair<long long, long long> >,
                 greater<pair<long long, long long> > >
      qu;
  long long res = 0, tmp = 0;
  for (long long i = (1); i <= (a); ++i) {
    qu.push(make_pair(s1[i] - n, 1));
    pair<long long, long long> top = qu.top();
    if (top.first + s2[i] < 0) {
      qu.pop();
      qu.push(make_pair(-s2[i], 0));
      res += top.second;
      tmp += top.first + s2[i];
    }
  }
  if (res == b) ans = min(ans, n * b + tmp);
  return res >= b;
}
signed main() {
  a = read();
  b = read();
  for (long long i = (1); i <= (a); ++i) s1[i] = read();
  for (long long i = (1); i <= (a); ++i) s2[i] = read();
  long long l = 1, r = inf;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%lld", ans);
  return 0;
}
