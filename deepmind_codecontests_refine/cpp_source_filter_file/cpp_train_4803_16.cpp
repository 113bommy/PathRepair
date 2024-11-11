#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, i, j, k, INF = 1E9, a, b, c, ans, w, id, ct, aa, bb, cc;
  cin >> n >> m;
  vector<tuple<int, int, int, int>> edge(m);
  for (i = 0; i < m; i++) {
    cin >> a >> b >> w;
    edge[i] = {w, a, b, i + 1};
  }
  sort(edge.rbegin(), edge.rend());
  aa = 1;
  bb = INF;
  while (aa < bb) {
    cc = (aa + bb) / 2;
    vector<vector<int>> adj(n + 1);
    vector<int> in(n + 1, 0);
    queue<int> q;
    for (auto p : edge) {
      tie(w, a, b, id) = p;
      if (w <= cc) break;
      in[b]++;
      adj[a].push_back(b);
    }
    for (i = 1; i <= n; i++) {
      if (in[i] == 0) q.push(i);
    }
    ct = 0;
    while (!q.empty()) {
      id = q.front();
      q.pop();
      ct++;
      for (auto p : adj[id]) {
        in[p]--;
        if (in[p] == 0) q.push(p);
      }
    }
    if (ct < n)
      aa = cc + 1;
    else
      bb = cc;
  }
  ans = aa;
  vector<vector<int>> adj(n + 1);
  vector<int> in(n + 1, 0), plist, pid(n + 1, -1), idlist;
  queue<int> q;
  for (auto p : edge) {
    tie(w, a, b, id) = p;
    if (w <= ans) break;
    in[b]++;
    adj[a].push_back(b);
  }
  for (i = 1; i <= n; i++) {
    if (in[i] == 0) q.push(i);
  }
  ct = 0;
  while (!q.empty()) {
    id = q.front();
    q.pop();
    ct++;
    plist.push_back(id);
    for (auto p : adj[id]) {
      in[p]--;
      if (in[p] == 0) q.push(p);
    }
  }
  for (i = 0; i < n; i++) pid[plist[i]] = i;
  for (auto p : edge) {
    tie(w, a, b, id) = p;
    if (w <= ans) {
      if (pid[a] > pid[b]) idlist.push_back(id);
    }
  }
  cout << ans << " " << idlist.size() << "\n";
  for (auto p : idlist) cout << p << " ";
  cout << "\n";
  return 0;
}
