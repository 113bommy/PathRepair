#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 2e9;
const ll LLINF = 2e18;
const ld EPS = 1e-9;
int m, n, k, ans, cnt, x, y, l, r, q, c, x1, yy1, x2, yy2, t, s;
int light[105][105][10], cur[10];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q >> c;
  for (int i = 0; i < n; i++) {
    cin >> x1 >> yy1 >> s;
    light[x1][yy1][s]++;
  }
  for (int i = 0; i < 101; i++) {
    for (int j = 0; j < 101; j++) {
      for (int k = 0; k < 10; k++) {
        light[i][j][k] +=
            light[i - 1][j][k] + light[i][j - 1][k] - light[i - 1][j - 1][k];
      }
    }
  }
  for (int i = 0; i < q; i++) {
    cin >> t >> x1 >> yy1 >> x2 >> yy2;
    ans = 0;
    for (int k = 0; k < 10; k++) {
      cur[k] = light[x2][yy2][k] - light[x1 - 1][yy2][k] -
               light[x2][yy1 - 1][k] + light[x1 - 1][yy1 - 1][k];
      ans += (k + t) % (c + 1) * cur[k];
    }
    cout << ans << '\n';
  }
  return 0;
}
