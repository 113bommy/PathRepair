#include <bits/stdc++.h>
const long double PI = acos(-1);
const long double eps = 0.0000000001;
const long long INF = 0x3fffffffffffffff;
long long n, m, v[505][505], lm[505], rm[505], d[505], lst[505], matchl[505],
    matchr[505];
bool visl[505], visr[505];
char c1[2000005], c2[2000005];
std::string to = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
void Match(long long now) {
  static long long tmp;
  while (now) {
    tmp = matchl[lst[now]];
    matchl[lst[now]] = now;
    matchr[now] = lst[now];
    now = tmp;
  }
}
void bfs(long long s) {
  std::fill(visl + 1, visl + 1 + n, false);
  std::fill(visr + 1, visr + 1 + n, false);
  std::fill(d + 1, d + 1 + n, INF);
  std::queue<long long> que;
  que.push(s);
  while (true) {
    while (!que.empty()) {
      long long now = que.front();
      que.pop();
      visl[now] = true;
      for (long long i = 1; i <= n; ++i)
        if (!visr[i] && lm[now] + rm[i] - v[now][i] < d[i]) {
          d[i] = lm[now] + rm[i] - v[now][i];
          lst[i] = now;
          if (!d[i]) {
            visr[i] = true;
            if (!matchr[i])
              return Match(i);
            else
              que.push(matchr[i]);
          }
        }
    }
    long long down = INF;
    for (long long i = 1; i <= n; ++i)
      if (!visr[i]) down = std::min(down, d[i]);
    for (long long i = 1; i <= n; ++i) {
      if (visl[i]) lm[i] -= down;
      if (visr[i])
        rm[i] += down;
      else
        d[i] -= down;
    }
    for (long long i = 1; i <= n; ++i)
      if (!visr[i] && !d[i]) {
        visr[i] = true;
        if (!matchr[i])
          return Match(i);
        else
          que.push(matchr[i]);
      }
  }
}
long long KM() {
  for (long long i = 1; i <= n; ++i)
    lm[i] = *std::max_element(v[i] + 1, v[i] + 1 + n);
  for (long long i = 1; i <= n; ++i) {
    bfs(i);
  }
  long long res = 0;
  for (long long i = 1; i <= n; ++i) {
    res += lm[i] + rm[i];
  }
  return res;
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin >> m >> n;
  for (long long i = 1; i <= n; ++i)
    for (long long j = 1; j <= n; ++j) v[i][j] = 0;
  for (long long i = 1; i <= m; ++i) std::cin >> c1[i];
  for (long long i = 1; i <= m; ++i) std::cin >> c2[i];
  for (long long i = 1; i <= m; ++i)
    ++v[to.find(c1[i]) + 1][to.find(c2[i]) + 1];
  std::cout << KM() << std::endl;
  for (long long i = 1; i <= n; ++i) std::cout << to[matchl[i] - 1];
  std::cout << std::endl;
  return 0;
}
