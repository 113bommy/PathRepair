#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, K;
  cin >> n >> K;
  bool dp[n + 1][K + 1];
  memset(dp, false, sizeof(dp[0][0]) * (n + 1) * (K + 1));
  string a[n + 1];
  string b[10];
  b[0] = "1110111";
  b[1] = "0010010";
  b[2] = "1011101";
  b[3] = "1011011";
  b[4] = "0111010";
  b[5] = "1101011";
  b[6] = "1101111";
  b[7] = "1010010";
  b[8] = "1111111";
  b[9] = "1111011";
  for (int i = 0; i < n; i++) cin >> a[n - i];
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 10; j++) {
      int p = 0;
      for (int k = 0; k < 7; k++)
        if (a[i][k] == b[j][k]) p++;
      if (p == 7 && i == 1) {
        dp[i][0] = true;
        break;
      } else if (p == 7 && dp[i - 1][0] != false) {
        dp[i][0] = true;
      }
    }
  }
  for (int i = 0; i <= K; i++) {
    for (int j = 0; j < 10; j++) {
      int p = 0, q = 0;
      for (int k = 0; k < 7; k++) {
        if (a[1][k] == b[j][k])
          continue;
        else if (a[1][k] == '0' && b[j][k] == '1')
          p++;
        else {
          q++;
          break;
        }
      }
      if (p == i && q == 0) {
        dp[1][i] = true;
        break;
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= K; j++) {
      for (int J = 9; J >= 0; J--) {
        int p = 0, q = 0;
        for (int k = 0; k < 7; k++) {
          if (a[i][k] == b[J][k])
            continue;
          else if (a[i][k] == '0' && b[J][k] == '1')
            p++;
          else {
            q++;
            break;
          }
        }
        if ((p <= j && q == 0) && dp[i - 1][j - p]) {
          dp[i][j] = true;
          break;
        }
      }
    }
  }
  if (dp[n][K] == false)
    cout << "-1";
  else {
    int u = K;
    string ans = "";
    for (int i = n; i >= 1; i--) {
      for (int j = 9; j >= 0; j--) {
        int p = 0, q = 0, e = 0;
        for (int k = 0; k < 7; k++) {
          if (a[i][k] == b[j][k])
            continue;
          else if (a[1][k] == '0' && b[j][k] == '1')
            p++;
          else {
            q++;
            break;
          }
        }
        if (u >= p) {
          if ((dp[i - 1][u - p] || ((i == 1) && (u == p))) && q == 0) {
            ans += char(j + 48);
            e++;
            u -= p;
            break;
          }
          if (e > 0) break;
        }
      }
    }
    cout << ans;
  }
}
