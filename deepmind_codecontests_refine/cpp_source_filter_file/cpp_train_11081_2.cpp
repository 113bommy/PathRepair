#include <bits/stdc++.h>
using namespace std;
char x[4][4];
int ha[10];
int main() {
  string a, b, c, d;
  cin >> a >> b >> c >> d;
  int a1 = (int)a.length() - 2, b1 = (int)b.length() - 2,
      c1 = (int)c.length() - 2, d1 = (int)d.length() - 2;
  bool aa1 = (a1 / 2 >= b1 && a1 / 2 >= c1 && a1 / 2 >= d1) ||
             (a1 <= b1 / 2 && a1 <= c1 / 2 && a1 <= d1 / 2);
  bool bb1 = (b1 / 2 >= a1 && b1 / 2 >= c1 && b1 / 2 >= d1) ||
             (b1 <= a1 / 2 && b1 <= c1 / 2 && b1 <= d1 / 2);
  bool cc1 = (c1 / 2 >= a1 && c1 / 2 >= b1 && c1 / 2 >= d1) ||
             (c1 <= b1 / 2 && c1 <= b1 / 2 && c1 <= d1 / 2);
  bool dd1 = (d1 / 2 >= a1 && d1 / 2 >= c1 && d1 / 2 >= b1) ||
             (d1 <= b1 / 2 && d1 <= c1 / 2 && d1 <= a1 / 2);
  if (aa1 + bb1 + cc1 + dd1 == 1) {
    if (aa1) cout << "A";
    if (bb1) cout << "B";
    if (cc1) cout << "C";
    if (dd1) cout << "D";
  } else
    cout << "C";
}
