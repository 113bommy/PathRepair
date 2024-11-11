#include <bits/stdc++.h>
using namespace std;
const int Z = 3 * (int)1e3 + 111;
const int N = 3 * (int)1e5 + 111;
const int INF = (int)1e9 + 111;
const int MOD = (int)1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  double l, d, v, g, r;
  cin >> l >> d >> v >> g >> r;
  double t(0);
  t = d / v;
  if (int(t + 1) % int(g + r) <= g) {
    if (int(t) % int(g + r) >= g) t = int(t) + 1;
  } else {
    t += (g + r) - int(t);
  }
  t += (l - d) / v;
  cout << setprecision(20) << t;
}
