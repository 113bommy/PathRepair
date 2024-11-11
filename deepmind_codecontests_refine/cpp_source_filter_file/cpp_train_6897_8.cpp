#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, k, s[N], id[4][N], sum[N];
pair<int, int> ST[4 * N];
vector<pair<int, int>> type[4];
bool mark[N];
pair<int, int> add(pair<int, int> a, pair<int, int> b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
pair<int, int> get(int id, int l, int r, int L, int R) {
  if (r < L || R < l) return make_pair(0, 0);
  if (L <= l && r <= R) return ST[id];
  int mid = (l + r) / 2;
  return add(get(id * 2, l, mid, L, R), get(id * 2 + 1, mid + 1, r, L, R));
}
void update(int id, int l, int r, int u, pair<int, int> x) {
  if (r == l && l == u) {
    ST[id] = x;
    return;
  }
  if (u > r || u < l) return;
  int mid = (l + r) / 2;
  update(id * 2, l, mid, u, x);
  update(id * 2 + 1, mid + 1, r, u, x);
  ST[id] = add(ST[id * 2], ST[id * 2 + 1]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    int z, a, b;
    cin >> z >> a >> b;
    pair<int, int> t = make_pair(z, i);
    if (a == 0 && b == 0)
      type[0].push_back(t);
    else if (a == 1 && b == 0)
      type[1].push_back(t);
    else if (a == 0 && b == 1)
      type[2].push_back(t);
    else
      type[3].push_back(t);
  }
  for (int i = 0; i < 4; i++) sort(type[i].begin(), type[i].end());
  for (int i = 0; i < min(type[1].size(), type[2].size()); i++)
    sum[i + 1] = sum[i] + type[1][i].first + type[2][i].first;
  vector<tuple<int, int, int>> val;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < type[i].size(); j++)
      val.push_back(make_tuple(type[i][j].first, i, j));
  }
  sort(val.begin(), val.end());
  for (int z = 0; z < val.size(); z++) {
    int t, i, j;
    tie(t, i, j) = val[z];
    id[i][j] = z + 1;
  }
  int sz = val.size();
  int res = 2e9 + 1;
  for (int i = 0; i < type[0].size(); i++)
    update(1, 1, sz, id[0][i], make_pair(type[0][i].first, 1));
  for (int i = k; i < type[1].size(); i++)
    update(1, 1, sz, id[1][i], make_pair(type[1][i].first, 1));
  for (int i = k; i < type[2].size(); i++)
    update(1, 1, sz, id[2][i], make_pair(type[2][i].first, 1));
  int lef = m - k * 2;
  int chose = -1;
  int g = 0;
  int h = 0;
  if (lef >= 0 && k <= min(type[1].size(), type[2].size())) {
    int take = 0;
    if (lef != 0) {
      int l = 1, r = sz;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (get(1, 1, sz, 1, mid).second <= lef) {
          take = mid;
          l = mid + 1;
        } else
          r = mid - 1;
      }
    }
    if (get(1, 1, sz, 1, take).second == lef &&
        res > sum[k] + get(1, 1, sz, 1, take).first) {
      res = sum[k] + get(1, 1, sz, 1, take).first;
      h = k;
      chose = 0;
      g = take;
    }
  }
  int cur = 0;
  int now = k;
  int upd = k;
  for (int i = 0; i < type[3].size(); i++) {
    now--;
    if (now >= 0) {
      if (now < type[1].size())
        update(1, 1, sz, id[1][now], make_pair(type[1][now].first, 1));
      if (now < type[2].size())
        update(1, 1, sz, id[2][now], make_pair(type[2][now].first, 1));
    }
    cur += type[3][i].first;
    int need = max(k - i - 1, 0);
    if (need > min(type[1].size(), type[2].size())) continue;
    int lef = m - (i + 1) - need * 2;
    if (lef < 0) continue;
    int take = 0;
    if (lef != 0) {
      int l = 1, r = sz;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (get(1, 1, sz, 1, mid).second <= lef) {
          take = mid;
          l = mid + 1;
        } else
          r = mid - 1;
      }
    }
    if (get(1, 1, sz, 1, take).second == lef &&
        res > cur + sum[need] + get(1, 1, sz, 1, take).first) {
      res = cur + sum[need] + get(1, 1, sz, 1, take).first;
      chose = i + 1;
      upd = max(now, 0);
      g = take;
      h = need;
    }
  }
  for (int i = 1; i <= 4 * n; i++) ST[i] = make_pair(0, 0);
  if (res == 1e9) return cout << -1, 0;
  vector<int> ans;
  for (int i = 0; i < chose; i++) ans.push_back(type[3][i].second);
  for (int i = 0; i < type[0].size(); i++)
    update(1, 1, sz, id[0][i], make_pair(type[0][i].first, 1));
  for (int i = upd; i < type[1].size(); i++)
    update(1, 1, sz, id[1][i], make_pair(type[1][i].first, 1));
  for (int i = upd; i < type[2].size(); i++)
    update(1, 1, sz, id[2][i], make_pair(type[2][i].first, 1));
  for (int i = 1; i <= g; i++)
    if (get(1, 1, sz, i, i).second == 1) mark[i] = true;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < type[i].size(); j++)
      if (mark[id[i][j]]) ans.push_back(type[i][j].second);
  }
  for (int i = 0; i < h; i++) {
    ans.push_back(type[1][i].second);
    ans.push_back(type[2][i].second);
  }
  cout << res << '\n';
  for (auto& x : ans) cout << x << ' ';
}
