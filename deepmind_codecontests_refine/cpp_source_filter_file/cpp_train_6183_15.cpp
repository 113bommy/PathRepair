#include <bits/stdc++.h>
using namespace std;
int main() {
  float l, d, v, g, r, t1, t2, temp;
  cin >> l >> d >> v >> g >> r;
  t1 = d / v;
  int count = 0;
  while (t1 >= g + r) {
    t1 -= (g + r);
    count++;
  }
  if (t1 <= g) {
    t1 = t1 + count * (g + r);
  } else {
    t1 = (count + 1) * (g + r);
  }
  t2 = (l - d) / v;
  cout << setprecision(8) << t1 + t2;
  return 0;
}
