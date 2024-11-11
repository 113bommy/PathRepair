#include <bits/stdc++.h>
using namespace std;
const int Inf = (int)1e9 + 7;
namespace {
void solve() {
  int n, m, cl, ce, v;
  cin >> n >> m >> cl >> ce >> v;
  vector<int> S(cl), E(ce);
  for (int i = 0; i < cl; i++) cin >> S[i];
  for (int i = 0; i < ce; i++) cin >> E[i];
  int q;
  cin >> q;
  while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (y1 > y2) {
      swap(x1, x2);
      swap(y1, y2);
    }
    vector<int> pos;
    auto sp1 = lower_bound(S.begin(), S.end(), y1);
    if (sp1 != S.end()) pos.push_back(*sp1);
    if (sp1 != S.begin()) pos.push_back(*prev(sp1));
    auto sp2 = lower_bound(S.begin(), S.end(), y2);
    if (sp2 != S.end()) pos.push_back(*sp2);
    if (sp2 != S.begin()) pos.push_back(*prev(sp2));
    int res = (x1 == x2 ? abs(x1 - x2) : Inf);
    for (int e : pos) res = min(res, abs(y1 - e) + abs(y2 - e) + abs(x1 - x2));
    pos.clear();
    auto ep1 = lower_bound(E.begin(), E.end(), y1);
    if (ep1 != E.end()) pos.push_back(*ep1);
    if (ep1 != E.begin()) pos.push_back(*prev(ep1));
    auto ep2 = lower_bound(E.begin(), E.end(), y2);
    if (ep2 != E.end()) pos.push_back(*ep2);
    if (ep2 != E.begin()) pos.push_back(*prev(ep2));
    for (int e : pos)
      res = min(res, abs(y1 - e) + abs(y2 - e) + (abs(x1 - x2) + v - 1) / v);
    cout << res << "\n";
  }
}
}  // namespace
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(9);
  cout << fixed;
  solve();
  return 0;
}
