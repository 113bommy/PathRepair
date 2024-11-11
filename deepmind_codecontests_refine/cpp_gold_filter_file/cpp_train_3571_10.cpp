#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 1, prec = 12;
double dp[maxn][maxn];
void sync() {
  for (int i = 0; i < maxn; i++)
    for (int j = 0; j < maxn; j++) dp[i][j] = -1.0;
  for (int i = 0; i < maxn; i++) dp[i][0] = 1.0, dp[0][i] = 0.0;
}
double solve(int w, int b) {
  w = max(w, 0), b = max(b, 0);
  if (dp[w][b] != -1.0) return dp[w][b];
  double win = (double)w / (double)(w + b);
  double lose =
      (double)b / (double)(w + b) * (double)(b - 1) / (double)(w + b - 1);
  if ((float)lose < 0.000000001) {
    dp[w][b] = win;
    return dp[w][b];
  }
  win += lose * ((solve(w, b - 3) * ((double)(b - 2) / (double)(w + b - 2))) +
                 (solve(w - 1, b - 2) * ((double)w / (double)(w + b - 2))));
  dp[w][b] = win;
  return dp[w][b];
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int w, b;
  sync();
  cin >> w >> b;
  cout << fixed << setprecision(prec) << solve(w, b) << endl;
}
