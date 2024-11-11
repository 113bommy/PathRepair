#include <bits/stdc++.h>
using namespace std;
bool f[102][102];
int main() {
  int i, j, k, l, n, m, x[100], y[100], t, mx, my, mi, d;
  while (cin >> n >> m >> k) {
    for (i = 0; i < k; i++) cin >> x[i] >> y[i];
    t = 1;
    for (i = 0; i < k && t; i++) {
      if (x[i] < 5)
        t = 0;
      else if (x[i] > n - 4)
        t = 0;
      else if (y[i] < 5)
        t = 0;
      else if (y[i] > m - 4)
        t = 0;
    }
    if (t)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
