#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 20;
vector<pair<int, int> > seg[maxn * 4];
vector<int> prefix_min[maxn * 4];
int a[maxn], nex1[maxn], d[maxn], ans;
map<int, int> mp;
void build(int s, int e, int v) {
  if (e - s < 2) {
    seg[v].push_back({nex1[s], d[s]});
    prefix_min[v].push_back(1e7);
    prefix_min[v].push_back(d[s]);
    return;
  }
  int m = (s + e) / 2;
  build(s, m, 2 * v);
  build(m, e, 2 * v + 1);
  int pt1 = 0, pt2 = 0;
  while (pt1 < (int)seg[2 * v].size() && pt2 < (int)seg[2 * v + 1].size()) {
    if (seg[2 * v][pt1] < seg[2 * v + 1][pt2])
      seg[v].push_back(seg[2 * v][pt1]), pt1++;
    else
      seg[v].push_back(seg[2 * v + 1][pt2]), pt2++;
  }
  while (pt1 < (int)seg[2 * v].size()) seg[v].push_back(seg[2 * v][pt1]), pt1++;
  while (pt2 < (int)seg[2 * v + 1].size())
    seg[v].push_back(seg[2 * v + 1][pt2]), pt2++;
  prefix_min[v].push_back(1e7);
  for (int i = 0; i < (int)seg[v].size(); i++) {
    prefix_min[v].push_back(min(prefix_min[v].back(), seg[v][i].second));
  }
}
void get(int l, int r, int s, int e, int v) {
  if (l <= s && e <= r) {
    pair<int, int> x = {r, -1};
    int k = lower_bound(seg[v].begin(), seg[v].end(), x) - seg[v].begin();
    ans = min(ans, prefix_min[v][k]);
    return;
  }
  if (r <= s || e <= l) return;
  int m = (s + e) / 2;
  get(l, r, s, m, 2 * v);
  get(l, r, m, e, 2 * v + 1);
}
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = n; i > 0; i--) {
    if (mp[a[i]]) {
      nex1[i] = mp[a[i]];
      d[i] = nex1[i] - i;
    } else {
      nex1[i] = n + 1;
      d[i] = 1e7;
    }
    mp[a[i]] = i;
  }
  build(1, n + 1, 1);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    r++;
    ans = 1e7;
    get(l, r, 1, n + 1, 1);
    if (ans >= n) ans = -1;
    printf("%d", ans);
  }
}
