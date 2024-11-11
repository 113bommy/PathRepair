#include <bits/stdc++.h>
const long double PI = acos(-1);
const long double eps = 0.0000000001;
const long long INF = 0x3fffffffffffffff;
const long long xx[] = {0, -1, 0, +1}, yy[] = {+1, 0, -1, 0};
long long n, m, belong[1605][1605], cnt, ans[2560005];
struct photo {
  bool c[1605][1605];
  bool *const operator[](const long long &x) { return c[x]; }
  const bool *const operator[](const long long &x) const { return c[x]; }
} d, e, f;
bool check(const photo &x, const bool &y, const long long &X,
           const long long &Y) {
  for (long long i = 0; i != 4; ++i)
    if (X + xx[i] >= 1 && X + xx[i] <= n && Y + yy[i] >= 1 && Y + yy[i] <= m &&
        x[X + xx[i]][Y + yy[i]] == y)
      return true;
  return false;
}
photo work(const photo &x, const bool &y) {
  photo res;
  for (long long i = 1; i <= n; ++i)
    for (long long j = 1; j <= m; ++j)
      if (check(x, y, i, j))
        res[i][j] = y;
      else
        res[i][j] = !y;
  return res;
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin >> n >> m;
  for (long long i = 1; i <= n; ++i)
    for (long long j = 1; j <= m; ++j) std::cin >> d[i][j];
  for (long long i = 1; i <= n; ++i)
    for (long long j = 1; j <= m; ++j)
      if (!belong[i][j] && d[i][j]) {
        belong[i][j] = ++cnt;
        std::queue<std::pair<long long, long long>> que;
        que.push(std::make_pair(i, j));
        while (!que.empty()) {
          std::pair<long long, long long> now = que.front();
          que.pop();
          for (long long i = 0; i != 4; ++i) {
            if (!belong[now.first + xx[i]][now.second + yy[i]] &&
                d[now.first + xx[i]][now.second + yy[i]]) {
              belong[now.first + xx[i]][now.second + yy[i]] = cnt;
              que.push(std::make_pair(now.first + xx[i], now.second + yy[i]));
            }
          }
        }
      }
  e = d;
  for (long long i = 1; i <= 3; ++i) e = work(e, false);
  for (long long i = 1; i <= 10; ++i) e = work(e, true);
  for (long long i = 1; i <= n; ++i)
    for (long long j = 1; j <= m; ++j) f[i][j] = d[i][j] && !e[i][j];
  for (long long i = 1; i <= n; ++i)
    for (long long j = 1; j <= m; ++j)
      if (f[i][j]) {
        long long siz = 0;
        std::queue<std::pair<long long, long long>> que;
        que.push(std::make_pair(i, j));
        while (!que.empty()) {
          std::pair<long long, long long> now = que.front();
          ++siz;
          que.pop();
          for (long long i = 0; i != 4; ++i) {
            if (f[now.first + xx[i]][now.second + yy[i]]) {
              f[now.first + xx[i]][now.second + yy[i]] = false;
              que.push(std::make_pair(now.first + xx[i], now.second + yy[i]));
            }
          }
        }
        if (siz > 10) ++ans[belong[i][j]];
      }
  std::sort(ans + 1, ans + 1 + cnt);
  std::cout << cnt << std::endl;
  for (long long i = 1; i <= cnt; ++i) std::cout << ans[i] << " \n"[i == cnt];
  return 0;
}
