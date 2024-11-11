#include <bits/stdc++.h>
using namespace std;
int main() {
  int hy, ay, dy, hm, am, dm, h, a, d;
  cin >> hy >> ay >> dy >> hm >> am >> dm >> h >> a >> d;
  int y, m, mn = 600;
  for (int i(0); i < 201; ++i) {
    if ((ay + i - dm) <= 0) continue;
    for (int j(0); j < 201; ++j) {
      y = hy;
      m = hm;
      while (m > 0) {
        m -= max(0, ay + i - dm);
        y -= max(0, am - dy - j);
      }
      if (y > 0)
        mn = min(mn, i * a + j * d);
      else
        mn = min(mn, i * a + j * d - y * h + h);
    }
  }
  cout << mn << endl;
  return 0;
}
