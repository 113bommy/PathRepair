#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
};
int n, m;
point P[3];
int main() {
  string res;
  int n, m, x1, y1, x2, y2;
  cin >> n >> m >> x1 >> y1 >> x2 >> y2;
  int delx = abs(x2 - x1);
  int dely = abs(y2 - y1);
  int maxx = (delx > dely) ? delx : dely;
  if (maxx > 5) res = "Second";
  if (maxx < 5) res = "First";
  if (maxx == 5) {
    int other = delx + dely - maxx;
    if (other == 5)
      res = "Second";
    else
      res = "First";
  }
  cout << res;
  return 0;
}
