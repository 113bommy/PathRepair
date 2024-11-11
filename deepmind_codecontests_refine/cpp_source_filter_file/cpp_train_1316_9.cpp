#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int INF = 1e9 + 7;
int get_full_time(int y1, int x1, int y2, int x2, int x, int v) {
  if (y1 == y2) return abs(x1 - x2);
  int res = abs(x - x1);
  res += abs(x2 - x);
  int up = abs(y2 - y1);
  up = up / v + int(up % v != 0);
  res += up;
  return res;
}
void solve() {
  int n, m, cl, ce, v;
  cin >> n >> m >> cl >> ce >> v;
  vector<int> ls, es;
  for (int i = 0; i < cl; ++i) {
    int num;
    cin >> num;
    ls.push_back(num);
  }
  for (int i = 0; i < ce; ++i) {
    int num;
    cin >> num;
    es.push_back(num);
  }
  sort(ls.begin(), ls.end());
  sort(es.begin(), es.end());
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int ans = INF;
    if (!ls.empty()) {
      auto it = lower_bound(ls.begin(), ls.end(), x1);
      if (it == ls.end()) it--;
      int cur = get_full_time(x1, y1, x2, y2, *it, 1);
      ans = min(ans, cur);
      if (it != ls.begin()) it--;
      cur = get_full_time(x1, y1, x2, y2, *it, 1);
      ans = min(ans, cur);
    }
    if (!es.empty()) {
      auto it = lower_bound(es.begin(), es.end(), x1);
      if (it == es.end()) it--;
      int cur = get_full_time(x1, y1, x2, y2, *it, v);
      ans = min(ans, cur);
      if (it != es.begin()) it--;
      cur = get_full_time(x1, y1, x2, y2, *it, v);
      ans = min(ans, cur);
    }
    cout << ans << '\n';
  }
}
int main() {
  solve();
  return 0;
}
