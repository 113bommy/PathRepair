#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, l, v1, v2, k, m, d;
  cin >> n >> l >> v1 >> v2 >> k;
  m = (int)(n / k) + !!((int)n % (int)k);
  d = l / (m - (v2 - v1) / (v1 + v2) * (m - 1));
  cout << fixed << setprecision(6) << d / v2 + (l - d) / v1;
}
