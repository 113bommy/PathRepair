#include <bits/stdc++.h>
using namespace std;
int r, c;
int main() {
  pair<int, int> points[4];
  int index = 0;
  cin >> r >> c;
  int x1 = -1;
  int x2 = -1;
  int y2 = -1;
  int y1 = -1;
  int countx1 = 0;
  int countx2 = 0;
  int county1 = 0;
  int county2 = 0;
  for (int i = 0; i < r; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < c; j++) {
      if (s[j] == '*') {
        if (x1 == -1 || x1 == i) {
          x1 = i;
        } else if (x2 == -1) {
          x2 = i;
        }
        if (y1 == -1 || y1 == j) {
          y1 = j;
        } else if (y2 == -1) {
          y2 = j;
        }
        if (i == x1) {
          countx1++;
        } else {
          countx2++;
        }
        if (j == y1) {
          county1++;
        } else {
          county2++;
        }
      }
    }
  }
  if (countx1 > countx2) {
    cout << x2 + 1 << " ";
  } else {
    cout << x1 + 1 << " ";
  }
  if (county1 > county2) {
    cout << y2 + 1 << " ";
  } else {
    cout << y1 + 1 << " ";
  }
}
