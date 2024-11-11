#include <bits/stdc++.h>
using namespace std;
char c[105][105];
int n, m;
int x[4], y[4], cnt;
int main() {
  cin >> n >> m;
  cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    for (int j = 0; j < m; j++)
      if (c[i][j] == '*') x[cnt] = i, y[cnt++] = j;
  }
  int xx, yy;
  if (x[0] == x[1]) {
    if (y[2] == y[0])
      xx = x[2], yy = y[1];
    else
      xx = x[2], yy = y[0];
  } else {
    if (y[0] == y[2])
      xx = x[0], yy = y[1];
    else
      xx = x[0], yy = y[2];
  }
  cout << xx + 1 << " " << yy + 1 << endl;
}
