#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int d1 = min(x1, x2);
  int d2 = min(y1, y2);
  bool ft = 0;
  if (x1 + y1 <= max(x2, y2)) {
    printf("Polycarp\n");
    return 0;
  }
  for (int i = 1; i <= d2; i++) {
    int t1 = y1 - i + x1 - d1;
    int sx = x2 - d2;
    int sy = y2 - i;
    int t2 = max(sx, sy);
    if (t1 > t2) {
      ft = 1;
    }
  }
  for (int i = 1; i <= d1; i++) {
    int t1 = x1 - i + y1 - d2;
    int sx = y2 - d1;
    int sy = x2 - i;
    int t2 = max(sx, sy);
    if (t1 > t2) {
      ft = 1;
    }
  }
  if (!ft)
    printf("Polycarp\n");
  else
    printf("Vasiliy\n");
}
