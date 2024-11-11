#include <bits/stdc++.h>
using namespace std;
int nfre[100000], deg[100000], n, m, res = -1;
pair<int, int> canh[100000];
vector<int> c[100000];
bool bfs(int s) {
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    nfre[u] = 1;
    for (int i = 0; i <= (int)c[u].size() - 1; ++i) {
      int v = c[u][i];
      --deg[v];
      if (deg[v] == 0) q.push(v);
    }
    if (q.size() > 1) return 0;
  }
  for (int i = 1; i <= n; ++i)
    if (!nfre[i]) return 0;
  return 1;
}
bool check(int mid) {
  for (int i = 1; i <= n; ++i) {
    c[i].clear();
    deg[i] = 0;
    nfre[i] = 0;
  }
  for (int i = 1; i <= mid; ++i) {
    int u = canh[i].first, v = canh[i].second;
    c[u].push_back(v);
    ++deg[v];
  }
  int root = -1;
  for (int i = 1; i <= n; ++i)
    if (!deg[i]) root = i;
  if (root == -1) return 0;
  return bfs(root);
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d", &canh[i].first, &canh[i].second);
  }
  int l = 1, r = m;
  while (l <= r) {
    int mid = (l + r) / 2;
    bool ceck = check(mid);
    if (ceck && (!check(mid - 1) || mid == 1)) {
      res = mid;
      break;
    }
    if (!ceck) l = mid + 1;
    if (ceck) r = mid - 1;
  }
  cout << res << endl;
  return 0;
}
