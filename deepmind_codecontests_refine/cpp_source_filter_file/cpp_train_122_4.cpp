#include <bits/stdc++.h>
using namespace std;
void find(vector<long long> graph[], long long vis[], long long start,
          long long val) {
  if (val == start) return;
  vis[start] = 1;
  long long i, size = graph[start].size(), x;
  for (i = 0; i < size; i++) {
    x = graph[start][i];
    if (!vis[x]) {
      vis[x] = 1;
      find(graph, vis, x, val);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n, m, a, b, i, x, y, val, cnt1 = 0, cnt2 = 0, ans = 1;
    cin >> n >> m >> a >> b;
    vector<long long> graph[n + 1];
    long long vis[n + 1];
    memset(vis, 0, sizeof(vis));
    for (i = 0; i < m; i++) {
      cin >> x >> y;
      graph[x].push_back(y);
      graph[y].push_back(x);
    }
    find(graph, vis, a, b);
    for (i = 1; i <= n; i++)
      if (!vis[i]) cnt2++;
    memset(vis, 0, sizeof(vis));
    find(graph, vis, a, b);
    for (i = 1; i <= n; i++)
      if (!vis[i]) cnt1++;
    cout << cnt1 * cnt2 << endl;
  }
  return 0;
}
