#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, b, g;
  vector<int> x, y;
  map<int, int> xm, ym;
  cin >> n >> m;
  cin >> b;
  for (int i = 0; i < b; i++) {
    int xi;
    cin >> xi;
    x.push_back(xi);
    xm[xi] = 1;
  }
  cin >> g;
  for (int i = 0; i < g; i++) {
    int yj;
    cin >> yj;
    y.push_back(yj);
    ym[yj] = 1;
  }
  int c = 0;
  bool flag = 0;
  int h = 0;
  while (!flag) {
    int xii = c % n;
    int yii = c % m;
    if ((xm[xii] * ym[yii]) == 0) {
      if (xm[xii] == 1 || ym[yii] == 1) {
        xm[xii] = 1;
        ym[yii] = 1;
        h = h + 1;
      }
    }
    if (h == (n + m - b - g)) {
      cout << "Yes" << endl;
      break;
    }
    c = c + 1;
    if (c > n * m) {
      cout << "No" << endl;
      break;
    }
  }
  return 0;
}
