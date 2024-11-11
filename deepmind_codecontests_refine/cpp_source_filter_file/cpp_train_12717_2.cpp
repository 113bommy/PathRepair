#include <bits/stdc++.h>
using namespace std;
int n, m, b[300001], a[300001], l, r, mid, res;
bool check(int x) {
  int y;
  for (int i = 1; i <= n; i++) b[i] = a[i];
  for (int i = 2; i <= n; i++) {
    y = b[i - 1] - b[i];
    if (y < 0) y += m;
    if (y <= x)
      b[i] = b[i - 1];
    else if (b[i] < b[i - 1])
      return 0;
  };
  return 1;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  l = 0;
  r = m;
  res = m;
  do {
    mid = (l + r) / 2;
    if (check(mid)) {
      r = mid - 1;
      res = min(res, mid);
    } else
      l = mid + 1;
  } while (l <= r);
  cout << res;
  return 0;
}
