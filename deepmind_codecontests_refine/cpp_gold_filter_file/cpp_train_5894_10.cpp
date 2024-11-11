#include <bits/stdc++.h>
using namespace std;
const int lim = 27;
vector<int> sz;
vector<vector<int>> go;
void add(int v, int x) {
  for (int pos = lim; pos >= 0; pos--) {
    if (go[v][(x >> pos) & 1] == -1) {
      int nw = (int)sz.size();
      sz.push_back(0);
      go.push_back({-1, -1});
      go[v][(x >> pos) & 1] = nw;
    }
    sz[v]++;
    v = go[v][(x >> pos) & 1];
  }
  sz[v]++;
}
void build(vector<int> to_add) {
  sz.push_back(0);
  go.push_back({-1, -1});
  sort(to_add.begin(), to_add.end());
  to_add.resize(unique(to_add.begin(), to_add.end()) - to_add.begin());
  for (auto x : to_add) {
    add(0, x);
  }
}
int solve(int v, int x) {
  int ans = 0;
  for (int pos = lim; pos >= 0; pos--) {
    if (go[v][(x >> pos) & 1] == -1) {
      break;
    }
    assert(sz[go[v][(x >> pos) & 1]] <= (1 << pos));
    if (sz[go[v][(x >> pos) & 1]] < (1 << (pos))) {
      v = go[v][(x >> pos) & 1];
      continue;
    }
    ans += (1 << pos);
    if (go[v][!((x >> pos) & 1)] == -1) {
      break;
    }
    v = go[v][!((x >> pos) & 1)];
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  const int maxn = 1e6;
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &t : a) {
    cin >> t;
  }
  vector<int> ans(q);
  vector<vector<int>> quer(maxn);
  int cur = 0;
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    cur ^= x;
    quer[cur].push_back(i);
  }
  build(a);
  for (int i = 0; i < maxn; i++) {
    if (!quer[i].empty()) {
      int res = solve(0, i);
      for (auto ind : quer[i]) {
        ans[ind] = res;
      }
    }
  }
  for (auto t : ans) {
    cout << t << ' ';
  }
}
