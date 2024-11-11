#include <bits/stdc++.h>
using namespace std;
int check(double h, double r) {
  if (h >= r * sqrt(3))
    return 3;
  else if (h >= (r / 2))
    return 2;
  else
    return 1;
}
int main() {
  double r, h0, h;
  cin >> r >> h0;
  long res1, res2;
  res1 = res2 = 0;
  h = h0;
  res1 = ((int)(h / r)) * 2;
  h -= res1 * r;
  res1 += check(h, r);
  h = h0;
  if (h <= r + r / 2 * sqrt(3)) {
    cout << res1;
    return 0;
  }
  int i = (int)((h - r) / (r / 2 * sqrt(3)));
  if (i >= 1)
    res2 = (i / 2 + 1) * 2 + (i + 1) / 2;
  else
    i = 0;
  h -= r + i * r / 2 * sqrt(3);
  res2 += check(h, r);
  cout << max(res1, res2);
  return 0;
}
