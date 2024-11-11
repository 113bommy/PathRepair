#include <bits/stdc++.h>
using namespace std;
int nodes, dad[100500], sz[100500], deg[100500], big[100500], ans[100500];
map<int, int> simpler;
vector<int> adj[100500];
map<int, int> outer, daddy;
void bs(map<int, int>& fuck, int n, int l, int mn, int mx, int fck2 = 0) {
  int smx = l, r = mx;
  if (mn == nodes - 1) return;
  while (l < r - 1) {
    int mid = (l + r) / 2;
    auto it = fuck.lower_bound(mx - mid + fck2);
    if (it == fuck.end())
      l = mid;
    else if (mn + it->first <= mid + fck2)
      r = mid;
    else
      l = mid;
  }
  ans[n] = min(ans[n], r);
}
void add(int v) {
  simpler[sz[v]]++;
  outer[sz[v]]--;
  if (outer[sz[v]] == 0) outer.erase(sz[v]);
  for (auto u : adj[v])
    if (!big[u]) add(u);
}
void rem(int v) {
  outer[sz[v]]++;
  simpler[sz[v]]--;
  if (simpler[sz[v]] == 0) simpler.erase(sz[v]);
  for (auto u : adj[v])
    if (!big[u]) rem(u);
}
void dfs(int v, int biggie = 1) {
  outer[sz[v]]--;
  if (outer[sz[v]] == 0) outer.erase(sz[v]);
  daddy[sz[v]]++;
  int mx = -1, smx = -1, bigChild = -1, mn = nodes - 1;
  for (auto u : adj[v]) {
    if (sz[u] > mx) {
      smx = mx;
      mx = sz[u], bigChild = u;
    } else
      smx = max(smx, sz[u]);
    mn = min(mn, sz[u]);
  }
  if (dad[v]) mn = min(mn, nodes - sz[v]);
  for (auto u : adj[v]) {
    if (u != bigChild) {
      dfs(u, 0);
    }
  }
  if (~bigChild) {
    big[bigChild] = 1;
    dfs(bigChild, 1);
  }
  if (mx >= nodes - sz[v])
    bs(simpler, v, max(smx - 1, nodes - sz[v] - 1), mn, max(mx, nodes - sz[v]));
  daddy[sz[v]]--;
  if (daddy[sz[v]] == 0) daddy.erase(sz[v]);
  outer[sz[v]]++;
  add(v);
  if (mx < nodes - sz[v]) {
    bs(outer, v, mx - 1, mn, nodes - sz[v]);
    bs(daddy, v, mx - 1, mn, nodes - sz[v], sz[v]);
  }
  big[max(bigChild, 0)] = 0;
  if (biggie) rem(v);
}
int main() {
  cin >> nodes;
  int root;
  for (int i = 1; i < nodes + 1; i++) {
    int a, b;
    cin >> a >> b;
    dad[b] = a;
    sz[i] = 1;
    deg[a]++;
    if (a)
      adj[a].push_back(b);
    else
      root = b;
  }
  queue<int> q;
  for (int i = 1; i < nodes + 1; i++) {
    if (!deg[i]) q.push(i);
    ans[i] = nodes - 1;
  }
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    if (!t) break;
    outer[sz[t]]++;
    sz[dad[t]] += sz[t];
    deg[dad[t]]--;
    if (!deg[dad[t]]) q.push(dad[t]);
  }
  dfs(root);
  for (int i = 1; i < nodes + 1; i++) cout << ans[i] << endl;
}
