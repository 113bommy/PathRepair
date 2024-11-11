#include <bits/stdc++.h>
using namespace std;
int used[111111];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  vector<int> sp(k);
  for (int i = (0); i <= ((k)-1); i++) scanf("%d", &sp[i]), sp[i]--;
  vector<vector<int> > G(n);
  for (int i = (0); i <= ((m)-1); i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int s, t;
  scanf("%d%d", &s, &t);
  s--;
  t--;
  queue<int> Q;
  vector<int> d(n, 1000000000), sw(n);
  sp.push_back(s);
  sp.push_back(t);
  sort((sp).begin(), (sp).end()),
      sp.erase(unique(sp.begin(), sp.end()), sp.end());
  memset((used), 0, sizeof(used));
  for (int i = (0); i <= (((int)((sp).size())) - 1); i++)
    Q.push(sp[i]), d[sp[i]] = 0, sw[sp[i]] = sp[i], used[sp[i]] = true;
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    for (int i = (0); i <= (((int)((G[cur]).size())) - 1); i++)
      if (!used[G[cur][i]]) {
        d[G[cur][i]] = d[cur] + 1;
        used[G[cur][i]] = true;
        sw[G[cur][i]] = sw[cur];
        Q.push(G[cur][i]);
      }
  }
  vector<vector<int> > p(n), w(n);
  for (int i = (0); i <= ((n)-1); i++)
    for (int j = (0); j <= (((int)((G[i]).size())) - 1); j++)
      if (sw[i] != sw[G[i][j]]) {
        p[sw[i]].push_back(sw[G[i][j]]);
        w[sw[i]].push_back(d[i] + d[G[i][j]] + 1);
      }
  int l = 0, r = 2 * m;
  while (r - l > 1) {
    int cur = (l + r) / 2;
    vector<vector<int> > g(n);
    for (int i = (0); i <= (((int)((p).size())) - 1); i++)
      for (int j = (0); j <= (((int)((p[i]).size())) - 1); j++)
        if (w[i][j] <= cur) g[i].push_back(p[i][j]);
    queue<int> q;
    q.push(s);
    memset((used), 0, sizeof(used));
    used[s] = true;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      if (cur == t) break;
      for (int i = (0); i <= (((int)((g[cur]).size())) - 1); i++)
        if (!used[g[cur][i]]) {
          used[g[cur][i]] = true;
          q.push(g[cur][i]);
        }
    }
    if (used[t])
      r = cur;
    else
      l = cur;
  }
  if (r > m)
    cout << -1 << endl;
  else
    cout << r << endl;
  return 0;
}
