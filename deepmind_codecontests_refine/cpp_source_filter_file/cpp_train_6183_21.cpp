#include <bits/stdc++.h>
using namespace std;
int g, r, s, i;
double l, d, v;
int main() {
  cin >> l >> d >> v >> g >> r;
  s = g + r;
  for (i = 0; i <= 100000; i++)
    if (s * i * 1.0 <= d / v * 1.0 && s * (i + 1) * 1.0 >= d / v * 1.0) break;
  if (d / v * 1.0 <= g * 1.0)
    cout << fixed << setprecision(8) << l / v * 1.0;
  else
    cout << fixed << setprecision(8) << (i + 1) * s * 1.0 + (l - d) / v * 1.0;
  return 0;
}
