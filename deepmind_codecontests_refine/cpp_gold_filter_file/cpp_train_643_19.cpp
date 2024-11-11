#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sx, sy, up = 0, down = 0, left = 0, right = 0, x, y;
  cin >> n >> sx >> sy;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    if (x > sx) right++;
    if (x < sx) left++;
    if (y > sy) up++;
    if (y < sy) down++;
  }
  if (up >= down && up >= left && up >= right) {
    cout << up << endl;
    cout << sx << " " << (sy + 1);
  } else if (down >= up && down >= left && down >= right) {
    cout << down << endl;
    cout << sx << " " << (sy - 1);
  } else if (right >= down && right >= left && up <= right) {
    cout << right << endl;
    cout << (sx + 1) << " " << sy;
  } else if (left >= down && up <= left && left >= right) {
    cout << left << endl;
    cout << (sx - 1) << " " << sy;
  }
}
