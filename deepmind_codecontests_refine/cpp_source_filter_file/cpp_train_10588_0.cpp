#include <bits/stdc++.h>
using namespace std;
class node {
 public:
  int x;
  int y;
  bool operator<(const node &b) const {
    if (x != b.x) {
      return x < b.x;
    } else {
      return y > b.y;
    }
  }
};
int main() {
  node a[8];
  node b[8];
  for (int i = 0; i < 4; i++) {
    cin >> a[i].x >> a[i].y;
  }
  for (int i = 0; i < 4; i++) {
    cin >> b[i].x >> b[i].y;
  }
  sort(a, a + 4);
  sort(b, b + 4);
  int xb, yb;
  xb = (b[0].x + b[3].x) / 2;
  yb = (b[1].y + b[2].y) / 2;
  set<node> sa;
  bool flag = false;
  for (int i = a[1].x; i <= a[3].x; i++) {
    for (int j = a[1].y; j < a[0].y; j++) {
      node temp;
      temp.x = i;
      temp.y = j;
      sa.insert(temp);
    }
  }
  for (int i = b[0].x; i <= xb; i++) {
    if (flag) {
      break;
    }
    for (int j = b[0].y; j <= i - b[0].x + b[0].y; j++) {
      node temp;
      temp.x = i;
      temp.y = j;
      if (sa.find(temp) != sa.end()) {
        flag = true;
        break;
      }
    }
    if (flag) {
      break;
    }
    for (int j = b[0].y + 1; j >= b[0].y - i + b[0].x; j--) {
      node temp;
      temp.x = i;
      temp.y = j;
      if (sa.find(temp) != sa.end()) {
        flag = true;
        break;
      }
    }
  }
  for (int i = xb + 1; i <= b[3].x; i++) {
    if (flag) {
      break;
    }
    for (int j = b[0].y; j <= b[3].x - i + b[0].y; j++) {
      node temp;
      temp.x = i;
      temp.y = j;
      if (sa.find(temp) != sa.end()) {
        flag = true;
        break;
      }
    }
    if (flag) {
      break;
    }
    for (int j = b[0].y + 1; j >= b[3].y - b[3].x + i; j--) {
      node temp;
      temp.x = i;
      temp.y = j;
      if (sa.find(temp) != sa.end()) {
        flag = true;
        break;
      }
    }
  }
  if (flag) {
    cout << "YES" << endl;
  } else {
    cout << "no" << endl;
  }
  return 0;
}
