#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s1, s2, s3;
  long long i, p, j, ii, x, y, iii, cnt, cnt1, cnt2, d,
      c = 1, k, m, o, t = 0, mi = 2, n, sum = 0, h3 = 0, s4 = 0, h4 = 0, a, r;
  cin >> a >> x >> y;
  if (y % a == 0) {
    cout << -1;
    return 0;
  }
  if (y < a) {
    if (2 * x < a && 2 * x > -a)
      cout << 1;
    else
      cout << -1;
    return 0;
  }
  y = y - a;
  i = y / a;
  if (i % 2 == 0 && 2 * x < a && 2 * x > -a) {
    cout << 2 + 3 * i / 2;
    return 0;
  }
  if (i % 2 == 1 && x < a && x > 0) {
    cout << 2 + 3 * (i - 1) / 2;
    return 0;
  }
  if (i % 2 == 1 && x < 0 && x > -a) {
    cout << 2 + 3 * (i - 1) / 2;
    return 0;
  }
  cout << -1;
  return 0;
}
