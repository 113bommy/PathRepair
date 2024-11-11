#include <bits/stdc++.h>
using namespace std;
bool dp[301][301][301];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, n1, n2, n3;
  cin >> n;
  if (n == 1) {
    cin >> n1;
    cout << (n1 ? "BitLGM" : "BitAryo") << "\n";
  } else if (n == 2) {
    cin >> n1 >> n2;
    for (int i = 0; i < 301; i++) {
      for (int j = 0; j < 301; j++) {
        if (!dp[i][j][0]) {
          for (int k = 1; k < 301; k++) {
            if (i + k < 301) dp[i + k][j][0] = true;
            if (j + k < 301) dp[i][j + k][0] = true;
            if (i + k < 301 && j + k < 301) dp[i + k][j + k][0] = true;
          }
        }
      }
    }
    cout << (dp[n1][n2][0] ? "BitLGM" : "BitAryo") << "\n";
  }
  if (n == 3) {
    cin >> n1 >> n2 >> n3;
    for (int i = 0; i < 301; i++) {
      for (int j = 0; j < 301; j++) {
        for (int k = 0; k < 301; k++) {
          if (!dp[i][j][k]) {
            for (int l = 0; l < 301; l++) {
              if (i + l < 301) dp[i + l][j][k] = true;
              if (j + l < 301) dp[i][j + l][k] = true;
              if (k + l < 301) dp[i][j][k + l] = true;
              if (i + l < 301 && j + l < 301 && k + l < 301)
                dp[i + l][j + l][k + l] = true;
            }
          }
        }
      }
    }
    cout << (dp[n1][n2][n3] ? "BitLGM" : "BitAryo") << "\n";
  }
  return 0;
}
