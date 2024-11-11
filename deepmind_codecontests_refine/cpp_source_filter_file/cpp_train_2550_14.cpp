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
const long long mods = 1e9 + 7;
const long long inv2 = (mods + 1) >> 1;
const long long MAXN = 200005;
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
pair<long long, long long> a[MAXN];
queue<pair<long long, long long> > que;
long long dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
long long dy[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
long long f[2050][2050], num[505];
long long get(long long l, long long n, long long d) {
  n %= mods;
  long long r = l + (n - 1) * d;
  return (l + r) * n % mods * inv2 % mods;
}
signed main() {
  long long n = read() + 1, m = read();
  for (long long i = 1, x, y; i <= m; i++)
    x = read(), y = read(), f[x + 1010][y + 1010] = INF;
  que.push(make_pair(1010, 1010)), f[1010][1010] = 1, num[1] = 1;
  while (!que.empty()) {
    pair<long long, long long> q = que.front();
    que.pop();
    if (f[q.first][q.second] > 500) break;
    for (long long i = 0; i < 8; i++) {
      pair<long long, long long> p =
          make_pair(q.first + dx[i], q.second + dy[i]);
      if (f[p.first][p.second]) continue;
      f[p.first][p.second] = f[q.first][q.second] + 1;
      num[f[p.first][p.second]]++;
      que.push(p);
    }
  }
  long long ans = 0;
  for (long long i = 1; i <= min(n, 499ll); i++) ans += num[i];
  if (n <= 499)
    printf("%lld\n", ans);
  else
    printf("%lld\n",
           (ans + get(num[500], n - 499, num[500] - num[499])) % mods);
  return 0;
}
