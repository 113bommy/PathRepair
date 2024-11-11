#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7, Base = 998244353;
const long long N = 507;
const long long INF = 1LL * 1000 * 1000 * 1000 * 1000 * 1000 * 1000 + 7LL;
const double pie = acos(-1.0);
const double EPS = 1e-9;
long long n, m, room[N][2], wallpaper[N][3], cost;
long long calco(long long i, long long j) {
  long long piece = wallpaper[j][0] / room[i][1], len;
  len = piece * wallpaper[j][1];
  return ((room[i][0] + len - 1) / len) * wallpaper[j][2];
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; ++i)
    cin >> room[i][0] >> room[i][1], room[i][0] += room[i][1],
        room[i][0] = room[i][0] << 1, cin >> room[i][1];
  cin >> m;
  for (long long i = 1; i <= m; ++i)
    cin >> wallpaper[i][0] >> wallpaper[i][1] >> wallpaper[i][2];
  for (long long i = 1, c; i <= n; ++i) {
    c = INF;
    for (long long j = 1; j <= m; ++j) {
      if (wallpaper[j][0] < room[i][1]) continue;
      c = min(c, calco(i, j));
    }
    cost += c;
  }
  cout << cost << '\n';
  return 0;
}
