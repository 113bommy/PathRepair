#include <bits/stdc++.h>
using namespace std;
char cad[102];
char M[102][102];
int v[102][102];
int f, c, mod;
int dp[102][102][12];
string pred[102][102][12];
int main() {
  scanf("%d%d%d", &f, &c, &mod);
  mod++;
  for (int i = 0; i < (int)(f); ++i) {
    scanf("%s", M[i]);
  }
  for (int i = 0; i < (int)(f); ++i) {
    for (int j = 0; j < (int)(c); ++j) {
      v[i][j] = M[i][j] - '0';
    }
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < (int)(c); ++i) {
    pred[f - 1][i][v[f - 1][i] % mod] = "";
    dp[f - 1][i][v[f - 1][i] % mod] = v[f - 1][i];
  }
  for (int i = f - 2; i >= 0; --i) {
    for (int j = 0; j < c; ++j) {
      if (j - 1 >= 0) {
        for (int k = 0; k < (int)(mod); ++k) {
          int moda = dp[i + 1][j - 1][k];
          if (moda != -1) {
            int vn = moda + v[i][j];
            if (dp[i][j][vn % mod] < vn) {
              dp[i][j][vn % mod] = vn;
              pred[i][j][vn % mod] = pred[i + 1][j - 1][k] + "R";
            }
          }
        }
      }
      if (j + 1 < c) {
        for (int k = 0; k < (int)(mod); ++k) {
          int moda = dp[i + 1][j + 1][k];
          if (moda != -1) {
            int vn = moda + v[i][j];
            if (dp[i][j][vn % mod] < vn) {
              dp[i][j][vn % mod] = vn;
              pred[i][j][vn % mod] = pred[i + 1][j + 1][k] + "L";
            }
          }
        }
      }
    }
  }
  int maxi = -1, index = 0;
  for (int i = 0; i < (int)(c); ++i) {
    if (dp[0][i][0] > maxi) {
      maxi = dp[0][i][0];
      index = i;
    }
  }
  if (maxi == -1) {
    printf("-1");
    return 0;
  }
  int where = index;
  string ans = pred[0][index][0];
  for (int i = f - 2; i >= 0; --i) {
    if (ans[i] == 'L') {
      where++;
    } else
      where--;
  }
  cout << maxi << endl << where + 1 << endl;
  cout << ans << endl;
  return 0;
}
