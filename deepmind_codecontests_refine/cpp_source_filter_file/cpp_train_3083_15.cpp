#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const int MX = 502;
int n, m, k, LIMIT;
int M[MX][MX];
bool Check(int t) {
  int i, j, cnt, temp;
  int dp[MX][MX], row[MX][MX], col[MX][MX];
  dp[1][1] = 0;
  for (i = 1; i < k + 1; i++)
    for (j = 1; j < k + 1; j++)
      if (M[i][j] <= t) dp[1][1]++;
  if (dp[1][1] >= LIMIT) return true;
  for (i = 1; i < n + 1; i++) {
    row[i][1] = 0;
    for (j = 1; j < 1 + k; j++)
      if (M[i][j] <= t) row[i][1]++;
    for (j = 2; j < m + 1 - k + 1; j++) {
      row[i][j] = row[i][j - 1];
      if (M[i][j - 1] <= t) row[i][j]--;
      if (M[i][j + k - 1] <= t) row[i][j]++;
    }
  }
  for (j = 1; j < m + 1; j++) {
    col[1][j] = 0;
    for (i = 1; i < 1 + k; i++)
      if (M[i][j] <= t) col[1][j]++;
    for (i = 2; i < n + 1 - k + 1; i++) {
      col[i][j] = col[i - 1][j];
      if (M[i - 1][j] <= t) col[i][j]--;
      if (M[i + k - 1][j] <= t) col[i][j]++;
    }
  }
  for (i = 1; i < n + 1 - k + 1; i++) {
    if (i != 1) dp[i][1] = dp[i - 1][1] - row[i - 1][1] + row[i + k - 1][1];
    for (j = 1; j < m + 1 - k + 1; j++) {
      if (j != 1) dp[i][j] = dp[i][j - 1] - col[i][j - 1] + col[i][j + k - 1];
      if (dp[i][j] >= LIMIT) return true;
    }
  }
  return false;
}
int BinarySearch(int lo, int hi) {
  if (lo == hi) return Check(lo) ? lo : -1;
  int mid = (lo + hi) >> 1;
  return Check(mid) ? BinarySearch(lo, mid) : BinarySearch(mid + 1, hi);
}
int main() {
  ios_base::sync_with_stdio(false);
  int i, j, q, x, y, t;
  cin >> n >> m >> k >> q;
  for (i = 1; i < n + 1; i++)
    for (j = 1; j < m + 1; j++) M[i][j] = INF;
  LIMIT = k * k;
  while (q--) {
    cin >> x >> y >> t;
    M[x][y] = t;
  }
  cout << BinarySearch(1, 1e9);
  return 0;
}
