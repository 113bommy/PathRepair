#include <bits/stdc++.h>
using namespace std;
int g[30004], d, dp[30004][500];
bool used[30004][500];
int recur(int i, int j) {
  int k = j - d + 250;
  if (i > 30000) return 0;
  if (used[i][k]) return dp[i][k];
  used[i][k] = 1;
  if (j == 1)
    dp[i][k] = g[i] + max(recur(i + j, j), recur(i + j + 1, j + 1));
  else
    dp[i][k] = g[i] + max(recur(i + j - 1, j - 1),
                          max(recur(i + j, j), recur(i + j + 1, j + 1)));
  return dp[i][k];
}
int main() {
  int n, q, t, x, y, m, k, ans;
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> x;
    g[x]++;
  }
  cout << recur(d, d) << "\n";
  return 0;
}
