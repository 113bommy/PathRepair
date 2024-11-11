#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 10, mod = 199999;
int n, p[M], de[M], fa[M];
vector<int> son[M], ans;
void dfs(int x) {
  cout << x << ' ';
  if (son[x].empty()) return;
  int mx = n - 1;
  for (auto v : son[x]) {
    if (de[v] >= de[mx]) mx = v;
  }
  int pre = 0;
  for (auto v : son[x]) {
    if (v == mx) continue;
    dfs(v);
    while (pre--) {
      ans.push_back(v);
    }
    pre = de[v];
  }
  while (pre--) {
    ans.push_back(mx);
  }
  dfs(mx);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int x;
    cin >> x;
    son[x].push_back(i);
    de[i] = 1;
    fa[x] = i;
  }
  for (int i = n - 1; ~i; --i) {
    de[fa[i]] = max(de[fa[i]], de[i] + 1);
  }
  dfs(0);
  cout << '\n';
  cout << ans.size() << '\n';
  for (auto x : ans) cout << x << " \n"[x == ans.back()];
}
