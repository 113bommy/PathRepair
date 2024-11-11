#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int u[1001], d[1001], r[1001], l[1001];
int main() {
  int n, m;
  cin >> n >> m;
  int a[n][m][2];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int b;
      cin >> b;
      if (b == 1) {
        d[j] = i + 1;
        if ((u[j] - 1 >= 0)) {
          u[j] = min(u[j], i + 1);
        } else {
          u[j] = i + 1;
        }
        r[i] = j + 1;
        if ((l[i] - 1 >= 0)) {
          l[i] = min(l[i], j + 1);
        } else {
          l[i] = j + 1;
        }
      } else {
        dp[i][j] = -1;
      }
    }
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dp[i][j] == -1) {
        if (u[j] - 1 > i && u[j] != 0) {
          sum++;
        }
        if (d[j] - 1 < i && d[j] != 0) {
          sum++;
        }
        if (r[i] - 1 > j && r[i] != 0) {
          sum++;
        }
        if (l[i] - 1 < j && l[i] != 0) {
          sum++;
        }
      }
    }
  }
  cout << sum;
  return 0;
}
