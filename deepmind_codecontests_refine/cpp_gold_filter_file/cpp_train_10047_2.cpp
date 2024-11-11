#include <bits/stdc++.h>
const long double PI = acos(-1);
const long double eps = 0.0000000001;
const long long INF = 0x3fffffffffffffff;
long long n, m, p, lto[1005][1005], rto[1005][1005], ld[1005], rd[1005],
    f[100005], t[100005];
void connect(long long L, long long R, long long v) {
  lto[L][v] = R;
  rto[R][v] = L;
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin >> n >> m >> p;
  for (long long i = 1; i <= p; ++i) {
    std::cin >> f[i] >> t[i];
    ++ld[f[i]];
    ++rd[t[i]];
    long long a = std::find(lto[f[i]], lto[f[i]] + m, 0) - lto[f[i]];
    long long b = std::find(rto[t[i]], rto[t[i]] + n, 0) - rto[t[i]];
    std::vector<long long> way;
    way.push_back(t[i]);
    while (true)
      if (way.size() & 1) {
        if (!rto[way.back()][a]) break;
        way.push_back(rto[way.back()][a]);
      } else {
        if (!lto[way.back()][b]) break;
        way.push_back(lto[way.back()][b]);
      }
    for (long long j = 1; j < way.size(); ++j)
      if (j & 1)
        connect(way[j], way[j - 1], b);
      else
        connect(way[j - 1], way[j], a);
    if (way.size() & 1)
      rto[way.back()][b] = 0;
    else
      lto[way.back()][a] = 0;
    connect(f[i], t[i], a);
  }
  long long ans = std::max(*std::max_element(ld + 1, ld + 1 + n),
                           *std::max_element(rd + 1, rd + 1 + m));
  std::cout << ans << std::endl;
  for (long long i = 1; i <= p; ++i) {
    std::cout << std::find(lto[f[i]], lto[f[i]] + ans, t[i]) - lto[f[i]] + 1
              << " \n"[i == p];
  }
  return 0;
}
