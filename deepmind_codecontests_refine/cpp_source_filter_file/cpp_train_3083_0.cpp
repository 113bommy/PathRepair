#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
int a[505][505];
struct p {
  int x, y, t;
  bool operator<(const p &p1) const { return t < p1.t; }
} ps[250005];
int n, m, k, q, hi, lo, mid, ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k >> q;
  for (int i = 0; i < q; i++) cin >> ps[i].x >> ps[i].y >> ps[i].t;
  sort(ps, ps + q);
  hi = INF, lo = 1, ans = -1;
  while (hi >= lo) {
    mid = (hi + lo) / 2;
    memset(a, 0, sizeof a);
    for (int i = 0; i < q; i++) {
      if (ps[i].t > mid) break;
      a[ps[i].x][ps[i].y] = 1;
    }
    bool b = false;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        if (i >= k && j >= k &&
            a[i][j] - a[i - k][j] - a[i][j - k] + a[i - k][j - k] >= k * k)
          b = true;
      }
    }
    if (b)
      ans = mid, hi = mid - 1;
    else
      lo = mid + 1;
  }
  cout << ans;
  return 0;
}
