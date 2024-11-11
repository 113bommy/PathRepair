#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
string a[64];
int main() {
  int h, w;
  cin >> h >> w;
  int mnx = inf;
  int mxx = -1;
  int mny = inf;
  int mxy = -1;
  for (int i = 0; i < h; i++) {
    cin >> a[i];
    for (int j = 0; j < w; j++) {
      if (a[i][j] == '#') {
        mnx = min(mnx, j);
        mxx = max(mxx, j);
        mny = min(mny, i);
        mxy = max(mxy, i);
      }
    }
  }
  for (int i = mny; i <= mxy; i++) {
    for (int j = mnx; j <= mxx; j++) {
      printf("%c", a[i][j]);
    }
    puts("");
  }
  return 0;
}
