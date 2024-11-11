#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int x1, y1, x2, y2, n, q[1000][3], a[10000], b[10000],
      z = 0, minx, maxx, miny, maxy, countx = 0, flag = 0;
  cin >> x1 >> y1 >> x2 >> y2 >> n;
  for (long long int i = 0; i < n; i++)
    for (long long int j = 0; j < 3; j++) cin >> q[i][j];
  minx = min(x1, x2);
  maxx = max(x1, x2);
  miny = min(y1, y2);
  maxy = max(y1, y2);
  for (long long int i = miny; i <= maxy; i++) {
    a[z] = minx;
    b[z] = i;
    z++;
  }
  for (long long int i = miny; i <= maxy; i++) {
    a[z] = maxx;
    b[z] = i;
    z++;
  }
  for (long long int i = minx + 1; i <= maxx - 1; i++) {
    a[z] = i;
    b[z] = miny;
    z++;
  }
  for (long long int i = minx + 1; i <= maxx - 1; i++) {
    a[z] = i;
    b[z] = maxy;
    z++;
  }
  for (long long int i = 0; i < z; i++) {
    flag = 0;
    for (long long int j = 0; j < n; j++) {
      if (pow(a[i] - q[j][0], 2) + pow(b[i] - q[j][1], 2) <= pow(q[j][2], 2)) {
        countx++;
        break;
      }
    }
  }
  cout << z - countx << endl;
  return 0;
}
