#include <bits/stdc++.h>
using namespace std;
long double e = 1e-14;
const long double INF = (long double)2000 * 1000 * 1000 * 1000 * 1000 * 1000;
long long a[2][2];
long double l[2][2], r[2][2];
long double lans[2], rans[2];
void up(int x, long double y) {
  lans[x] = min(y, lans[x]);
  rans[x] = max(rans[x], y);
}
bool check(long double x) {
  lans[1] = lans[0] = INF;
  rans[1] = rans[0] = -INF;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      l[i][j] = a[i][j] - x;
      r[i][j] = a[i][j] + x;
    }
  up(0, (l[0][0] * l[1][1]));
  up(0, (l[0][0] * r[1][1]));
  up(0, (r[0][0] * r[1][1]));
  up(0, (r[0][0] * l[1][1]));
  up(1, l[0][1] * l[1][0]);
  up(1, r[0][1] * l[1][0]);
  up(1, l[0][1] * r[1][0]);
  up(1, r[0][1] * r[1][0]);
  if (rans[0] < lans[1] + e || rans[1] < lans[0] + e) return 0;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) cin >> a[i][j];
  long double l = 0;
  long double r = (long double)2000 * 1000 * 1000 * 1000 * 1000 * 1000;
  for (int i = 0; i < 2000000; i++) {
    long double s = (l + r) / 2;
    if (check(s))
      r = s;
    else
      l = s;
  }
  cout.setf(ios::fixed);
  cout.precision(20);
  cout << r;
  return 0;
}
