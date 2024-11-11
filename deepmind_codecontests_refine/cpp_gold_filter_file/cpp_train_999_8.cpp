#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int INF = 1e9;
vector<unordered_map<int, int> > fw;
int n, q;
int main() {
  iostream::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<int> dp[2];
  const int MX = 500 + 1;
  for (int i = 0; i < 2; i++) dp[i].resize(MX, 1e9);
  dp[0][0] = 0;
  int p = 1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x /= 100;
    int a = x / 10;
    for (int j = 0; j < MX; j++) {
      if (j + x / 10 < MX) {
        dp[p][j + a] = min(dp[p][j + a], dp[p ^ 1][j] + x);
      }
      if (j <= x)
        dp[p][0] = min(dp[p][0], dp[p ^ 1][j] + x - j);
      else
        dp[p][j - x] = min(dp[p][j - x], dp[p ^ 1][j] + 0);
    }
    p ^= 1;
    for (int i = 0; i < MX; i++) dp[p][i] = 1e9;
  }
  int ans = 1e9;
  for (int i : dp[p ^ 1]) ans = min(ans, i);
  cout << ans * 100;
  return 0;
}
