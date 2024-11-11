#include <bits/stdc++.h>
using namespace std;
int n, m;
int x;
bool dp[3001][3001];
int main() {
  cin >> n >> m;
  if (n > m) {
    cout << "YES";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> x;
    x = x % m;
    dp[i][x] = true;
    for (int j = 0; j < m; j++) {
      if (dp[i - 1][j] == true) {
        dp[i][j] = true;
        dp[i][(j + x) % m] = true;
      }
    }
    if (dp[i][0] == true) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
