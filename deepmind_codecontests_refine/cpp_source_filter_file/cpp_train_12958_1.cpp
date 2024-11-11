#include <bits/stdc++.h>
using namespace std;
struct CoordInt {
  int x, y;
};
int main() {
  int n;
  cin >> n;
  vector<CoordInt> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].x;
    cin >> v[i].y;
  }
  int idx_min_x = 0, idx_max_x = 0, idx_min_y = 0, idx_max_y = 0;
  for (int i = 1; i < n; i++) {
    if (v[i].x < v[idx_min_x].x) {
      idx_min_x = i;
    } else if (v[i].x > v[idx_max_x].x) {
      idx_max_x = i;
    }
    if (v[i].y < v[idx_min_y].y) {
      idx_min_y = i;
    } else if (v[i].y > v[idx_max_y].y) {
      idx_max_y = i;
    }
  }
  vector<CoordInt> v2(n);
  for (int i = 1; i < n; i++) {
    v2[i].x = v[i].x - v[i].y;
    v2[i].y = v[i].x + v[i].y;
  }
  int idx_min_x_2 = 0, idx_max_x_2 = 0, idx_min_y_2 = 0, idx_max_y_2 = 0;
  for (int i = 1; i < n; i++) {
    if (v2[i].x < v2[idx_min_x_2].x) {
      idx_min_x_2 = i;
    } else if (v2[i].x > v[idx_max_x_2].x) {
      idx_max_x_2 = i;
    }
    if (v2[i].y < v2[idx_min_y_2].y) {
      idx_min_y_2 = i;
    } else if (v2[i].y > v2[idx_max_y_2].y) {
      idx_max_y_2 = i;
    }
  }
  int count = 0;
  vector<CoordInt> cs = {v[idx_min_x_2], v[idx_min_x],   v[idx_min_y_2],
                         v[idx_min_y],   v[idx_max_x_2], v[idx_max_x],
                         v[idx_max_y_2], v[idx_max_y]};
  cs[0].x--;
  cs[1].x--;
  cs[2].x--;
  cs[3].y--;
  cs[4].x++;
  cs[5].x++;
  cs[6].x++;
  cs[7].y++;
  int j = 0;
  bool state = true;
  CoordInt a, b;
  for (int i = 0; i < cs.size(); i++) {
    if (j == 2) {
      if (state) {
        state = false;
      } else {
        state = true;
      }
      j = 0;
    }
    a = cs[i];
    b = cs[(i + 1) % cs.size()];
    if (state) {
      count += abs(a.y - b.y);
    } else {
      count += abs(a.x - b.x);
    }
    j++;
  }
  cout << count;
  return 0;
}
