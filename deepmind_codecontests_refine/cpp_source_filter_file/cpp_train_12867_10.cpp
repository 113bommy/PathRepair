#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000ll * 1000ll * 1000ll * 3ll;
long long n, x, l, r, cost;
struct node {
  long long _l, _r, _cost;
  node() : _l(0), _r(0), _cost(0){};
  node(long long l, long long r, long long cost) {
    _l = l, _r = r, _cost = cost;
  }
};
map<long long, vector<node> > mm;
map<long long, vector<long long> > mm2;
bool comp(const node& a, const node& b) {
  if (a._l != b._l) return a._l < b._l;
  if (a._r != b._r) return a._r < b._r;
  return a._cost < b._cost;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> x;
  vector<node> vv(n);
  for (int i = 0; i < n; i++) {
    cin >> l >> r >> cost;
    vv[i] = node(l, r, cost);
    mm[r - l + 1].push_back(vv[i]);
  }
  for (auto& vv2 : mm) {
    int sz = vv2.second.size();
    sort(vv2.second.begin(), vv2.second.end(), comp);
    vector<long long>& vx = mm2[vv2.first];
    vx.resize(sz);
    int idx = sz - 1;
    while (idx >= 0) {
      if (idx == sz - 1)
        vx[idx] = vv2.second[idx]._cost;
      else
        vx[idx] = min(vx[idx + 1], vv2.second[idx]._cost);
      idx--;
    }
  }
  long long ans = INF;
  for (int i = 0; i < n; i++) {
    int len = x - (vv[i]._r - vv[i]._l + 1);
    int sz = mm[len].size(), val = vv[i]._r + 1;
    vector<node>& m = mm[len];
    vector<long long>& m2 = mm2[len];
    int lo = 0, hi = sz;
    while (lo < hi) {
      int mid = (lo + hi + 1) / 2;
      if (m[mid]._l <= val) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    if (lo < m.size() && m[lo]._l < val) lo++;
    if (lo < m.size() && m[lo]._l >= val) ans = min(ans, vv[i]._cost + m2[lo]);
  }
  if (ans == INF)
    cout << -1 << "\n";
  else
    cout << ans << "\n";
  return 0;
}
