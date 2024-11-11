#include <bits/stdc++.h>
using namespace std;
long long sol = (1LL << 62), solp;
struct pc {
  long long x, y;
};
pc a[1000000], b[1000000];
inline void Actualiz(long long val, long long cacat) {
  if (val < sol) {
    sol = val;
    solp = cacat;
  }
}
int main() {
  int m, n, i;
  long long v1, v2, v3, v4, ans;
  cin >> m >> n >> m;
  v1 = v2 = v3 = v4 = -(1LL << 62);
  for (i = 1; i <= m; ++i) {
    cin >> b[i].x >> b[i].y;
    v1 = max(v1, -b[i].x - b[i].y);
    v2 = max(v2, b[i].y - b[i].x);
    v3 = max(v3, b[i].x + b[i].y);
    v4 = max(v4, b[i].x - b[i].y);
  }
  cin >> n;
  for (i = 1; i <= n; ++i) {
    cin >> a[i].x >> a[i].y;
    ans = -(1LL << 62);
    ans = max(ans, a[i].x + a[i].y + v1);
    ans = max(ans, a[i].x - a[i].y + v2);
    ans = max(ans, -a[i].x - a[i].y + v3);
    ans = max(ans, -a[i].x + a[i].y + v4);
    Actualiz(ans, i);
  }
  cout << sol << "\n" << solp << "\n";
  return 0;
}
