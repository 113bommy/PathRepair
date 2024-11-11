#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, l, r, x, n, h, m, cnt = 0, sum = 0, a[1000];
  memset(a, 0, sizeof(a));
  cin >> n >> h >> m;
  for (i = 0; i < m; i++) {
    cin >> l >> r >> x;
    for (j = l; j <= r; j++) {
      if (a[j] != 0)
        a[j] = min(a[j], x);
      else
        a[j] = x;
    }
  }
  for (j = 1; j <= n; j++)
    if (a[j] <= h && a[j] != 0) {
      sum += (a[j] * a[j]);
      cnt++;
    }
  if (cnt > 0) sum += ((n - cnt) * (h * h));
  cout << sum << endl;
  return 0;
}
