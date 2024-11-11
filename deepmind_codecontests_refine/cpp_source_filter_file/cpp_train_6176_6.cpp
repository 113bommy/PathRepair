#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
long long n, m, k, x, y, ans;
int main() {
  cin >> n >> m >> x >> y >> k;
  while (k--) {
    int v1, v2;
    cin >> v1 >> v2;
    long long tp1 = inf, tp2 = inf;
    if (v1 > 0)
      tp1 = (n - x) / v1;
    else if (v1 < 0)
      tp1 = (x - 1) / (-v1);
    if (v2 > 0)
      tp2 = (m - x) / v2;
    else if (v2 < 0)
      tp2 = (x - 1) / (-v2);
    int sp = min(tp2, tp1);
    ans += sp;
    x += sp * v1;
    y += sp * v2;
  }
  cout << ans << endl;
  return 0;
}
