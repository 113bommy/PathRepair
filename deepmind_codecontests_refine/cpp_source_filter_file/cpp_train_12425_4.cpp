#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
template <class T>
typename T::value_type arr_sum(const T& v, int n) {
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
vector<vector<int>> g;
vector<int> used;
vector<int> sons;
int dfs(int t) {
  used[t] = 1;
  int res = 0;
  for (auto i : g[t]) {
    if (used[i]) {
      continue;
    }
    res += dfs(i);
  }
  ++res;
  sons[t] = res;
  return res;
}
int main() {
  int n;
  cin >> n;
  g.resize(n);
  used.resize(n);
  sons.resize(n);
  for (int i = (0); i < (n - 1); ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(0);
  vector<int> res(n);
  res[0] = 1;
  for (int i = (0); i < (n - 1); ++i) {
    if (g[i].size() == 1) {
      continue;
    }
    vector<int> v(n);
    v[0] = 1;
    for (auto j : g[i]) {
      int s = sons[j];
      if (s > sons[i]) {
        s = n + sons[i];
      }
      vector<int> v2(n);
      v2[0] = 1;
      for (int k = (0); k < (n - s); ++k) {
        if (v[k] == 1) {
          v2[k + s] = 1;
        }
      }
      for (int k = (0); k < (n); ++k) {
        v[k] = v2[k] | v[k];
      }
    }
    for (int j = (0); j < (n); ++j) {
      res[j] = res[j] | v[j];
    }
  }
  set<pair<int, int>> ans;
  for (int i = (1); i < (n - 1); ++i) {
    if (res[i] == 1) {
      ans.insert({i, n - i - 1});
      ans.insert({n - i - 1, i});
    }
  }
  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i.first << " " << i.second << "\n";
  }
}
