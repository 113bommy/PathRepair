#include <bits/stdc++.h>
using namespace std;
int n, m, t, k;
int a[20][20];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> t >> k;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    a[x][y] = 1;
  }
  int res = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      for (int ii = i; ii < n; ii++)
        for (int jj = j; jj < m; jj++) {
          int cur = 0;
          for (int x = i; x <= ii; x++)
            for (int y = j; y <= jj; y++) cur += a[x][y];
          res += (cur >= k);
        }
  cout << res << '\n';
  return 0;
}
