#include <bits/stdc++.h>
using namespace std;
void io() {}
const int inf = 1000000000;
int n, k;
vector<vector<int>> p;
vector<vector<int>> dp;
int get(int l, int r) { return (p[r][r] - p[r][l] - p[l][r] + p[l][l]) >> 1; }
void f(int j, int l, int r, int tl, int tr) {
  if (l > r) {
    return;
  }
  int t = (l + r) / 2;
  int best = inf, bestP = -1;
  for (int i = tl; i <= tr; i++) {
    if (dp[i - 1][j - 1] == inf) continue;
    int tt = dp[i - 1][j - 1] + get(i - 1, t);
    if (tt < best) {
      best = tt;
      bestP = i;
    }
  }
  dp[t][j] = best;
  f(j, l, t - 1, tl, bestP);
  f(j, t + 1, r, bestP, tr);
}
int main() {
  io();
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c = ' ';
      while (c < '0' || c > '9') {
        c = getchar();
      }
      a[i + 1][j + 1] = c - '0';
    }
  }
  p.assign(n + 1, vector<int>(n + 1));
  p[1][1] = a[1][1];
  for (int i = 2; i <= n; i++) {
    p[i][1] = p[i - 1][1] + a[i][1];
    p[1][i] = p[1][i - 1] + a[1][i];
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + a[i][j];
    }
  }
  dp.assign(n + 1, vector<int>(k + 1, inf));
  dp[0][0] = 0;
  for (int i = 1; i <= k; i++) {
    f(i, 1, n, 1, n);
  }
  cout << dp[n][k];
  return 0;
}
