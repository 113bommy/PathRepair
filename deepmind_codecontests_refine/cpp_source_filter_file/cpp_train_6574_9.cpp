#include <bits/stdc++.h>
using namespace std;
int n, xa, ya, xb, yb;
vector<int> row, col;
int ask(int x1, int y1, int x2, int y2) {
  cout << '?' << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
  fflush(stdout);
  int k;
  cin >> k;
  return k;
}
int search(int x, int flag) {
  if (flag == 0) {
    int left = 1, right = n, mid;
    while (left < right) {
      mid = left + (right - left) / 2;
      if (ask(x, left, x, mid) % 2)
        right = mid;
      else
        left = mid + 1;
    }
    return left;
  } else {
    int up = 1, down = n, mid;
    while (up < down) {
      mid = up + (down - up) / 2;
      if (ask(up, x, mid, x) % 2)
        down = mid;
      else
        up = mid + 1;
    }
    return up;
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if (ask(i, 1, i, n) % 2) row.push_back(i);
    if (ask(1, i, n, i) % 2) col.push_back(i);
  }
  if (row.size() && col.size()) {
    if (ask(row[0], col[0], row[0], col[0]) % 2) {
      xa = row[0];
      ya = col[1];
      xb = row[1];
      yb = col[1];
    } else {
      xa = row[0];
      ya = col[1];
      xb = row[1];
      yb = col[0];
    }
  } else if (row.size()) {
    xa = row[0];
    ya = search(row[0], 0);
    xb = row[1];
    yb = ya;
  } else {
    ya = col[0];
    xa = search(col[0], 1);
    yb = col[1];
    xb = xa;
  }
  cout << '!' << ' ' << xa << ' ' << ya << ' ' << xb << ' ' << yb << endl;
  return 0;
}
