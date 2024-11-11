#include <bits/stdc++.h>
using namespace std;
int dp[1000010][4][4];
int kol[1000010];
int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int l;
    cin >> l;
    kol[l]++;
  }
  for (int i = 1; i <= n; i++)
    for (int a = 0; a < 3; a++)
      for (int b = 0; b < 3; b++)
        for (int c = 0; c < 3; c++) {
          if (a + b + c > kol[i]) continue;
          if (i + 2 > k && c != 0) continue;
          dp[i + 1][b][c] =
              max(dp[i + 1][b][c], dp[i][a][b] + c + (kol[i] - a - b - c) / 3);
        }
  cout << dp[k + 1][0][0];
}
