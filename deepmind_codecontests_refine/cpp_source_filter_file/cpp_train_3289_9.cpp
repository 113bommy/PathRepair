#include <bits/stdc++.h>
using namespace std;
int n, m, cc = 1;
vector<int> c, cur, z;
vector<vector<int>> adj1, adj2;
void dfs(int s, int p) {
  for (auto i : adj1[s]) {
    if (c[i] != -1)
      cur.push_back(c[i]);
    else
      z.push_back(i);
  }
  sort(cur.begin(), cur.end());
  int x = 0, pos = 0;
  while (z.size() > 0) {
    if (pos < cur.size() && cur[pos] == x) {
      pos++;
    } else {
      c[z.back()] = x;
      z.pop_back();
    }
    x++;
  }
  cur.clear();
  for (auto i : adj2[s]) {
    if (i != p) dfs(i, s);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  adj1.assign(n, vector<int>());
  adj2.assign(n, vector<int>());
  c.assign(m, -1);
  for (int i = 0; i < n; ++i) {
    int r, x;
    cin >> r;
    cc = max(cc, r);
    for (int j = 0; j < r; ++j) {
      cin >> x;
      x--;
      adj1[i].push_back(x);
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj2[u].push_back(v);
    adj2[v].push_back(u);
  }
  dfs(0, 0);
  cout << cc << "\n";
  for (auto i : c) {
    cout << i + 1 << " ";
  }
  return 0;
}
