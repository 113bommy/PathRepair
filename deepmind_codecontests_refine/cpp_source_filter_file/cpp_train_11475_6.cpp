#include <bits/stdc++.h>
using namespace std;
int n, c[2003], f[2003];
vector<int> graph[2003];
vector<int> dfs(int node) {
  vector<int> res;
  for (auto &nxt : graph[node]) {
    vector<int> sv = dfs(nxt);
    for (auto &c : sv) {
      res.push_back(c);
    }
  }
  res.push_back(node);
  int idx = (int)res.size() - 1;
  if (c[node] >= idx) {
    cout << "NO\n";
    exit(0);
  }
  while (idx > c[node]) {
    swap(res[idx - 1], res[idx]);
    idx--;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  int root = -1;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p >> c[i + 1];
    graph[p].push_back(i + 1);
    if (p == 0) root = i + 1;
  }
  vector<int> ans = dfs(root);
  for (int i = 0; i < n; i++) {
    f[ans[i]] = i + 1;
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    if (i > 1) cout << ' ';
    cout << f[i];
  }
  cout << '\n';
  return 0;
}
