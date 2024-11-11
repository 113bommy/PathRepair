#include <bits/stdc++.h>
using namespace std;
const long long I1 = 1e9;
const long long I2 = 1e18;
const int32_t M1 = 1e9 + 7;
const int32_t M2 = 998244353;
template <typename T, typename T1>
T maxn(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T minn(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
map<int, set<int> > adj;
int mx = 0;
pair<int, int> ind = {-1, -1};
map<int, int> mp;
pair<int, int> dfs(int src, int p) {
  int mx1 = -1, mx2 = -1, ind1 = -1, ind2 = -1;
  for (auto u : adj[src]) {
    if (u != p) {
      pair<int, int> x = dfs(u, src);
      x.first++;
      if (x.first > mx1) {
        mx2 = mx1, ind2 = ind1;
        mx1 = x.first, ind1 = x.second;
      } else if (x.first > mx2) {
        mx2 = x.first, ind2 = x.second;
      }
    }
  }
  if (mx1 > -1 && mx2 > -1 && mx1 + mx2 > mx) {
    mx = mx1 + mx2;
    ind = {ind1, ind2};
  }
  if (mp.count(src)) {
    if (mx1 > mx) {
      mx = mx1;
      ind = {ind1, src};
    }
    if (mx1 = -1) {
      mx1 = 0, ind1 = src;
    }
  }
  return {mx1, ind1};
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]] = i + 1;
  }
  for (auto u : a) {
    for (int i = 30; i >= 0; i--) {
      if ((1 << i) < u) {
        adj[(1 << (i + 1)) - u].insert(u);
        adj[u].insert((1 << (i + 1)) - u);
        u = (1 << (i + 1)) - u;
      }
    }
    if (u == 1) {
      adj[0].insert(1);
      adj[1].insert(0);
    }
  }
  pair<int, int> cur = dfs(0, -1);
  cout << mp[ind.first] << " " << mp[ind.second] << " " << mx << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int testcase = 1;
  while (testcase--) solve();
  return 0;
}
