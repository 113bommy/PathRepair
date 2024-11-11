#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[2000][2000];
int di[] = {0, 0, 0, 1, 1, 1, -1, -1, -1};
int dj[] = {0, -1, 1, -1, 0, 1, -1, 0, 1};
bool ok(int i, int j) { return i > 0 && j > 0 && i <= n && j <= m; }
int main() {
  scanf("%i%i", &n, &m);
  for (int k = 0; k < m; k++) {
    int i, j;
    scanf("%i%i", &i, &j);
    a[j][i] = k + 1;
  }
  int ans = 1e9;
  for (int i = 1; i < n; i++)
    for (int j = 1; j < n; j++) {
      int res = 0;
      bool flag = true;
      for (int p = 0; p < 9; p++)
        if (ok(i + di[p], j + dj[p]) && a[i + di[p]][j + dj[p]])
          res = max(res, a[i + di[p]][j + dj[p]]);
        else
          flag = false;
      if (flag) ans = min(ans, res);
    }
  cout << (ans == 1e9 ? -1 : ans);
  return 0;
}
