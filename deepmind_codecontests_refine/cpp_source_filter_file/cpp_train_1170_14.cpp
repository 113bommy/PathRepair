#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500100, MAXK = 23;
const long long MOD = 998244353;
const long long INF = 1e18 + 1;
const long double PI = asin(1) * 2;
void setIO() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
}
void setIO(string second) {
  setIO();
  freopen((second + ".in").c_str(), "r", stdin);
  freopen((second + ".out").c_str(), "w", stdout);
}
bool grid[110][110];
int main() {
  setIO();
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    int x, y;
    cin >> n >> m >> x >> y;
    y = min(y, 2 * x);
    for (int i = (1); i <= (n); i++)
      for (int j = (1); j <= (m); j++) {
        char c;
        cin >> c;
        grid[i][j] = (c == '.');
      }
    int ans = 0;
    for (int i = (1); i <= (n); i++)
      for (int j = (1); j <= (m); j++) {
        if (grid[i][j]) {
          if (j < m && grid[i][j + 1]) {
            ans += y;
            grid[i][j + 1] = false;
          } else
            ans += x;
        }
      }
    cout << ans << "\n";
  }
  return 0;
}
