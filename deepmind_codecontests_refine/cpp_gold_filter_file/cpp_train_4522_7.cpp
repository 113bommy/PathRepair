#include <bits/stdc++.h>
using namespace std;
int main() {
  int y1, y2, i;
  char x1, x2;
  vector<string> v;
  cin >> x1 >> y1;
  cin >> x2 >> y2;
  while (x1 != x2 || y1 != y2) {
    if (x1 < x2 && y1 < y2) {
      x1++;
      y1++;
      v.push_back("RU");
    } else if (x1 > x2 && y1 > y2) {
      x1--;
      y1--;
      v.push_back("LD");
    } else if (x1 > x2 && y1 < y2) {
      x1--;
      y1++;
      v.push_back("LU");
    } else if (x1 < x2 && y1 > y2) {
      x1++;
      y1--;
      v.push_back("RD");
    } else if (x1 == x2) {
      if (y1 > y2) {
        y1--;
        v.push_back("D");
      } else {
        y1++;
        v.push_back("U");
      }
    } else if (y1 == y2) {
      if (x1 > x2) {
        x1--;
        v.push_back("L");
      } else {
        x1++;
        v.push_back("R");
      }
    }
  }
  cout << v.size() << endl;
  for (i = 0; i < v.size(); i++) cout << v[i] << endl;
  return 0;
}
