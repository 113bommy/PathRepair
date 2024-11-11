#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
vector<vector<ii>> t;
int n, tt;
vector<int> lo, hi, bit;
vector<pair<long long, int>> p, a;
void dfs(int u = 0) {
  lo[u] = hi[u] = tt++;
  p[u].second = u;
  for (auto [v, w] : t[u]) {
    p[v].first = w + p[u].first;
    dfs(v);
    hi[u] = max(hi[u], hi[v]);
  }
}
void upd(int k, int x) {
  for (++k; k <= n; k += k & -k) bit[k] += x;
}
int query(int k) {
  int a = 0;
  for (++k; k > 0; k -= k & -k) a += bit[k];
  return a;
}
void solve() {
  cin >> n;
  vector<int> cnt(n, 0);
  bit.assign(n + 1, 0);
  t.resize(n);
  lo.resize(n);
  hi.resize(n);
  p.assign(n, make_pair(0LL, 0));
  a.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i].first;
  for (int i = 1; i < n; ++i) {
    int pai, w;
    cin >> pai >> w;
    t[pai - 1].push_back({i, w});
  }
  dfs();
  for (int i = 0; i < n; ++i) {
    a[i].first -= p[i].first;
    a[i].second = i;
    p[i].first *= -1;
  }
  sort(a.rbegin(), a.rend());
  sort(p.rbegin(), p.rend());
  for (int i = 0, j = 0; j < n; ++j) {
    for (; i < n && a[i].first >= p[j].first; ++i) upd(lo[a[i].second], 1);
    cnt[p[j].second] = query(hi[p[j].second]) - query(lo[p[j].second]);
  }
  for (int v = 0; v < n; ++v) cout << cnt[v] << ' ';
  cout << '\n';
}
signed main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
