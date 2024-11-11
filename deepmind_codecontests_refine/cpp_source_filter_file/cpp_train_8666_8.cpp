#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
vector<int> edge[maxn], dep[maxn];
pair<int, int> query(vector<int> node) {
  if (node.size() == 0) return {-1, -1};
  cout << "? " << node.size();
  for (auto x : node) cout << ' ' << x;
  cout << endl;
  int pt, dis;
  cin >> pt >> dis;
  return {pt, dis};
}
void dfs(int u, int pre, int d) {
  dep[d].push_back(u);
  for (auto v : edge[u])
    if (v != pre) dfs(v, u, d + 1);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) edge[i].clear();
    for (int i = 0; i <= n; i++) dep[i].clear();
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      edge[u].push_back(v);
      edge[v].push_back(u);
    }
    vector<int> node;
    for (int i = 1; i <= n; i++) node.push_back(i);
    auto tmp = query(node);
    int rt = tmp.first, len = tmp.second;
    dfs(rt, 0, 0);
    int l = 0, r = n, x, y;
    while (l <= r) {
      int mid = l + r >> 1;
      auto tmp = query(dep[mid]);
      if (tmp.second == len) {
        l = mid + 1;
        x = tmp.first;
      } else
        r = mid - 1;
    }
    for (int i = 0; i <= n; i++) dep[i].clear();
    dfs(x, 0, 0);
    tmp = query(dep[len]);
    y = tmp.second;
    cout << "! " << x << ' ' << y << endl;
    string s;
    cin >> s;
  }
  return 0;
}
