#include <bits/stdc++.h>
using namespace std;
double EPSILON = 1e-8;
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  int l, d, v, g, r;
  cin >> l >> d >> v >> g >> r;
  double time = (double)l / v;
  double traffic = fmod((double)d / v, (double)g + r);
  if (traffic > g - EPSILON) time += g + r - traffic;
  cout << fixed << setprecision(10) << time << '\n';
  return 0;
}
