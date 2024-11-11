#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
vector<vector<int>> edges;
vector<ll> A;
array<ll, 3> dfs(int cur) {
  if (edges[cur].empty()) return {A[cur], 0, 1};
  vector<array<ll, 3>> rets;
  ll max_v = 0, remain = 0, leaf = 0;
  for (auto nxt : edges[cur]) {
    auto sub_ret = dfs(nxt);
    rets.push_back(sub_ret);
    max_v = max(max_v, sub_ret[0]);
    remain += sub_ret[1];
    leaf += sub_ret[2];
  }
  for (auto& sub_ret : rets) remain += sub_ret[2] * (max_v - sub_ret[0]);
  if (remain < A[cur]) {
    ll a = A[cur] - remain;
    ll ret0 = (a + leaf - 1) / leaf + max_v;
    return {ret0, leaf - a % leaf, leaf};
  }
  return {max_v, remain - A[cur], leaf};
}
void solve(int TestCase) {
  cin >> n;
  edges.resize(n);
  A.resize(n);
  for (auto i = 1; i < n; ++i) {
    int p;
    cin >> p;
    p--;
    edges[p].push_back(i);
  }
  for (auto& x : A) cin >> x;
  ll ret = dfs(0)[0];
  cout << ret << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  for (auto i = 1; i <= t; ++i) {
    solve(i);
  }
}
