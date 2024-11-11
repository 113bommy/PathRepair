#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1}, dy[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int n, k, x[100100], y[100100], ans[100100];
short cnt[100001 * 301];
int evts[100100 * 2], evtcnt;
vector<int> ys, at;
void add(int y1, int y2, int x, int val) {
  for (int y = (y1), __ee = (y2 + 1); y < __ee; ++y) {
    ans[cnt[y]] += x - at[y];
    cnt[y] += val;
    at[y] = x;
  }
}
pair<int, int> decode(int i) {
  if (i >= 0)
    return make_pair(x[i], 1);
  else
    return make_pair(x[~i] + k, -1);
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = (0), __ee = (n); i < __ee; ++i) {
    cin >> x[i] >> y[i];
    for (int j = (y[i]), __ee = (y[i] + k); j < __ee; ++j) ys.push_back(j);
    evts[evtcnt++] = i;
    evts[evtcnt++] = ~i;
  }
  sort(ys.begin(), ys.end());
  ys.erase(unique(ys.begin(), ys.end()), ys.end());
  for (int i = (0), __ee = (n); i < __ee; ++i)
    y[i] = lower_bound(ys.begin(), ys.end(), y[i]) - ys.begin();
  ys.clear();
  ys.shrink_to_fit();
  at.resize((n + 1) * (k + 1) + 100);
  sort(evts, evts + evtcnt,
       [&](int a, int b) { return decode(a) < decode(b); });
  for (int i = (0), __ee = (evtcnt); i < __ee; ++i) {
    int e = evts[i];
    auto evt = decode(e);
    int x = evt.first, val = evt.second;
    int y1 = y[max(e, ~e)], y2 = y[max(e, ~e)] + k - 1;
    add(y1, y2, x, val);
  }
  for (int i = (1), __ee = (n + 1); i < __ee; ++i) cout << ans[i] << " ";
}
