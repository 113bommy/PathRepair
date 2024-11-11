#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, sx, sy, x, y;
  cin >> n >> sx >> sy;
  long long int a = 0, b = 0, c = 0, d = 0;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    if (x > sx && y > sy) {
      b++;
      c++;
    } else if (x > sx && y < sy) {
      c++;
      d++;
    } else if (x < sx && y > sy) {
      b++;
      a++;
    } else if (x < sx && y < sy) {
      a++;
      d++;
    } else if (x == sx) {
      if (y > sy)
        b++;
      else
        d++;
    } else if (y == sy) {
      if (x > sx)
        c++;
      else
        a++;
    }
  }
  if (sx == 0) a = 0;
  if (sx == 1000000000) c = 0;
  if (sy == 0) d = 0;
  if (sy == 1000000000) b = 0;
  if (a == max(a, max(b, max(c, d)))) {
    cout << a << endl;
    cout << sx - 1 << " " << sy;
  } else if (b == max(a, max(b, max(c, d)))) {
    cout << b << endl;
    cout << sx << " " << sy + 1;
  } else if (c == max(a, max(b, max(c, d)))) {
    cout << c << endl;
    cout << sx + 1 << " " << sy;
  } else {
    cout << d << endl;
    cout << sx << " " << sy - 1;
  }
}
