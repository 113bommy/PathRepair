#include <bits/stdc++.h>
using namespace std;
long long int dv[200010];
long long int rat[200010];
long long int solve(long long int r, long long int n) {
  for (long long int i = 1; i <= n; i++) {
    if (dv[i] == 1 && r < 1900) return -1;
    if (dv[i] == 2 && r >= 1900) return 1;
    r += rat[i];
  }
  return 0;
}
int main() {
  long long int n, i, j, k, l, r, d, ans = -100000000000, m, s = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> rat[i] >> dv[i];
    s += rat[i];
  }
  l = -10000000000;
  r = 10000000000;
  while (l <= r) {
    m = (l + r) / 2;
    k = solve(m, n);
    if (k != 1 && k != -1) {
      ans = max(ans, m);
      l = m + 1;
    } else if (k == 1) {
      r = m - 1;
    } else if (k == -1) {
      l = m + 1;
    }
  }
  if (ans == -100000000000)
    cout << "Impossible" << endl;
  else if (ans == 10000000000)
    cout << "Infinity" << endl;
  else {
    cout << ans + s << endl;
  }
  return 0;
}
