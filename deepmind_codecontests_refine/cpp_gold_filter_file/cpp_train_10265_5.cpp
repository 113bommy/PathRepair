#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int maxn = 100 + 10;
const int INF = 1 << 30;
const long long LINF = 1LL << 60;
const double PI = acos(-1.0);
const double eps(1e-8);
int dp[maxn][2];
int n, m;
char G[maxn][maxn];
inline bool allzero(char str[]) {
  for (int i = 0; i < strlen(str); i += 1) {
    if (str[i] == '1') {
      return false;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = n; i; i -= 1) {
    cin >> G[i];
  }
  dp[0][0] = 0;
  dp[0][1] = INF;
  while (allzero(G[n]) && n > 1) n -= 1;
  for (int i = 1; i < n; i += 1) {
    int l = m + 1, r = 0;
    for (int j = 1; j < m + 2; j += 1) {
      if (G[i][j] == '1') {
        l = min(l, j);
        r = max(r, j);
      }
    }
    dp[i][0] = min(m + 1 + dp[i - 1][1], dp[i - 1][0] + r * 2) + 1;
    dp[i][1] = min(dp[i - 1][0] + m + 1, dp[i - 1][1] + (m + 1 - l) * 2) + 1;
  }
  int l = m + 1, r = 0;
  for (int j = 1; j < m + 2; j += 1)
    if (G[n][j] == '1') {
      l = min(l, j);
      r = max(r, j);
    }
  cout << min(dp[n - 1][0] + r, dp[n - 1][1] + (m + 1 - l)) << endl;
  return 0;
}
