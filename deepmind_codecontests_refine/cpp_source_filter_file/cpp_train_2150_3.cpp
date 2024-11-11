#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)2e5 + 7;
const int infint = (int)1e9 + 3;
const int MOD = (int)1e9 + 7;
const long long inf = (long long)1e18;
int n, x[MAXN], y[MAXN], ans, mn_bound, mx_bound;
multiset<int> up, down;
vector<int> v[2 * MAXN];
void shift(int u) {
  auto it = up.find(u);
  up.erase(it);
  down.insert(u);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  for (int i = 0; i < n; i++)
    if ((x[i] + y[i]) % 2) {
      up.insert(x[i] + y[i]);
      v[y[i] - x[i] + MAXN].push_back(x[i] + y[i]);
    }
  ans = 0;
  mn_bound = -MAXN + 1, mx_bound = MAXN - 1;
  for (auto u : v[0]) shift(u);
  for (int y = mn_bound; y <= mx_bound; y += 2) {
    int l = infint, r = -infint;
    if (down.size()) l = *down.begin(), r = *down.rbegin();
    int l2 = infint, r2 = -infint;
    if (up.size()) l2 = *up.begin(), r2 = *up.rbegin();
    l = max(l, l2), r = min(r, r2);
    if (r > l) {
      l++, r--;
      ans += (r - l) / 2 + 1;
    }
    for (auto u : v[y + 1 + MAXN]) shift(u);
  }
  for (int i = 0; i < 2 * MAXN; i++) v[i].clear();
  up.clear(), down.clear();
  for (int i = 0; i < n; i++)
    if ((x[i] + y[i]) % 2 == 0) {
      up.insert(x[i] + y[i]);
      v[y[i] - x[i] + MAXN].push_back(x[i] + y[i]);
    }
  mn_bound = -MAXN, mx_bound = MAXN;
  for (int y = mn_bound; y <= mx_bound; y += 2) {
    int l = infint, r = -infint;
    if (down.size()) l = *down.begin(), r = *down.rbegin();
    int l2 = infint, r2 = -infint;
    if (up.size()) l2 = *up.begin(), r2 = *up.rbegin();
    l = max(l, l2), r = min(r, r2);
    if (r > l) {
      l++, r--;
      ans += (r - l) / 2 + 1;
    }
    if (y != mx_bound)
      for (auto u : v[y + 1 + MAXN]) shift(u);
  }
  cout << ans;
}
