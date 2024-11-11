#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1 << 20);
const int inf = (int)1e9 + 42;
struct point {
  int x, y;
  point() {
    x = 0;
    y = 0;
  }
  point(int _x, int _y) {
    x = _x;
    y = _y;
  }
};
struct event {
  int add, x, y, lower, upper;
  event() {
    add = 0;
    x = 0;
    y = 0;
    lower = 0;
    upper = 0;
  }
  event(int _x, int _y, int _lower, int _upper, int _add) {
    lower = _lower;
    upper = _upper;
    add = _add;
    x = _x;
    y = _y;
  }
};
bool operator<(const event& a, const event& b) {
  if (a.y != b.y) return a.y < b.y;
  if (a.x != b.x) return a.x < b.x;
  if (a.add != b.add) return a.add < b.add;
  if (a.lower != b.lower) return a.lower < b.lower;
  return a.upper < b.upper;
}
int n, k;
point a[MAXN];
void read() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
}
int ans[MAXN];
vector<event> e;
void solve() {
  vector<int> lix, xcord, cnt, last;
  for (int i = 0; i < n; i++) lix.push_back(a[i].x);
  sort(lix.begin(), lix.end());
  lix.erase(unique(lix.begin(), lix.end()), lix.end());
  for (int i = 0; i < n; i++) {
    int low = lix[i] - k + 1;
    if (!xcord.empty() && xcord.back() >= lix[i] - k + 1)
      low = xcord.back() + 1;
    for (int j = low; j <= lix[i]; j++) xcord.push_back(j);
  }
  for (int i = 0; i < n; i++) {
    e.push_back(event(a[i].x, a[i].y - k + 1, a[i].x - k + 1, a[i].x, 1));
    e.push_back(event(a[i].x, a[i].y + 1, a[i].x - k + 1, a[i].x, -1));
  }
  for (auto& x : e) {
    x.lower = lower_bound(xcord.begin(), xcord.end(), x.lower) - xcord.begin();
    x.upper = lower_bound(xcord.begin(), xcord.end(), x.upper) - xcord.begin();
  }
  int sz = xcord.size();
  xcord.clear();
  xcord.shrink_to_fit();
  last.resize(sz);
  cnt.resize(sz);
  sort(e.begin(), e.end());
  for (int i = 0; i < last.size(); i++) cnt[i] = 0, last[i] = -inf;
  for (auto it : e)
    for (int x = it.lower; x <= it.upper; x++) {
      if (last[x] != -inf) ans[cnt[x]] += it.y - last[x];
      cnt[x] += it.add;
      last[x] = it.y;
    }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  read();
  solve();
  return 0;
}
