#include <bits/stdc++.h>
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long int N = 5e3 + 30, mod = 1e9 + 7, inf = 1e9;
string a[N], b[N];
int dp[N][30][30];
pair<int, int> par[N][30][30];
int main() {
  int n, m, ans = inf, I, J;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < 30; j++)
      for (int k = 0; k < 30; k++) dp[i][j][k] = 5e5;
  }
  char c, d;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      if (i == j) continue;
      c = char(int('a') + i);
      d = char(int('a') + j);
      int cnt = 0;
      for (int k = 0; k < m; k++) {
        if ((k % 2 && a[0][k] != d) || (k % 2 == 0 && a[0][k] != c)) {
          cnt++;
        }
      }
      dp[0][i][j] = cnt;
      if (n == 1) {
        if (dp[0][i][j] < ans) {
          ans = dp[0][i][j];
          I = i;
          J = j;
        }
      }
    }
  }
  if (n == 1) {
    cout << ans << '\n';
    char c = char(int('a') + I);
    char d = char(int('a') + J);
    for (int i = 0; i < m; i++) {
      if (i % 2)
        cout << d;
      else
        cout << c;
    }
    return 0;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      for (int k = 0; k < 26; k++) {
        if (j == k) continue;
        for (int x = 0; x < 26; x++) {
          if (x == j) continue;
          for (int y = 0; y < 26; y++) {
            if (y == k) continue;
            if (dp[i][j][k] > dp[i - 1][x][y]) {
              dp[i][j][k] = dp[i - 1][x][y];
              par[i][j][k] = {x, y};
            }
          }
        }
        char c = char(int('a') + j), d = char(int('a') + k);
        for (int x = 0; x < m; x++) {
          if ((x % 2 && a[i][x] != d) || (x % 2 == 0 && a[i][x] != c)) {
            dp[i][j][k]++;
          }
        }
        if (i == n - 1) {
          if (ans > dp[i][j][k]) {
            ans = min(ans, dp[i][j][k]);
            I = j;
            J = k;
          }
        }
      }
    }
  }
  cout << ans << '\n';
  for (int i = n - 1; i >= 0; i--) {
    char c = char(int('a') + I);
    char d = char(int('a') + J);
    for (int j = 0; j < m; j++) {
      if (j % 2)
        b[i] += d;
      else
        b[i] += c;
    }
    int p = I;
    I = par[i][p][J].first;
    J = par[i][p][J].second;
  }
  for (int i = 0; i < n; i++) cout << b[i] << '\n';
}
