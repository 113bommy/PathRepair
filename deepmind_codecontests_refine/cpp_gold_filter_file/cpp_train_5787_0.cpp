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
const int oo = 1 << 30;
const long long loo = 1ll << 62;
const int mods = 1e9 + 7;
const int MAXN = 500005;
const int INF = 0x3f3f3f3f;
inline int read() {
  int f = 1, x = 0;
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
long long ans = 0;
int c[MAXN], w[MAXN], p[MAXN], flag[MAXN];
priority_queue<pair<int, int> > que;
signed main() {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++) c[i] = read(), p[i] = c[i] / 100, c[i] %= 100;
  for (int i = 1; i <= n; i++) w[i] = read();
  for (int i = 1; i <= n; i++) {
    if (c[i]) que.push(make_pair(-(100 - c[i]) * w[i], i));
    m -= c[i];
    if (m < 0)
      ans -= que.top().first, flag[que.top().second] = 1, que.pop(), m += 100;
  }
  printf("%lld\n", ans);
  for (int i = 1; i <= n; i++)
    if (flag[i])
      printf("%d 0\n", p[i] + 1);
    else
      printf("%d %d\n", p[i], c[i]);
  return 0;
}
