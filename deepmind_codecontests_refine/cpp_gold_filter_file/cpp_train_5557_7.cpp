#include <bits/stdc++.h>
using namespace std;
using lld = int64_t;
class S {
 public:
  lld solve(vector<pair<lld, lld>> &ps) {
    std::sort(ps.begin(), ps.end());
    lld n = ps.size();
    for (int i = 0; i < n - 1; ++i) {
      lld ki = ps[i].first;
      lld ai = ps[i].second;
      lld kip1 = ps[i + 1].first;
      lld aip1 = ps[i + 1].second;
      lld diff = kip1 - ki;
      lld needed_boxes;
      if (diff + 1 >= 60) {
        needed_boxes = 1;
      } else {
        lld denom = pow(4, diff) + 0.01;
        needed_boxes = ceil((double)(ai) / denom);
      }
      aip1 = std::max(aip1, needed_boxes);
      ps[i + 1].second = aip1;
    }
    lld ki = ps.back().first;
    lld ai = ps.back().second;
    lld res = ki + 1;
    lld itr = 0;
    lld increment = 0;
    while ((1 << itr) < ai) {
      itr += 2;
      ++increment;
    }
    ki += increment;
    res = std::max(res, (lld)ki);
    return res;
  }
  void solve() {
    lld n = 0;
    lld a, k;
    vector<pair<lld, lld>> ps;
    cin >> n;
    for (lld i = 0; i < n; ++i) {
      cin >> k >> a;
      ps.push_back({k, a});
    }
    lld res = solve(ps);
    cout << res << endl;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  S s;
  s.solve();
  return 0;
}
