#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
int ll_max = 1e6;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int n, m, k, i, j, z;
  long long int x, y, t, count, p;
  cin >> n;
  long long int a[n][n];
  long long int b[n][n];
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < n; j++) {
      cin >> a[i][j];
      if ((i + j) % 2 == 0)
        b[i][j] = 0;
      else
        b[i][j] = 1;
    }
  }
  long long int maxb = 0;
  long long int maxw = 0;
  pair<long long int, long long int> white;
  pair<long long int, long long int> black;
  long long int sum1[n][n];
  memset(sum1, 0, sizeof(sum1[0][0]) * n * n);
  long long int sum2[n][n];
  memset(sum1, 0, sizeof(sum2[0][0]) * n * n);
  for (long long int i = 0; i < n; i++) {
    for (j = 0; j < n; j += (n - 1)) {
      z = min(i, j);
      x = i - z;
      y = j - z;
      long long int sm1 = 0;
      long long int sm2 = 0;
      while (x < n && y < n) {
        sm1 += a[x][y];
        x++;
        y++;
      }
      z = min(i, n - 1 - j);
      x = i - z;
      y = j + z;
      while (x < n && y >= 0) {
        sm2 += a[x][y];
        x++;
        y--;
      }
      sum1[i][j] = sm1;
      sum2[i][j] = sm2;
    }
  }
  i = 0;
  for (long long int j = 0; j < n; j++) {
    z = min(i, j);
    x = i - z;
    y = j - z;
    long long int sm1 = 0;
    long long int sm2 = 0;
    while (x < n && y < n) {
      sm1 += a[x][y];
      x++;
      y++;
    }
    z = min(i, n - 1 - j);
    x = i - z;
    y = j + z;
    while (x < n && y >= 0) {
      sm2 += a[x][y];
      x++;
      y--;
    }
    sum1[i][j] = sm1;
    sum2[i][j] = sm2;
  }
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < n; j++) {
      z = min(i, j);
      x = i - z;
      y = j - z;
      long long int sm1 = sum1[x][y];
      z = min(i, n - 1 - j);
      x = i - z;
      y = j + z;
      long long int sm2 = sum2[x][y];
      long long int total = sm1 + sm2 - a[i][j];
      if (b[i][j] == 0) {
        if (total > maxw) {
          maxw = total;
          white.first = i;
          white.second = j;
        }
      } else {
        if (total > maxb) {
          maxb = total;
          black.first = i;
          black.second = j;
        }
      }
    }
  }
  cout << maxw + maxb << endl;
  cout << white.first + 1 << " " << white.second + 1 << " " << black.first + 1
       << " " << black.second + 1;
  return 0;
}
