#include <bits/stdc++.h>
using namespace std;
int n, r, x, y, g = 3000000ll;
int ans;
vector<pair<pair<int, int>, pair<int, int> > > v;
class RangeTree {
 public:
  int _l, _r, maxi, lazy;
  RangeTree *left, *right;
  RangeTree(int l, int r) {
    _l = l;
    _r = r;
    maxi = 0;
    left = right = NULL;
  }
  void checkleft() {
    if (left == NULL) left = new RangeTree(_l, (_l + _r) / 2);
  }
  void checkright() {
    if (right == NULL) right = new RangeTree((_l + _r) / 2 + 1, _r);
  }
  void checklazy() {
    if (lazy != 0) {
      left->maxi += lazy;
      right->maxi += lazy;
      left->lazy += lazy;
      right->lazy += lazy;
      lazy = 0;
    }
  }
  void update(int k, int l, int r) {
    if (_r < l || _l > r) return;
    if (_l >= l && _r <= r) {
      maxi += k;
      lazy += k;
      return;
    }
    checkright();
    checkleft();
    checklazy();
    left->update(k, l, r);
    right->update(k, l, r);
    maxi = max(left->maxi, right->maxi);
  }
};
RangeTree rt(0, 9000005);
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> r;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    v.push_back({{x - y + r, -1}, {x + y - r, x + y + r}});
    v.push_back({{x - y - r - 1, +1}, {x + y - r, x + y + r}});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    rt.update(v[i].first.second, v[i].second.first + g, v[i].second.second + g);
    ans = max(ans, rt.maxi);
  }
  cout << ans << "\n";
  return 0;
}
