#include <bits/stdc++.h>
using namespace std;
int dp[505][505];
int main() {
  int n, m, b, d, a;
  cin >> n >> m >> b >> d;
  for (short i = 0; i < 505; i++) dp[0][i] = 1;
  for (short i = 0; i < n; i++) {
    cin >> a;
    for (short j = 1; j < 505; j++) {
      for (short k = a; k < 505; k++) {
        dp[j][k] = (dp[j][k] + dp[j - 1][k - 1]) % d;
      }
    }
  }
  printf("%d", dp[m][b]);
  fclose(stdin);
  return 0;
}
