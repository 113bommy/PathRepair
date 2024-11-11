#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int h, w, H, W, minn = 999999999;
    cin >> w >> h;
    int xx, dx, xy, dy;
    cin >> xx >> xy >> dx >> dy;
    cin >> W >> H;
    if (W + dx - xx <= w) {
      if (W <= xx)
        minn = 0;
      else
        minn = min(minn, W - xx);
      dx = w - dx;
      if (W <= dx)
        minn = 0;
      else
        minn = min(minn, W - dx);
    }
    if (H + dy - xy <= h) {
      if (H <= xy)
        minn = 0;
      else
        minn = min(minn, H - xy);
      dy = h - dy;
      if (H <= dy)
        minn = 0;
      else
        minn = min(minn, H - dy);
    }
    if (minn == 999999999)
      cout << "-1\n";
    else
      cout << minn << ".0000000\n";
  }
}
