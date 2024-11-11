#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int d, n, m;
vector<vector<int>> points;
struct FT {
  int ft[N];
  void update(int idx, int v) {
    while (idx < N) {
      ft[idx] += v;
      idx += idx & -idx;
    }
  }
  int query(int idx) {
    int ans = 0;
    while (idx > 0) {
      ans += ft[idx];
      idx -= idx & -idx;
    }
    return ans;
  }
};
FT lft, rgt, tp, bm;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> d >> n >> m;
  int x1, y1, x2, y2;
  for (int i = 1; i <= d; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    lft.update(x1, 1);
    rgt.update(x2, 1);
    tp.update(y1, 1);
    bm.update(y2, 1);
    points.push_back({x1, y1, x2, y2});
  }
  int cl, cr, ct, cb;
  cin >> cl >> cr >> ct >> cb;
  int ans = -1;
  for (int i = 0; i < d; i++) {
    vector<int> &v = points[i];
    int cntl = lft.query(v[2] - 1);
    if (v[0] != v[2]) cntl -= 1;
    if (cntl != cl) continue;
    int cntr = d - rgt.query(v[0]);
    if (v[0] != v[2]) cntr -= 1;
    if (cntr != cr) continue;
    int cntt = tp.query(v[3] - 1);
    if (v[1] != v[3]) cntt -= 1;
    if (cntt != ct) continue;
    int cntb = d - bm.query(v[1]);
    if (v[1] != v[3]) cntb -= 1;
    if (cntb != cb) continue;
    ans = i + 1;
    break;
  }
  cout << ans << '\n';
  return 0;
}
