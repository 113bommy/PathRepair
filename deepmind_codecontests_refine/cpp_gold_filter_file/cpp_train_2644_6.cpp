#include <bits/stdc++.h>
using namespace std;
struct T {
  int x, y;
};
T pares[5005];
int n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> pares[i].x >> pares[i].y;
  bool secortan = false;
  int pos = -1;
  int xx, yy, z = 0;
  for (int i = 1; i <= n && pos <= n; i++) {
    int c = 0;
    for (int j = 1; j <= n; j++)
      if (i != j) {
        int x = max(pares[i].x, pares[j].x);
        int y = min(pares[i].y, pares[j].y);
        if (y > x) {
          secortan = true;
          if (!c) {
            xx = i;
            yy = j;
          }
          c++;
          z++;
        }
      }
    if (c > 1) {
      if (pos == -1)
        pos = i;
      else
        pos = n + 1;
    }
  }
  if (pos == n + 1)
    cout << 0;
  else if (!secortan) {
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
      cout << i;
      if (i != n) cout << " ";
    }
  } else if (z == 2)
    cout << 2 << endl << yy << " " << xx;
  else
    cout << 1 << endl << pos;
  return 0;
}
