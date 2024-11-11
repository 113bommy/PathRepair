#include <bits/stdc++.h>
using namespace std;
char s[5][105][105];
char m[3][105][105];
int ans[3][5];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= 10; j++) {
      for (int k = 1; k <= 10; k++) {
        if ((i + j + k) % 2 == 1) {
          m[i][j][k] = '1';
        } else
          m[i][j][k] = '0';
      }
    }
  }
  memset(ans, 0, sizeof(ans));
  cin >> n;
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        cin >> s[i][j][k];
      }
    }
  }
  for (int i = 1; i <= 2; i++) {
    for (int j = 1; j <= 4; j++) {
      for (int k = 1; k <= n; k++) {
        for (int r = 1; r <= n; r++) {
          if (s[j][k][r] != m[i][k][r]) {
            ans[i][j]++;
          }
        }
      }
    }
  }
  int result = 1e6;
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      if (i == j) continue;
      for (int k = 1; k <= 4; k++) {
        if (i == k || j == k) continue;
        result = min(
            result, ans[1][i] + ans[1][j] + ans[2][k] + ans[2][10 - i - j - k]);
      }
    }
  }
  cout << result << endl;
  return 0;
}
