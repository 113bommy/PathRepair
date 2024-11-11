#include <bits/stdc++.h>
using namespace std;
vector<int> px, py;
int k;
int xs, ys;
bool correct(int t) {
  vector<int> y, x;
  int cover[1001][1001];
  y.push_back(1);
  y.push_back(ys + 1);
  x.push_back(1);
  x.push_back(xs + 1);
  for (int i = 0; i < k; i++) {
    if (py[i] - t > 1) y.push_back(py[i] - t);
    if (py[i] + t + 1 <= ys) y.push_back(py[i] + t + 1);
    if (px[i] - t > 1) x.push_back(px[i] - t);
    if (px[i] + t + 1 <= xs) x.push_back(px[i] + t + 1);
  }
  sort(x.begin(), x.end());
  auto last = unique(x.begin(), x.end());
  x.erase(last, x.end());
  sort(y.begin(), y.end());
  last = unique(y.begin(), y.end());
  y.erase(last, y.end());
  memset(cover, 0, sizeof(cover));
  for (int i = 0; i < k; i++) {
    int xst = lower_bound(x.begin(), x.end(), max(1, px[i] - t)) - x.begin();
    int xe =
        lower_bound(x.begin(), x.end(), min(xs + 1, px[i] + t + 1)) - x.begin();
    int yst = lower_bound(y.begin(), y.end(), max(1, py[i] - t)) - y.begin();
    int ye =
        lower_bound(y.begin(), y.end(), min(ys + 1, py[i] + t + 1)) - y.begin();
    cover[xst][yst]++;
    cover[xst][ye]--;
    cover[xe][yst]--;
    cover[xe][ye]++;
  }
  int minX = xs + 1, maxX = 0;
  int minY = ys + 1, maxY = 0;
  for (int xi = 0; xi < (int)x.size(); xi++) {
    for (int yi = 0; yi < (int)y.size(); yi++) {
      if (xi > 0 and yi > 0) {
        cover[xi][yi] +=
            cover[xi - 1][yi] + cover[xi][yi - 1] - cover[xi - 1][yi - 1];
      } else if (xi > 0) {
        cover[xi][yi] += cover[xi - 1][yi];
      } else if (yi > 0) {
        cover[xi][yi] += cover[xi][yi - 1];
      }
      if (cover[xi][yi] <= 0) {
        if (x[xi] <= xs and y[yi] <= ys) {
          minX = min(minX, x[xi]);
          maxX = max(maxX, x[xi + 1] - 1);
          minY = min(minY, y[yi]);
          maxY = max(maxY, y[yi + 1] - 1);
        }
      }
    }
  }
  if (maxX == 0) return true;
  int l = max(maxX - minX, maxY - minY);
  return (l <= t * 2);
}
int main() {
  cin >> xs >> ys >> k;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    px.push_back(x);
    py.push_back(y);
  }
  int minv = 0, maxv = max(xs, ys) / 2;
  while (minv < maxv) {
    int t = (minv + maxv) / 2;
    if (correct(t)) {
      maxv = t;
    } else
      minv = t + 1;
  }
  cout << minv;
  return 0;
}
