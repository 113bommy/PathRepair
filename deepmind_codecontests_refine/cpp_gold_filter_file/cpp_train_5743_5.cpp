#include <bits/stdc++.h>
using namespace std;
long c[51][51], d[51][51];
int main() {
  long n, m, sum = 0;
  cin >> n >> m;
  long a[n][m], b[n][m], i, j;
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j) cin >> a[i][j];
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j) cin >> b[i][j];
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j) {
      long s, r;
      s = a[i][j];
      r = b[i][j];
      a[i][j] = min(s, r);
      b[i][j] = max(s, r);
    }
  for (i = 0; i < n; ++i)
    for (j = 1; j < m; ++j)
      if (a[i][j] <= a[i][j - 1]) c[i][j] = 1;
  for (i = 0; i < m; ++i)
    for (j = 1; j < n; ++j)
      if (a[j][i] <= a[j - 1][i]) c[j][i] = 1;
  for (i = 0; i < n; ++i)
    for (j = 1; j < m; ++j)
      if (b[i][j] <= b[i][j - 1]) c[i][j] = 1;
  for (i = 0; i < m; ++i)
    for (j = 1; j < n; ++j)
      if (b[j][i] <= b[j - 1][i]) c[j][i] = 1;
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j) sum += c[i][j];
  if (sum > 0)
    cout << "Impossible";
  else
    cout << "Possible";
  return 0;
}
