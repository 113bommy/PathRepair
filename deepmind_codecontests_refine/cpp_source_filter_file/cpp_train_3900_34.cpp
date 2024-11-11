#include <bits/stdc++.h>
using namespace std;
int a[2005][2005];
long long b[10020] = {0}, d[10020] = {0};
int main() {
  std::ios_base::sync_with_stdio(0);
  int cases, caseno = 0, n, i, j, k, cnt, x, y, x1, y1, M = 5000;
  long long sum, mx1, mx2;
  cin >> n;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) cin >> a[i][j];
  }
  for (i = 1; i <= n; i++) {
    x = 1, y = i;
    sum = 0;
    while (x <= n && y <= n) sum += a[x++][y++];
    b[M + 1 - i] = sum;
    x = i, y = 1;
    sum = 0;
    while (x <= n && y <= n) sum += a[x++][y++];
    b[M + i - 1] = sum;
    x = 1, y = i;
    sum = 0;
    while (x <= n && y > 0) sum += a[x++][y--];
    d[M + 1 + i] = sum;
    x = i, y = n;
    sum = 0;
    while (x <= n && y > 0) sum += a[x++][y--];
    d[M + i + n] = sum;
  }
  mx1 = mx2 = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      sum = b[M + i - j] + d[M + i + j] - a[i][j];
      if (i % 2 == j % 2) {
        if (sum > mx1) {
          mx1 = sum;
          x1 = i;
          y1 = j;
        }
      } else {
        if (sum > mx2) {
          mx2 = sum;
          x = i;
          y = j;
        }
      }
    }
  }
  cout << mx1 + mx2 << '\n' << x << " " << y << " " << x1 << " " << y1 << '\n';
  return 0;
}
