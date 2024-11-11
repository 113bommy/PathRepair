#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
template <class T>
typename T::value_type arr_sum(const T &v, int n) {
  typename T::value_type sum = 0;
  for (int i = (0); i < (n); ++i) sum += v[i];
  return sum;
}
struct Sync_stdio {
  Sync_stdio() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
  }
} _sync_stdio;
struct Z {
  int x;
  int y;
  int i;
};
vector<vector<int>> g;
vector<int> used;
vector<int> d;
void dfs0(int x) {
  used[x] = 1;
  int res = 1;
  for (auto i : g[x]) {
    if (used[i]) {
      continue;
    }
    dfs0(i);
    res += d[i];
  }
  d[x] = res;
}
vector<int> ans;
void dfs1(int x, vector<Z> v) {
  used[x] = 1;
  auto pos = min_element(v.begin(), v.end(), [](const Z &a, const Z &b) {
    return a.y == b.y ? a.x < b.x : a.y < b.y;
  });
  ans[pos->i] = x;
  Z t = *pos;
  v.erase(pos);
  sort(v.begin(), v.end(), [&t](const Z &a, const Z &b) {
    if (a.y == t.y) {
      return 0;
    }
    if (b.y == t.y) {
      return 1;
    }
    return (int)((a.x - t.x) * 1.0 / (a.y - t.y) <
                 (b.x - t.x) * 1.0 / (b.y - t.y));
  });
  int start = 0;
  for (auto i : g[x]) {
    if (used[i]) {
      continue;
    }
    vector<Z> t(d[i]);
    copy(v.begin() + start, v.begin() + start + d[i], t.begin());
    start += d[i];
    dfs1(i, t);
  }
}
int main() {
  int n;
  cin >> n;
  g.resize(n);
  used.resize(n);
  d.resize(n);
  ans.resize(n);
  for (int i = (0); i < (n - 1); ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector<Z> v(n);
  for (int i = (0); i < (n); ++i) {
    cin >> v[i].x >> v[i].y;
    v[i].i = i;
  }
  dfs0(0);
  used.assign(n, 0);
  dfs1(0, v);
  for (auto i : ans) {
    cout << i + 1 << " ";
  }
}
