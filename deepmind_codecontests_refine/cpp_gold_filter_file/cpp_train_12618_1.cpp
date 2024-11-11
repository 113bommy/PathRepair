#include <bits/stdc++.h>
using namespace std;
int x[1010], y[1010], cnt, _cnt;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d %d", &x[i], &y[i]);
  while (true) {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
      if ((x[i] + y[i]) & 1 == 1) cnt++;
    if (cnt >= 1 && cnt <= n - 1) {
      cout << cnt << endl;
      for (int i = 1; i <= n; i++)
        if ((x[i] + y[i]) & 1 == 1) printf("%d ", i);
      return 0;
    }
    if (cnt == n) {
      for (int i = 1; i <= n; i++) x[i]--;
    }
    for (int i = 1; i <= n; i++) {
      cnt = (x[i] - y[i]) / 2;
      _cnt = (x[i] + y[i]) / 2;
      x[i] = cnt;
      y[i] = _cnt;
    }
  }
  return 0;
}
