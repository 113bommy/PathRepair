#include <bits/stdc++.h>
using namespace std;
int cnt[300010], a[300010], n, m;
vector<int> near[300010];
queue<int> q;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    near[--u].push_back(--v);
    near[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    if ((cnt[i] = near[i].size()) >= 2) q.push(i);
  }
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    if (cnt[now] < 2) continue;
    cnt[now] = near[now].size() - cnt[now];
    a[now] = !a[now];
    for (int x : near[now]) {
      if ((cnt[x] += (a[now] == x ? 1 : -1)) >= 2) q.push(x);
    }
  }
  for (int i = 0; i < n; i++) cout << a[i];
  cout << endl;
  return 0;
}
