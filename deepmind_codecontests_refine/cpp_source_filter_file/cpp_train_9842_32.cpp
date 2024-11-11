#include <bits/stdc++.h>
using namespace std;
const double pi = 2 * acos(0.0);
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  double d, h, v, e, tot, inc;
  cin >> d >> h >> v >> e;
  if (v / (pi * d * d / 4) > e) {
    printf("%f\n", h / (v / (pi * d * d / 4) - e));
  } else
    cout << "NO\n";
  return 0;
}
