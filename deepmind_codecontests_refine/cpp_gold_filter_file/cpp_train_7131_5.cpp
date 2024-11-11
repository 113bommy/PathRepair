#include <bits/stdc++.h>
using namespace std;
int a[200], DP[200][200 * 200], ans = 1000000001;
int n, k, s;
int main() {
  cin >> n >> k >> s;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i < 200; i++)
    for (int j = 0; j < 200 * 200; j++) DP[i][j] = 1000000001;
  DP[0][0] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i - 1; j >= 0; j--)
      for (int x = 0; x <= n * n; x++) {
        if (DP[j][x] == 1000000001) continue;
        DP[j + 1][x + i - j - 1] =
            min(DP[j + 1][x + i - j - 1], DP[j][x] + a[i]);
      }
  for (int i = 0; i <= min(s, n * n); i++) ans = min(ans, DP[k][i]);
  cout << ans;
}
