#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int n, k;
int a[1005];
int mn[405][405];
int mx[405][405];
int s[405];
int dp[55][405][405];
int get(int l, int r) {
  int ret = s[r] - (l ? s[l - 1] : 0);
  return ret;
}
int main() {
  int n, k;
  cin >> n >> k;
  for (int(i) = (0); (i) < (n); ++(i)) {
    cin >> a[i];
    if (i) s[i] = s[i - 1];
    s[i] += a[i];
  }
  for (int(i) = (0); (i) < (404); ++(i))
    for (int(j) = (0); (j) < (404); ++(j))
      for (int(q) = (0); (q) < (55); ++(q)) dp[q][i][j] = -INF;
  for (int(i) = (0); (i) < (n); ++(i))
    for (int(j) = (i); (j) < (n); ++(j)) dp[1][i][j] = 0;
  for (int(i) = (0); (i) < (n); ++(i))
    for (int(j) = (i); (j) < (n); ++(j)) {
      mn[i][j] = mx[i][j] = i;
      for (int(t) = (i); (t) < (j + 1); ++(t)) {
        if (get(mn[i][j], j) > get(t, j)) mn[i][j] = t;
        if (get(mx[i][j], j) < get(t, j)) mx[i][j] = t;
      }
    }
  for (int(c) = (1); (c) < (k); ++(c))
    for (int(i) = (0); (i) < (n); ++(i))
      for (int(j) = (i); (j) < (n); ++(j)) {
        if (dp[c][i][j] < 0) continue;
        int cur;
        for (int(e) = (j + 1); (e) < (n); ++(e)) {
          cur = mn[j + 1][e];
          dp[c + 1][cur][e] = max(dp[c + 1][cur][e],
                                  dp[c][i][j] + abs(get(cur, e) - get(i, j)));
          cur = mx[j + 1][e];
          dp[c + 1][cur][e] = max(dp[c + 1][cur][e],
                                  dp[c][i][j] + abs(get(cur, e) - get(i, j)));
        }
      }
  int ans = 0;
  for (int(i) = (0); (i) < (n); ++(i))
    for (int(j) = (i); (j) < (n); ++(j)) ans = max(ans, dp[k][i][j]);
  cout << ans << endl;
  return 0;
}
