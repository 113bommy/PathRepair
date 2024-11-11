#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  int T[n][m];
  vector<int> row(n, -1), col(n, -1);
  for (int i = (0); i <= (n - 1); ++i)
    for (int j = (0); j <= (m - 1); ++j) {
      char ct;
      cin >> ct;
      if (ct == '.')
        T[i][j] = 0;
      else
        T[i][j] = (ct - '0');
      if (!T[i][j]) continue;
      bool r = (j % 2) xor (T[i][j] <= 2),
           c = (i % 2) xor (T[i][j] == 1 || T[i][j] == 4);
      if (row[i] != -1 && row[i] != r) {
        cout << 0;
        return 0;
      } else
        row[i] = r;
      if (col[j] != -1 && col[j] != c) {
        cout << 0;
        return 0;
      } else
        col[j] = c;
    }
  int MOD = 1000003;
  int ans = 1;
  for (int i = (0); i <= ((int)(row).size() - 1); ++i)
    if (row[i] == -1) ans = (2 * ans) % MOD;
  for (int i = (0); i <= ((int)(col).size() - 1); ++i)
    if (col[i] == -1) ans = (2 * ans) % MOD;
  cout << ans;
  return 0;
}
