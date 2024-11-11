#include <bits/stdc++.h>
using namespace std;
inline int mod(int x) {
  if (x < 0) {
    return -x;
  }
  return x;
}
int main() {
  string s;
  cin >> s;
  s = " " + s;
  int count_x[100002], count_y[100002], count_z[100002], i;
  count_x[0] = count_y[0] = count_z[0] = 0;
  for (i = 1; i <= s.length(); i++) {
    count_x[i] = count_x[i - 1];
    count_y[i] = count_y[i - 1];
    count_z[i] = count_z[i - 1];
    if (s[i] == 'x') {
      count_x[i]++;
    } else if (s[i] == 'y') {
      count_y[i]++;
    } else if (s[i] == 'z') {
      count_z[i]++;
    }
  }
  int q, x, y, xc, yc, zc;
  cin >> q;
  while (q--) {
    cin >> x >> y;
    if (y - x < 3) {
      cout << "YES" << endl;
      continue;
    }
    xc = count_x[y] - count_x[x - 1];
    yc = count_y[y] - count_y[x - 1];
    zc = count_z[y] - count_z[x - 1];
    if (mod(xc - yc) >= 2 or mod(yc - zc) >= 2 or mod(zc - xc) >= 2) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
  return 0;
}
