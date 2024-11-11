#include <bits/stdc++.h>
using namespace std;
long long int n, m, cl, ce, v, a;
long long int q, xa, ya, xb, yb;
vector<long long int> ladder;
vector<long long int> elevator;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> cl >> ce >> v;
  for (long long int i = 0; i < cl; i++) {
    cin >> a;
    ladder.push_back(a);
  }
  for (long long int i = 0; i < ce; i++) {
    cin >> a;
    elevator.push_back(a);
  }
  cin >> q;
  while (q--) {
    cin >> xa >> ya >> xb >> yb;
    if (xa == xb) {
      cout << abs(xa - xb) << '\n';
      continue;
    }
    long long int ans = INT_MAX;
    long long int se, sl, b, c, d, e;
    if (ce != 0)
      se = lower_bound(elevator.begin(), elevator.end(), ya) - elevator.begin();
    if (cl != 0)
      sl = lower_bound(ladder.begin(), ladder.end(), ya) - ladder.begin();
    if (ce != 0) b = elevator[max(se - 1, 1LL * 0)];
    if (ce != 0) c = elevator[min(se, cl - 1)];
    if (cl != 0) d = ladder[max(sl - 1, 1LL * 0)];
    if (cl != 0) e = ladder[min(sl, cl - 1)];
    if (ce != 0)
      ans = min(ans, abs(ya - b) + (abs(xa - xb) + v - 1) / v + abs(yb - b));
    if (ce != 0)
      ans = min(ans, abs(ya - c) + (abs(xa - xb) + v - 1) / v + abs(yb - c));
    if (cl != 0) ans = min(ans, abs(ya - d) + abs(xa - xb) + abs(yb - d));
    if (cl != 0) ans = min(ans, abs(ya - e) + abs(xa - xb) + abs(yb - e));
    cout << ans << '\n';
  }
}
