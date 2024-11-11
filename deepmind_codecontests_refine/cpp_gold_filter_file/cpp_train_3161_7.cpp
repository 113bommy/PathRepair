#include <bits/stdc++.h>
using namespace std;
void print(vector<int> &a) {
  for (int i : a) {
    cout << i << " ";
  }
  cout << "\n";
}
int main(void) {
  ios_base::sync_with_stdio(false);
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<string> code(n, "");
  vector<int> whi(m, -1);
  vector<int> w_c(m, 0), b_c(m, 0);
  vector<int> w_cum(m, 0), b_cum(m, 0);
  for (int i = (0); i <= (n - 1); i++) cin >> code[i];
  for (int j = (0); j <= (m - 1); j++) {
    for (int i = (0); i <= (n - 1); i++) {
      if (code[i][j] == '.')
        w_c[j]++;
      else
        b_c[j]++;
    }
  }
  w_cum[0] = w_c[0];
  b_cum[0] = b_c[0];
  for (int i = (1); i <= (m - 1); i++) {
    w_cum[i] = w_cum[i - 1] + w_c[i];
    b_cum[i] = b_cum[i - 1] + b_c[i];
  }
  vector<vector<int> > dp(2, vector<int>(m, 0));
  for (int j = (0); j <= (min(x - 1, m) - 1); j++) {
    dp[0][j] = n * m;
    dp[1][j] = n * m;
  }
  for (int j = (x - 1); j <= (m - 1); j++) {
    int mn1 = INT_MAX, mn2 = INT_MAX;
    if (y > j) {
      mn1 = b_cum[j];
      mn2 = w_cum[j];
    }
    for (int i = (x); i <= (min(j, y)); i++) {
      mn1 = min(mn1, dp[1][j - i] + (b_cum[j] - b_cum[j - i]));
      mn2 = min(mn2, dp[0][j - i] + (w_cum[j] - w_cum[j - i]));
    }
    dp[0][j] = mn1;
    dp[1][j] = mn2;
  }
  cout << min(dp[0][m - 1], dp[1][m - 1]);
  return 0;
}
