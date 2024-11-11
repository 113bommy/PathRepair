#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s = 0, x[110][110];
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> x[i][j];
  for (int i = 1; i <= n; i++) {
    s += x[i][i];
    x[i][i] = 0;
    s += x[i][n - i + 1];
    x[i][n - i + 1] = 0;
    s += x[(n - 1) / 2 + 1][i];
    x[(n - 1) / 2 + 1][i] = 0;
    s += x[i][(n - 1) / 2 + 1];
    x[i][(n - 1) / 2 + 1] = 0;
  }
  cout << s;
  return 0;
}
