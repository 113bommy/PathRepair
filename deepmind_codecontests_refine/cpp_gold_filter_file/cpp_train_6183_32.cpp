#include <bits/stdc++.h>
using namespace std;
int main() {
  int l, g, r, v, d;
  double ldiv;
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(6);
  scanf("%d %d %d %d %d", &l, &d, &v, &g, &r);
  ldiv = double(d) / v;
  if (ldiv >= g) {
    ldiv = (r + g) * ceil(d * 1.0 / (v * (r + g))) +
           double(double((l - d)) / double(v));
  } else {
    ldiv = double(l) / v;
  }
  cout << ldiv << endl;
}
