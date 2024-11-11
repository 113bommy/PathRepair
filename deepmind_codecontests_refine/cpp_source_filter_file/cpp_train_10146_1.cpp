#include <bits/stdc++.h>
using namespace std;
int vis[100005], p[100005];
long long d[100005];
vector<pair<int, int> > edge[100005];
int main() {
  int n, m, k;
  int u, v, x, s, y;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &u, &v, &x);
    edge[u].push_back(make_pair(v, x));
    edge[v].push_back(make_pair(u, x));
  }
  for (int i = 0; i <= n; i++) {
    d[i] = 0x3f3f3f3f3f3f3f3f;
  }
  d[1] = 0;
  memset(p, 0, sizeof(p));
  memset(vis, 0, sizeof(vis));
  queue<int> q;
  q.push(1);
  vis[1] = 1;
  for (int i = 0; i < k; i++) {
    scanf("%d %d", &s, &y);
    if (y < d[s]) {
      d[s] = y;
      p[s] = 1;
    }
    if (d[s] == 0) {
      vis[s] = 1;
      q.push(s);
    }
  }
  while (!q.empty()) {
    int w = q.front();
    q.pop();
    vis[w] = 0;
    for (int i = 0; i < edge[w].size(); i++) {
      int next = edge[w][i].first;
      int len = edge[w][i].second;
      if (d[next] >= d[w] + len) {
        p[next] = 0;
      }
      if (d[next] > d[w] + len) {
        p[next] = 0;
        d[next] = d[w] + len;
        if (vis[next] == 0) {
          vis[next] = 1;
          q.push(next);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += p[i];
  }
  cout << k - ans << endl;
  return 0;
}
