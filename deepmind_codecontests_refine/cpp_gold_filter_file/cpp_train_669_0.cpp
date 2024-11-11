#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int maxn = 100500;
const int inf = 1 << 30;
const int mod = int(1e9) + 7;
const int base = 257;
double dist(int xa, int ya, int xb, int yb) {
  return ((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb) + .0);
}
bool check(int xa, int ya, int xb, int yb, int xc, int yc, int xd, int yd) {
  int x[5], y[5];
  x[1] = xa, y[1] = ya;
  x[2] = xb, y[2] = yb;
  x[3] = xc, y[3] = yc;
  x[4] = xd, y[4] = yd;
  set<double> Set;
  set<pair<int, int> > dup;
  for (int i = 1; i <= 4; i++) dup.insert(make_pair(x[i], y[i]));
  for (int i = 1; i <= 4; i++)
    for (int j = 1; j <= 4; j++)
      if (i != j) Set.insert(dist(x[i], y[i], x[j], y[j]));
  if (Set.size() == 2 && dup.size() == 4) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int xx[5][5], yy[5][5], ans = inf;
    for (int i = 1; i <= 4; i++) {
      int x, y, a, b;
      cin >> x >> y >> a >> b;
      x -= a, y -= b;
      xx[i][0] = x + a, xx[i][1] = -y + a, xx[i][2] = -x + a, xx[i][3] = y + a;
      yy[i][0] = y + b, yy[i][1] = x + b, yy[i][2] = -y + b, yy[i][3] = -x + b;
    }
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        for (int k = 0; k < 4; k++)
          for (int l = 0; l < 4; l++) {
            if (check(xx[1][i], yy[1][i], xx[2][j], yy[2][j], xx[3][k],
                      yy[3][k], xx[4][l], yy[4][l]) == true) {
              ans = min(ans, i + j + k + l);
            }
          }
    if (ans == inf)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
