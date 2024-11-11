#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
int n, m, u, v, next[N], p, cmp;
vector<int> node[N], ve, vec;
map<int, bool> mp[N];
queue<int> q[N];
bool mark[N];
set<int> st;
void dfs(int v) {
  vec.push_back(v);
  mark[v] = true;
  for (auto i : node[v])
    if (!mark[i]) dfs(i);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    node[u].push_back(v);
    node[v].push_back(u);
    mp[u][v] = true;
    mp[v][u] = true;
  }
  if (n <= 7) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    do {
      int z = m;
      bool cant = false;
      for (int i = 0; i < n - 1; i++) {
        if (z && mp[arr[i]][arr[i + 1]]) {
          cant = true;
          break;
        }
        z--;
      }
      if (z && mp[arr[0]][arr[n - 1]]) cant = true;
      if (!cant) {
        z = m;
        for (int i = 0; z && i < n - 1; i++) {
          cout << arr[i] << ' ' << arr[i + 1] << '\n';
          z--;
        }
        if (z) cout << arr[0] << ' ' << arr[n - 1] << '\n';
        return 0;
      }
    } while (next_permutation(arr, arr + n));
    cout << -1 << '\n';
  } else {
    for (int i = 1; i <= n; i++) {
      if (!mark[i]) {
        ve.clear();
        vec.clear();
        dfs(i);
        for (int j = 0; j < (int)vec.size(); j += 2) ve.push_back(vec[j]);
        for (int j = 1; j < (int)vec.size(); j += 2) ve.push_back(vec[j]);
        if (ve.size() & 1) swap(ve[0], ve[1]);
        for (auto j : ve) q[cmp].push(j);
        st.insert(cmp);
        cmp++;
      }
    }
    vector<int> ans;
    while (st.size()) {
      vector<int> deleted;
      for (auto i : st) {
        ans.push_back(q[i].front());
        q[i].pop();
        if (q[i].empty()) deleted.push_back(i);
      }
      for (auto i : deleted) st.erase(i);
    }
    ans.push_back(ans[0]);
    for (int i = 0; m && i < (int)ans.size(); i++) {
      cout << ans[i] << ' ' << ans[i + 1] << '\n';
      m--;
    }
  }
  return 0;
}
