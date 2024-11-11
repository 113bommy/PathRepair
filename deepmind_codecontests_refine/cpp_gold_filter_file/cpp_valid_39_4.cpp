#include <bits/stdc++.h>
using namespace std;
int min(int a, int b) {
  if (a <= b)
    return a;
  else
    return b;
}
int min_dis(int W, int H, int x1, int y1, int x2, int y2, int w, int h) {
  int dis = 1e9;
  if (h > H || w > W) {
    return -1;
  } else {
    if ((x2 - x1 + w) > W && (y2 - y1 + h) > H) {
      return -1;
    } else {
      if (w + (x2 - x1) <= W) {
        dis = min(dis, min(w - x1, w - (W - x2)));
      }
      if (h + (y2 - y1) <= H) {
        dis = min(dis, min(h - (H - y2), h - y1));
      }
    }
  }
  if (dis < 0) {
    dis = 0;
  }
  return dis;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int W, H;
    cin >> W >> H;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int w, h;
    cin >> w >> h;
    int dis = min_dis(W, H, x1, y1, x2, y2, w, h);
    cout << dis << endl;
  }
}
