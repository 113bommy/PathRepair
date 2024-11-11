#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  int r, x1, y1, x2, y2;
  while (cin >> r >> x1 >> y1 >> x2 >> y2) {
    double dis = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + 0.0);
    cout << ceil(dis / 2 / r) << endl;
  }
  return 0;
}
