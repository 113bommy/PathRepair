#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[1000][1000], ans1, ans2, sum, mx;
int Sum(int x, int y, int len) {
  int ssum = 0;
  for (int i = x; i < x + len; i++) ssum += a[i][y];
  return ssum;
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int j = 0; j < m; j++) {
    sum = mx = 0;
    for (int i = 0; i < n; i++)
      mx = (a[i][j] == 1 ? max(mx, Sum(i, j, k)) : mx);
    ans1 += mx;
    for (int i = 0; i < n; i++)
      if (a[i][j] == 1) {
        if (Sum(i, j, k) == mx) break;
        sum++;
      }
    ans2 += sum;
  }
  cout << ans1 << ' ' << ans2;
  return 0;
}
