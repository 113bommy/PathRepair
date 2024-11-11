#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  long long int s;
  s = 1;
  while (s--) {
    solve();
  }
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  int a[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int sum[n][m];
  int sum1[n][m];
  memset(sum, 0, sizeof(sum));
  memset(sum1, 0, sizeof(sum1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i - 1 >= 0)
        sum[i][j] = sum[i - 1][j] + a[i][j];
      else {
        sum[i][j] = a[i][j];
      }
      if (j - 1 >= 0)
        sum1[i][j] = sum1[i][j - 1] + a[i][j];
      else {
        sum1[i][j] = a[i][j];
      }
    }
  }
  long long int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 0) {
        if (i - 1 >= 0 && sum[i - 1][j] > 0) count++;
        if ((i == 0 && sum[n - 1][j] > 0) ||
            (i - 1 >= 0 && sum[n - 1][j] - sum[i - 1][j] > 0))
          count++;
        if (j - 1 >= 0 && sum1[i][j - 1] > 0) count++;
        if ((j == 0 && sum1[i][m - 1] > 0) ||
            (j - 1 >= 0 && sum1[i][m - 1] - sum1[i][j - 1] > 0))
          count++;
      }
    }
  }
  cout << count;
}
