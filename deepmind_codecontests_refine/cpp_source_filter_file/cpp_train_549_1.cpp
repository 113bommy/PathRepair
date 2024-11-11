#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;
int main() {
  double vp, vd, t, f, c;
  while (cin >> vp >> vd >> t >> f >> c) {
    double st = t * vp;
    double del = vd - vp;
    if (del <= 0) {
      puts("0");
      continue;
    }
    int ans = 0;
    while (1) {
      double time = st / del;
      st += time * vp;
      if (st >= c) break;
      ++ans;
      st += vp * (f + 1);
    }
    cout << ans << '\n';
  }
  return 0;
}
