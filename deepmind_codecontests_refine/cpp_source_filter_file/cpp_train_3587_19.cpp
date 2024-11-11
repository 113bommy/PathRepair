#include <bits/stdc++.h>
using namespace std;
int n, m, a[1555][1555];
long long sum[1555][1555];
long long best[1555][1555];
long long mx[1555][1555];
const long long oo = 12345678901234567LL;
long long solve() {
  memset(sum, 0, sizeof(sum));
  memset(best, 0, sizeof(best));
  memset(mx, 0, sizeof(mx));
  for (int i = 0; i < n; i++) {
    sum[i][0] = a[i][0];
    for (int j = 1; j < m; j++) sum[i][j] = sum[i][j - 1] + a[i][j];
  }
  for (int j = 0; j < m; j++) best[0][j] = sum[0][j];
  mx[0][m - 1] = best[0][m - 1];
  for (int j = m - 2; j >= 0; j--) mx[0][j] = max(best[0][j], mx[0][j + 1]);
  for (int i = 1; i < n; i++) {
    if (i & 1) {
      best[i][m - 1] = -oo;
      for (int j = 0; j < m - 1; j++) best[i][j] = sum[i][j] + mx[i - 1][j + 1];
    } else {
      best[i][0] = -oo;
      for (int j = 1; j < m; j++) best[i][j] = sum[i][j] + mx[i - 1][j - 1];
    }
    if (i & 1) {
      mx[i][0] = best[i][0];
      for (int j = 0; j < m; j++) mx[i][j] = max(best[i][j], mx[i][j - 1]);
    } else {
      mx[i][m - 1] = best[i][m - 1];
      for (int j = m - 2; j >= 0; j--) mx[i][j] = max(best[i][j], mx[i][j + 1]);
    }
  }
  long long res = 0;
  for (int j = 0; j < m; j++) res = max(res, mx[n - 1][j]);
  return res;
}
int main() {
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
    cout << solve() << endl;
  }
}
