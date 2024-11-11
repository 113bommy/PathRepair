#include <bits/stdc++.h>
using namespace std;
double a[10100], k, l, r, d, s;
int i, n;
int main() {
  cin >> n >> k;
  for (i = 0; i < n; i++) cin >> a[i];
  l = 0;
  r = 1000;
  while (l < r - 1e-8) {
    d = (l + r) * 0.5;
    s = 0;
    for (i = 0; i < n; i++)
      if (a[i] > d)
        s -= (a[i] - d) * (100 - k) * 0.01;
      else
        s += (d - a[i]);
    if (s < 0)
      l = d;
    else
      r = d;
  }
  printf("%.9f", r);
}
