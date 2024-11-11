#include <bits/stdc++.h>
using namespace std;
int n, m;
int vis[100006];
vector<int> graph[100004];
int cnt;
int a[100006];
void dfsvisit(int x) {
  vis[x] = 1;
  cnt = min(cnt, a[x]);
  for (int i = 0; i < graph[x].size(); i++) {
    int temp = graph[x][i];
    if (!vis[temp]) dfsvisit(temp);
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int p, q;
  for (int i = 0; i < m; i++) {
    cin >> p >> q;
    graph[p].push_back(q);
    graph[p].push_back(q);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      cnt = a[i];
      dfsvisit(i);
      ans += cnt;
    }
  }
  cout << ans << endl;
  return 0;
}
