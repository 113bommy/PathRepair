#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct node {
  int x, id;
  node(int a, int b) {
    x = a;
    id = b;
  }
};
vector<node> g[2 * maxn];
vector<int> ans;
int num[maxn];
int need[maxn], vis[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(node(y, i));
    g[y].push_back(node(x, i));
    need[x]++, need[y]++;
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (need[i] <= num[i]) q.push(i);
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 0; i < g[x].size(); i++) {
      int t1 = g[x][i].x, t2 = g[x][i].id;
      if (vis[t2]) continue;
      vis[t2] = 1;
      need[t1]--;
      if (need[t1] == num[t1]) q.push(t1);
      ans.push_back(t2);
    }
  }
  if (ans.size() < m)
    cout << "DEAD" << '\n';
  else {
    cout << "ALIVE" << '\n';
    for (int i = ans.size() - 1; i >= 0; i--) {
      cout << ans[i];
      if (i == 0)
        cout << '\n';
      else
        cout << ' ';
    }
  }
  return 0;
}
