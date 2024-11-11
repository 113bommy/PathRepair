#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, d, v, g, r;
  cin >> l >> d >> v >> g >> r;
  double res = (double)l / v;
  double cur = d / (double)v;
  while (cur > g + r) cur -= g + r;
  if (cur >= g) res += g + r - cur;
  cout.setf(ios_base::fixed);
  cout.precision(15);
  cout << res;
  return 0;
}
