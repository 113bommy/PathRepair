#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int inf = 2e9;
int n, a[N], k, mn[N];
pair<int, int> ST[4 * N];
vector<pair<int, int> > v[N];
void build(int id, int l, int r) {
  if (l == r) {
    ST[id] = make_pair(a[l], l);
    return;
  }
  int mid = (l + r) / 2;
  build(id * 2, l, mid);
  build(id * 2 + 1, mid + 1, r);
  ST[id] = min(ST[id * 2], ST[id * 2 + 1]);
}
pair<int, int> get(int id, int l, int r, int L, int R) {
  if (r < L || R < l) return make_pair(inf, 0);
  if (L <= l && r <= R) return ST[id];
  int mid = (l + r) / 2;
  return min(get(id * 2, l, mid, L, R), get(id * 2 + 1, mid + 1, r, L, R));
}
void update(int id, int l, int r, int u, int x) {
  if (r == l && l == u) {
    ST[id].first = x;
    return;
  }
  if (u > r || u < l) return;
  int mid = (l + r) / 2;
  update(id * 2, l, mid, u, x);
  update(id * 2 + 1, mid + 1, r, u, x);
  ST[id] = min(ST[id * 2], ST[id * 2 + 1]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  build(1, 1, n);
  int l = 0, r;
  for (int i = 1; i <= n - k; i++) {
    mn[i] = get(1, 1, n, i + 1, i + k).first;
    if (a[i] <= mn[i]) {
      if (!l) l = i;
      r = i;
    }
  }
  if (!l) return cout << "YES", 0;
  if (r + 1 > l + k || r + k + 1 > n) return cout << "NO", 0;
  for (int i = r + 1; i <= n - k; i++) {
    pair<int, int> cur = get(1, 1, n, i + 1, i + k);
    update(1, 1, n, cur.second, inf);
    if (a[i] <= get(1, 1, n, i + 1, i + k).first)
      v[cur.second].push_back(make_pair(a[i], i));
    update(1, 1, n, cur.second, cur.first);
  }
  for (int i = 1; i <= n; i++) sort(v[i].rbegin(), v[i].rend());
  for (int i = r + k + 1; i <= n; i++) {
    if (a[i] >= a[l]) continue;
    for (int j = r + 1; j <= l + k; j++) {
      while (!v[i].empty() && v[i].back().first < j) v[i].pop_back();
      if (a[i] > mn[j] && (v[i].empty() || v[i].back().first > a[j]))
        return cout << "YES", 0;
    }
  }
  cout << "NO";
}
