#include <bits/stdc++.h>
using namespace std;
int g, r, s, i;
double l, d, v;
int main() {
  cin >> l >> d >> v >> g >> r;
  s = g + r;
  for (i = 0; i <= 10000; i++)
    if (s * i * 1.0 <= d / v && s * (i + 1) * 1.0 >= d / v) break;
  if (d / v * 1.0 <= g * 1.0)
    cout << fixed << setprecision(8) << l / v;
  else
    cout << fixed << setprecision(8) << (i + 1) * s * 1.0 + (l - d) / v;
  return 0;
}
