#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 8;
const int MOD = 1e9 + 7;
int n, m, dp[2][N][N];
char s[N][N];
void Enter() {
  cin >> m >> n;
  for (int i = (1), _b = (m); i <= _b; ++i) cin >> (s[i] + 1);
}
inline bool inY(int y) { return y <= n && y >= 1; }
inline bool inX(int x) { return x <= m && x >= 1; }
inline void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
void Process() {
  int step = (n + m) / 2;
  for (int x = (1), _b = (m); x <= _b; ++x) {
    int y = step + 1 - x;
    if (!inY(y)) continue;
    for (int u = (1), _b = (m); u <= _b; ++u) {
      int v = m + n - u + 1 - step;
      if (inY(v) && abs(x - u) + abs(y - v) < 2 && s[x][y] == s[u][v]) {
        dp[step & 1][x][u] = 1;
      }
    }
  }
  for (int step = ((n + m) / 2), _b = (2); step >= _b; --step) {
    int z = step & 1;
    for (int x = (0), _b = (m); x <= _b; ++x)
      for (int y = (0), _b = (m); y <= _b; ++y) {
        dp[z ^ 1][x][y] = 0;
      }
    for (int x = (1), _b = (m); x <= _b; ++x) {
      int y = step + 1 - x;
      if (!inY(y)) continue;
      for (int u = (1), _b = (m); u <= _b; ++u) {
        int v = m + n - u + 1 - step;
        if (!inY(v)) continue;
        if (s[x - 1][y] == s[u + 1][v])
          add(dp[z ^ 1][x - 1][u + 1], dp[z][x][u]);
        if (s[x - 1][y] == s[u][v + 1]) add(dp[z ^ 1][x - 1][u], dp[z][x][u]);
        if (s[x][y - 1] == s[u + 1][v]) add(dp[z ^ 1][x][u + 1], dp[z][x][u]);
        if (s[x][y - 1] == s[u][v + 1]) add(dp[z ^ 1][x][u], dp[z][x][u]);
        if (step == 2) {
          cerr << "x _ y _ u _ v _ dp[z ^ 1][1][m]"
               << " = " << x << "," << y << "," << u << "," << v << ","
               << dp[z ^ 1][1][m] << '\n';
        }
      }
    }
  }
  cout << dp[1][1][m] << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  Enter();
  Process();
  return 0;
}
