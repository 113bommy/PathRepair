#include <bits/stdc++.h>
using namespace std;
int dp[321][2];
int main() {
  int n, T, L, Spd = 0;
  scanf("%d", &n);
  scanf("%d %d", &T, &L);
  Spd = L, dp[0][1] = 1;
  for (int i = 1; i < n; i++) {
    scanf("%d", &T);
    if (T == 1 || T == 3) scanf("%d", &L);
    switch (T) {
      case 1:
        Spd = L;
        for (int j = 1; j < Spd; j++)
          for (int k = 0; k < 2; k++) dp[j][k] = 0;
        break;
      case 2:
        for (int j = 0; j <= 300; j++) dp[j][0] = 0;
        break;
      case 3:
        for (int j = 0; j <= 300; j++)
          for (int k = 0; k < 2; k++) {
            if (dp[j][k]) {
              if (Spd <= L) {
                if (!dp[L][k] || dp[j][k] < dp[L][k]) dp[L][k] = dp[j][k];
                if (j > L || j == 0) dp[j][k]++;
              } else {
                dp[j][k]++;
              }
            }
          }
        break;
      case 4:
        for (int j = 0; j <= 300; j++)
          if (dp[j][0] && dp[j][0] < dp[j][1]) {
            dp[j][1] = dp[j][0];
          }
        break;
      case 5:
        for (int j = 1; j <= 300; j++)
          for (int k = 0; k < 2; k++)
            if (dp[j][k])
              if (!dp[0][k] || dp[j][k] < dp[0][k]) dp[0][k] = dp[j][k];
        break;
      case 6:
        for (int j = 0; j <= 300; j++) {
          if (dp[j][1]) {
            if (!dp[j][0] || dp[j][1] < dp[j][0]) dp[j][0] = dp[j][1];
            dp[j][1]++;
          }
        }
        break;
    }
  }
  int Out = 1 << 30;
  for (int i = 0; i <= 300; i++) {
    for (int k = 0; k < 2; k++)
      if (i >= Spd || i == 0)
        if (dp[i][k] && dp[i][k] < Out) {
          Out = dp[i][k];
        }
  }
  cout << Out - 1;
}
