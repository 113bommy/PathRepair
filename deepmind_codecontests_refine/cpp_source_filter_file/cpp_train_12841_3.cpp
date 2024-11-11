#include <bits/stdc++.h>
using namespace std;
int n, a[304][304], v[608][304][304], x;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) cin >> a[i][j];
  memset(v, 0xff, sizeof(v));
  v[2][1][1] = a[1][1];
  for (int i = 3; i <= n * 2; ++i) {
    for (int j = 1; j <= n; ++j)
      for (int k = j; k <= n; ++k)
        if (j <= i && k <= i) {
          int x = max(max(v[i - 1][j][k], v[i - 1][j - 1][k]),
                      max(v[i - 1][j][k - 1], v[i - 1][j - 1][k - 1]));
          v[i][j][k] = x + a[j][i - j] + (j == k ? 0 : a[k][i - k]);
        }
  }
  cout << v[n * 2][n][n] << endl;
}
