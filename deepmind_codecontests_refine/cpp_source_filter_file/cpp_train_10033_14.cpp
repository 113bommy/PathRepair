#include <bits/stdc++.h>
using namespace std;
const int inf = 1000 * 1000;
const int nmax = 10 + 10;
const double eps = 1e-2;
int n;
int ans = 0;
bool ok(int x) {
  int cur = 0;
  int d = 2;
  while (x > 1) {
    if (cur > 2) return false;
    if (x % d == 0) {
      cur++;
      while (x % d == 0) x /= d;
    }
    if (d == 2)
      ++d;
    else
      d += 2;
  }
  if (cur < 2) return false;
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 5; i <= n; ++i) {
    if (ok(i)) ans++;
  }
  cout << ans << endl;
  return 0;
}
