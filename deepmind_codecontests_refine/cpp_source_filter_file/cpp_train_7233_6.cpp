#include <bits/stdc++.h>
using namespace std;
const int N = 555;
int n, m, q;
int a[N][N], ans[N];
int cal(int i) {
  int flag = 0, l = 0, r = 0, ret = 0;
  for (int j = 1; j <= m; ++j) {
    if (a[i][j]) {
      if (!flag)
        flag = 1, l = j;
      else
        r = j;
    } else {
      if (flag) ret = max(ret, r - l + 1);
      flag = 0;
    }
  }
  if (flag) ret = max(ret, r - l + 1);
  return ret;
}
int main() {
  while (cin >> n >> m >> q) {
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) cin >> a[i][j];
      ans[i] = cal(i);
    }
    while (q--) {
      int x, y;
      cin >> x >> y;
      a[x][y] = 1 - a[x][y];
      ans[x] = cal(x);
      int res = 0;
      for (int i = 1; i <= n; ++i) res = max(res, ans[i]);
      cout << res << endl;
    }
  }
  return 0;
}
