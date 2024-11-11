#include <bits/stdc++.h>
using namespace std;
int n, a[1010], b[1010], k;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int j = 1; j <= n; j++) cin >> b[j];
  int d = 1, c = 1000, g, res = 0, tmp, flag;
  while (d <= c) {
    g = (d + c) / 2;
    tmp = k;
    flag = 1;
    for (int i = 1; i <= n; i++)
      if (a[i] * g > b[i])
        if (tmp >= a[i] * g - b[i])
          tmp -= a[i] * g - b[i];
        else {
          flag = 0;
          break;
        }
    if (flag) {
      res = max(res, g);
      d = g + 1;
    } else
      c = g - 1;
  }
  cout << res;
}
