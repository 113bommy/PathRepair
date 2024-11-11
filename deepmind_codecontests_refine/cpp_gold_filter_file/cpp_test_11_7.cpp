#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct info {
  int maxi = 0;
};
struct segtree {
  int n;
  vector<info> t;
  segtree(int n) {
    this->n = n + 1;
    t.resize(n * 4);
  }
  void Merge(info &node, info &l, info &r) { node.maxi = max(l.maxi, r.maxi); }
  void update(int node, int l, int r, int i, int j, int add) {
    if (l > j || r < i) {
      return;
    }
    if (l >= i && r <= j) {
      t[node].maxi = add;
      return;
    }
    int mid = (l + r) / 2;
    update(node * 2, l, mid, i, j, add);
    update(node * 2 + 1, mid + 1, r, i, j, add);
    Merge(t[node], t[node * 2], t[node * 2 + 1]);
  }
  void update(int l, int add) { update(1, 0, n, l, l, add); }
  info query(int node, int l, int r, int i, int j) {
    if (l > j || r < i) {
      info x;
      return x;
    }
    if (l >= i && r <= j) {
      return t[node];
    }
    int mid = (l + r) / 2;
    info x = query(node * 2, l, mid, i, j);
    info y = query(node * 2 + 1, mid + 1, r, i, j);
    info ret;
    Merge(ret, x, y);
    return ret;
  }
  int query(int l, int r) {
    info ret = query(1, 0, n, l, r);
    return ret.maxi;
  }
};
int n;
vector<pair<pair<int, int>, int> > a;
segtree seg(N);
int dp[N];
bool comp(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b) {
  if (a.first.first == b.first.first) {
    return a.first.second > b.first.second;
  }
  return a.first.first < b.first.first;
}
void solve(int l, int r) {
  if (l > r) {
    return;
  }
  if (l == r) {
    dp[l] = max(dp[l], 1);
    return;
  }
  int m = (l + r) / 2;
  solve(l, m);
  vector<pair<pair<int, int>, int> > now;
  for (int i = l; i <= r; i++) {
    now.push_back(a[i]);
  }
  sort(now.begin(), now.end(), comp);
  for (int i = 0; i < now.size(); i++) {
    int x = now[i].first.first;
    int y = now[i].first.second;
    int id = now[i].second;
    if (id >= l && id <= m) {
      seg.update(y, dp[id]);
    } else {
      int q = seg.query(0, y);
      dp[id] = max(dp[id], q + 1);
    }
  }
  for (int i = 0; i < now.size(); i++) {
    int x = now[i].first.first;
    int y = now[i].first.second;
    int id = now[i].second;
    if (id >= l && id <= m) {
      seg.update(y, 0);
    }
  }
  solve(m + 1, r);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x;
    y = i - x;
    if (y >= 0) {
      int sz = a.size();
      a.push_back({{x, y}, sz});
    }
  }
  n = a.size();
  if (n == 0) {
    cout << "0\n";
    return 0;
  };
  solve(0, n - 1);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << "\n";
  return 0;
}
