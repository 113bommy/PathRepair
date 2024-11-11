#include <bits/stdc++.h>
using namespace std;
const int DIM = 5005;
const int INF = 1000000005;
const int MOD = 1000000007;
pair<int, int> pts[DIM];
int main(void) {
  int n;
  cin >> n;
  int xmn = INF, xmx = -INF, ymn = INF, ymx = -INF;
  for (int i = 1; i <= n; ++i) {
    int x, y;
    cin >> x >> y;
    pts[i] = make_pair(x + y, x - y);
    xmn = min(xmn, pts[i].first);
    ymn = min(ymn, pts[i].second);
    xmx = max(xmx, pts[i].first);
    ymx = max(ymx, pts[i].second);
  }
  int aux1 = -INF, aux2 = -INF;
  for (int i = 1; i <= n; ++i) {
    aux1 = max(aux1, min(max(xmx - pts[i].first, ymx - pts[i].second),
                         max(pts[i].first - xmn, pts[i].second - ymn)));
    aux2 = max(aux2, min(max(xmx - pts[i].first, pts[i].second - ymn),
                         max(pts[i].first - xmn, ymn - pts[i].second)));
  }
  int len = min(aux1, aux2), ans = 2;
  for (int i = 1; i <= n; ++i)
    if (max(max(xmx - pts[i].first, ymx - pts[i].second),
            max(pts[i].first - xmn, pts[i].second - ymn)) <= len)
      ans = (ans << 1) % MOD;
  if (aux1 == aux2 and xmn + len < xmx and ymn + len < ymx)
    ans = (ans << 1) % MOD;
  cout << len << endl << ans << endl;
  return 0;
}
