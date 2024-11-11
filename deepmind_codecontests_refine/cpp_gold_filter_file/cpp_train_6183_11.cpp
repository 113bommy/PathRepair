#include <bits/stdc++.h>
using namespace std;
int l, d, v, g, r;
int main() {
  cin >> l >> d >> v >> g >> r;
  if (d % ((r + g) * v) >= g * v) {
    l += (r + g) * v - (d % ((r + g) * v));
  }
  printf("%.10lf", l * 1.0 / v);
}
