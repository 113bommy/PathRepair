#include <bits/stdc++.h>
using namespace std;
char a[128][128];
int go(int t1, int t2, int t3, int t4) {
  int ans = 0;
  for (int i = t1; i <= t3; ++i)
    for (int j = t2; j <= t4; ++j)
      if (a[i][j] == 'W') ++ans;
  return ans;
}
int main() {
  int n, m;
  cin >> n >> m;
  int l = 128, r = -1, u = 128, d = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      if (a[i][j] == 'B') {
        l = min(l, j);
        r = max(r, j);
        u = min(u, i);
        d = max(d, i);
      }
    }
  }
  if (l == 128) {
    cout << 1;
    return 0;
  }
  if (l == r && u == d) {
    cout << 0;
    return 0;
  }
  int l1 = r - l;
  int l2 = d - u;
  int dif = abs(l2 - l1);
  if (l1 > l2) {
    if (u + n - d - 1 < dif)
      cout << -1;
    else {
      if (u < dif)
        cout << go(0, 0, d + dif - u, r);
      else
        cout << go(u - dif, 0, d, r);
    }
  } else {
    if (l + m - r - 1 < dif)
      cout << -1;
    else {
      if (l < dif)
        cout << go(u, 0, d, r + dif - l);
      else
        cout << go(u, l - dif, d, r);
    }
  }
  return 0;
}
