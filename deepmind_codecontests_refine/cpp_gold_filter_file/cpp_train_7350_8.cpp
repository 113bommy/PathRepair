#include <bits/stdc++.h>
using namespace std;
const int N = 555;
int n, m, k;
int first[N], second[N];
int X[N << 1], xn, Y[N << 1], sdf;
int dp[N << 1][N << 1];
bool can(int t) {
  xn = 0, sdf = 0;
  X[xn++] = 1, X[xn++] = n + 1, Y[sdf++] = 1, Y[sdf++] = m + 1;
  for (int i = 0; i < k; i++) {
    int L = max(1, first[i] - t), R = min(n, first[i] + t);
    X[xn++] = L, X[xn++] = R + 1;
    L = max(1, second[i] - t), R = min(m, second[i] + t);
    Y[sdf++] = L, Y[sdf++] = R + 1;
  }
  sort(X, X + xn);
  xn = unique(X, X + xn) - X;
  sort(Y, Y + sdf);
  sdf = unique(Y, Y + sdf) - Y;
  for (int i = 0; i < xn; i++)
    for (int j = 0; j < sdf; j++) dp[i][j] = 0;
  for (int i = 0; i < k; i++) {
    int L = max(1, first[i] - t), R = min(n, first[i] + t);
    L = lower_bound(X, X + xn, L) - X;
    R = lower_bound(X, X + xn, R + 1) - X;
    int S = max(1, second[i] - t), T = min(m, second[i] + t);
    S = lower_bound(Y, Y + sdf, S) - Y;
    T = lower_bound(Y, Y + sdf, T + 1) - Y;
    dp[L][S] += 1;
    dp[L][T] += -1;
    dp[R][S] += -1;
    dp[R][T] += 1;
  }
  for (int i = 0; i + 1 < xn; i++)
    for (int j = 1; j + 1 < sdf; j++) dp[i][j] += dp[i][j - 1];
  int xmn = n, xmx = 1, ymn = m, ymx = 1;
  for (int i = 0; i + 1 < xn; i++)
    for (int j = 0; j + 1 < sdf; j++) {
      if (i) dp[i][j] += dp[i - 1][j];
      if (!dp[i][j]) {
        xmn = min(xmn, X[i]);
        xmx = max(xmx, X[i + 1] - 1);
        ymn = min(ymn, Y[j]);
        ymx = max(ymx, Y[j + 1] - 1);
      }
    }
  return (xmx - xmn) <= t * 2 && (ymx - ymn) <= t * 2;
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) cin >> first[i] >> second[i];
  int st = -1, ed = 1e9;
  while (st + 1 < ed) {
    int md = st + ed >> 1;
    if (can(md))
      ed = md;
    else
      st = md;
  }
  cout << ed << endl;
  return 0;
}
