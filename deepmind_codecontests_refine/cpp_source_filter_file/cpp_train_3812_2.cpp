#include <bits/stdc++.h>
using namespace std;
int n, a[12][6], ans[12], cnt;
bool check(int x, int p, int q) {
  int tot = 0;
  for (int i = 1; i <= 5; i++)
    tot = tot + (a[p][i] - a[x][i]) * (a[q][i] - a[x][i]);
  if (tot <= 0)
    return 1;
  else
    return 0;
}
int main() {
  cin >> n;
  if (n > 10) {
    cout << 0;
    exit(0);
  };
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 5; j++) cin >> a[i][j];
  for (int k = 1; k <= n; k++) {
    bool flag = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        if (i == j || j == k || i == k || flag) continue;
        if (!check(k, i, j)) flag = 1;
      }
    if (!flag) {
      cnt++;
      ans[cnt] = k;
    }
  }
  cout << cnt << endl;
  for (int i = 1; i <= cnt; i++) cout << ans[i] << endl;
}
