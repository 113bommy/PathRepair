#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 150, INFi = 1e9 + 123, MOD = 1e9 + 7, KEY = 1001;
const long long INFl = 1e18 + 123;
const double EPS = 0.00000001, INFd = 1e18 + 1234.9;
template <typename T>
inline T sqr(T t) {
  return t * t;
}
inline void file() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
string a, b, res;
int n, m, k, cost[M][M], ans;
char xx, yy;
inline void no() {
  cout << -1;
  exit(0);
}
int main() {
  file();
  for (int i = 0; i < M; i++)
    for (int j = 0; j < M; j++) cost[i][j] = INFi;
  cin >> a >> b;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> xx >> yy >> k;
    cost[xx][yy] = min(cost[xx][yy], k);
  }
  for (int k = 'a'; k <= 'z'; k++)
    for (int i = 'a'; i <= 'z'; i++)
      for (int j = 'a'; j <= 'z'; j++)
        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
  if (a.size() != b.size()) no();
  for (int i = 0; i < a.size(); i++)
    if (a[i] != b[i]) {
      int c = INFi;
      for (int j = 'a'; j <= 'z'; j++) {
        int pr = 0;
        if (j != a[i]) pr += cost[a[i]][j];
        if (j != b[i]) pr += cost[b[i]][j];
        if (c > pr) {
          c = pr;
          xx = j;
        }
      }
      if (c == INFi) no();
      ans += c;
      res += xx;
    } else
      res += a[i];
  cout << ans << "\n" << res;
}
