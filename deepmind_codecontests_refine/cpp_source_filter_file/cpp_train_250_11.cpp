#include <bits/stdc++.h>
using namespace std;
int n, k, minn, maxx, num1, num2, ans, sum, t, a[201], now[201];
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  ans = -1e9;
  for (int l = 1; l <= n; l++) {
    for (int r = l; r <= n; r++) {
      for (int i = 1; i <= n; i++) now[i] = a[i];
      for (int i = 1; i <= k; i++) {
        minn = 1e9;
        maxx = -1e9;
        num1 = 0;
        num2 = 0;
        for (int j = 1; j < l; j++)
          if (maxx < now[j]) {
            maxx = now[j];
            num1 = j;
          }
        for (int j = l + 1; j <= n; j++)
          if (maxx < now[j]) {
            maxx = now[j];
            num1 = j;
          }
        for (int j = l; j <= r; j++)
          if (minn > now[j]) {
            minn = now[j];
            num2 = j;
          }
        if (minn < maxx)
          t = now[num1], now[num1] = now[num2], now[num2] = t;
        else
          break;
      }
      sum = 0;
      for (int i = l; i <= r; i++) sum += now[i];
      ans = max(ans, sum);
    }
  }
  cout << ans;
}
