#include <bits/stdc++.h>
using namespace std;
const bool debug = 0;
vector<long long int> tree, lazy;
void update(int ql, int qr, long long int val, int l, int r, int curr) {
  if (l > r) return;
  tree[curr] += lazy[curr];
  if (l != r) {
    lazy[2 * curr + 1] += lazy[curr];
    lazy[2 * curr + 2] += lazy[curr];
  }
  lazy[curr] = 0;
  if (ql > r || qr < l) return;
  if (ql <= l && qr >= r) {
    tree[curr] += val;
    if (l != r) {
      lazy[2 * curr + 1] += val;
      lazy[2 * curr + 2] += val;
    }
    return;
  }
  int mid = (l + r) / 2;
  update(ql, qr, val, l, mid, curr * 2 + 1);
  update(ql, qr, val, mid + 1, r, curr * 2 + 2);
  tree[curr] = max(tree[curr * 2 + 1], tree[curr * 2 + 2]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, p;
  cin >> n >> m >> p;
  vector<pair<int, int> > wp(n), am(m);
  vector<pair<pair<int, int>, int> > mon(p);
  tree.assign(4 * m + 1, 0);
  lazy.assign(4 * m + 1, 0);
  for (int i = 0; i < n; ++i) cin >> wp[i].first >> wp[i].second;
  for (int i = 0; i < m; ++i) cin >> am[i].first >> am[i].second;
  for (int i = 0; i < p; ++i)
    cin >> mon[i].first.first >> mon[i].first.second >> mon[i].second;
  sort(wp.begin(), wp.end());
  sort(am.begin(), am.end());
  sort(mon.begin(), mon.end());
  for (int i = 0; i < m; ++i) update(i, i, -am[i].second, 0, m - 1, 0);
  int cur = 0;
  long long int best = -1e18;
  for (int i = 0; i < n; ++i) {
    while (cur < p && mon[cur].first.first < wp[i].first) {
      int pos = upper_bound(am.begin(), am.end(),
                            pair<int, int>(mon[cur].first.second, 1e4)) -
                am.begin();
      update(pos, m - 1, mon[cur].second, 0, m - 1, 0);
      cur++;
    }
    best = max(best, tree[0] - wp[i].second);
  }
  cout << best;
  return 0;
}
