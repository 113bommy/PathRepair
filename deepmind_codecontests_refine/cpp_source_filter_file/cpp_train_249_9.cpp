#include <bits/stdc++.h>
using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
const int N = 1e5 + 13;
const int INF = 1e9;
const int MAXA = 10011;
const int MAXB = 32;
int dp[MAXA][MAXB];
vector<pii> g[MAXA][MAXB];
void dfs(int a, int b) {
  if (dp[a][b] != 0) return;
  int mx = 1;
  for (auto p : g[a][b]) {
    dfs(p.first, p.second);
    mx = max(mx, dp[p.first][p.second]);
  }
  dp[a][b] = 4 - mx;
}
int main() {
  int a, b, n;
  cin >> a >> b >> n;
  dp[1][MAXB - 1] = 2;
  dp[MAXA - 1][1] = ((n - MAXA + 1) % 2 != 0 ? 1 : 3);
  for (int i = 0; i < MAXA; i++) {
    for (int j = 0; j < MAXB; j++) {
      li pw = 1;
      for (int l = 0; l < j; l++) {
        pw *= i;
        if (pw >= n) {
          dp[i][j] = 1;
          break;
        }
      }
      if (i < MAXA - 1) {
        g[i][j].emplace_back(i + 1, j);
      }
      if (j < MAXB - 1) {
        g[i][j].emplace_back(i, j + 1);
      }
    }
  }
  dfs(a, b);
  if (dp[a][b] == 3)
    cout << "Stas";
  else if (dp[a][b] == 1)
    cout << "Masha";
  else
    cout << "Missing";
}
