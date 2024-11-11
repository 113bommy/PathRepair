#include <bits/stdc++.h>
using namespace std;
char aa[100100];
int a[550][550];
int main() {
  int x, y, x0, y0;
  cin >> x >> y >> x0 >> y0;
  for (int i = 1; i <= x; i++)
    for (int j = 1; j <= y; j++) a[i][i] = 0;
  a[x0][y0] = 1;
  int sum = 1;
  scanf("%s", aa);
  int len = strlen(aa);
  cout << "1 ";
  for (int i = 0; i < len - 1; i++) {
    if (aa[i] == 'U') {
      x0--;
      if (x0 < 1) x0++;
      if (a[x0][y0] == 1)
        cout << "0 ";
      else {
        cout << "1 ";
        sum++;
        a[x0][y0] = 1;
      }
    }
    if (aa[i] == 'D') {
      x0++;
      if (x0 > x) x0--;
      if (a[x0][y0] == 1)
        cout << "0 ";
      else {
        cout << "1 ";
        sum++;
        a[x0][y0] = 1;
      }
    }
    if (aa[i] == 'L') {
      y0--;
      if (y0 < 1) y0++;
      if (a[x0][y0] == 1)
        cout << "0 ";
      else {
        cout << "1 ";
        sum++;
        a[x0][y0] = 1;
      }
    }
    if (aa[i] == 'R') {
      y0++;
      if (y0 > y) y0--;
      if (a[x0][y0] == 1)
        cout << "0 ";
      else {
        cout << "1 ";
        sum++;
        a[x0][y0] = 1;
      }
    }
  }
  cout << x * y - sum << endl;
  return 0;
}
