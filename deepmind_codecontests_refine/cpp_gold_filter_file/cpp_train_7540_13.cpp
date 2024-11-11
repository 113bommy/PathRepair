#include <bits/stdc++.h>
using namespace std;
int n;
char a[2004][2004];
int main() {
  cin >> n;
  int ext = 1000;
  int xi = ext, yi = ext, in, xj = ext, yj = ext;
  int mnx = xi, mxx = xi, mny = yi, mxy = yi;
  int o = 0;
  while (n--) {
    cin >> in;
    xj += in;
    if (o % 2)
      yj -= in;
    else
      yj += in;
    char c;
    if (yi > yj) {
      c = '\\';
      for (int i = xi, j = yi; i < xj && j > yj; i++, j--) a[j - 1][i] = c;
    } else {
      c = '/';
      for (int i = xi, j = yi; i < xj && j < yj; i++, j++) a[j][i] = c;
    }
    o++;
    mnx = min(mnx, xj);
    mxx = max(mxx, xj);
    mny = min(mny, yj);
    mxy = max(mxy, yj);
    xi = xj;
    yi = yj;
  }
  for (int j = mxy - 1; j >= mny; j--) {
    for (int i = mnx; i < mxx; i++)
      if (a[j][i] == '/' || a[j][i] == '\\')
        cout << a[j][i];
      else
        cout << " ";
    cout << endl;
  }
}
