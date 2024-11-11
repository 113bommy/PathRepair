#include <bits/stdc++.h>
using namespace std;
int x, y, xx, yy, q, v, n, m, lif, l;
vector<int> vlift, vl;
long long f_lift(int x, int y, int xx, int yy) {
  if (vlift.size() == 0) return 2e+9;
  int l = 0;
  int r = vlift.size() - 1;
  while (l < r) {
    int c = (l + r) / 2;
    if (vlift[c] < y)
      l = c + 1;
    else
      r = c;
  }
  int ans = 2e+9;
  if (l < vlift.size()) {
    ans = min(ans, abs(y - vlift[l]) + abs(yy - vlift[l]) +
                       (abs(x - xx) + v - 1) / v);
  }
  if (l - 1 >= 0) {
    ans = min(ans, abs(y - vlift[l - 1]) + abs(yy - vlift[l - 1]) +
                       (abs(x - xx) + v - 1) / v);
  }
  return ans;
}
long long f_l(int x, int y, int xx, int yy) {
  if (vl.size() == 0) return 2e+9;
  int l = 0;
  int r = vl.size() - 1;
  while (l < r) {
    int c = (l + r) / 2;
    if (vl[c] < y)
      l = c + 1;
    else
      r = c;
  }
  int ans = 2e+9;
  if (l < vl.size()) {
    ans = min(ans, abs(y - vl[l]) + abs(yy - vl[l]) + (abs(x - xx)));
  }
  if (l - 1 >= 0) {
    ans = min(ans, abs(y - vl[l - 1]) + abs(yy - vl[l - 1]) + (abs(x - xx)));
  }
  return ans;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin >> n >> m >> l >> lif >> v;
  for (int i = 0; i < l; ++i) {
    int x;
    cin >> x;
    vl.push_back(x);
  }
  for (int i = 0; i < lif; ++i) {
    int x;
    cin >> x;
    vlift.push_back(x);
  }
  sort(vl.begin(), vl.end());
  sort(vlift.begin(), vlift.end());
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> x >> y >> xx >> yy;
    if (x != xx) {
      cout << min(f_lift(x, y, xx, yy), f_l(x, y, xx, yy)) << endl;
    } else {
      cout << abs(yy - y) << endl;
    }
  }
  return 0;
}
