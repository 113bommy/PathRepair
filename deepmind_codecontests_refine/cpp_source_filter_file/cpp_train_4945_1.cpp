#include <bits/stdc++.h>
using namespace std;
const int Maxn = 200 * 1000 + 10;
int n, m, par[Maxn], deg[Maxn], cnt, st[Maxn], stt;
vector<int> edge[Maxn], ind[Maxn], leaf, sar[Maxn], lmt[Maxn];
bool ans[Maxn], markt[Maxn], ers[Maxn];
void dfs(int v) {
  stt++;
  st[v] = stt;
  int e, u;
  for (int i = 0; i < (int)edge[v].size(); i++) {
    e = abs(edge[v][i]);
    u = sar[e][0];
    if (u == v) u = sar[e][1];
    if (!ers[abs(edge[v][i])] && par[v] != abs(edge[v][i]) && st[u] < st[v]) {
      if (!markt[v]) cnt++;
      markt[v] = true;
      if (edge[v][i] > 0) ans[e] = true;
      if (st[u] == 0) {
        if (lmt[e][0] * lmt[e][1] == 1) {
          if (!markt[u]) cnt++;
          markt[u] = true;
        }
        par[u] = e;
        dfs(u);
      }
    }
  }
  return;
}
void dfsAll() {
  for (int i = 0; i < n; i++)
    if (st[i] == 0 && !markt[i]) dfs(i);
  return;
}
int main() {
  cin >> n >> m;
  int k, a;
  for (int i = 0; i < n; i++) {
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &a);
      if (sar[abs(a)].size() == 0) {
        sar[abs(a)].push_back(i);
        sar[abs(a)].push_back(i);
        lmt[abs(a)].push_back(a / abs(a));
        lmt[abs(a)].push_back(a / abs(a));
        ind[i].push_back(0);
      } else {
        sar[abs(a)][1] = i;
        lmt[abs(a)][1] = a / abs(a);
        ind[i].push_back(1);
      }
      edge[i].push_back(a);
      deg[i]++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (deg[i] == 1 &&
        (lmt[abs(edge[i][0])][0] * lmt[abs(edge[i][0])][1] == -1) &&
        !ers[abs(edge[i][0])]) {
      leaf.push_back(abs(edge[i][0]));
      markt[i] = true;
      cnt++;
      if (edge[i][0] > 0) ans[abs(edge[i][0])] = true;
      ers[abs(edge[i][0])] = true;
    }
  }
  while (!leaf.empty()) {
    int e = leaf.back();
    leaf.pop_back();
    int u = sar[e][0];
    if (markt[u]) u = sar[e][1];
    deg[u]--;
    if (deg[u] == 1) {
      for (int i = 0; i < (int)edge[u].size(); i++) {
        if (!ers[abs(edge[u][i])]) {
          if (lmt[abs(edge[u][i])][0] * lmt[abs(edge[u][i])][1] == -1) {
            leaf.push_back(abs(edge[u][i]));
            markt[u] = true;
            cnt++;
            if (edge[u][i] > 0) ans[abs(edge[u][i])] = true;
            ers[abs(edge[u][i])] = true;
          }
        }
      }
    }
  }
  dfsAll();
  if (cnt != n) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  for (int i = 1; i <= m; i++) {
    if (ans[i])
      printf("1");
    else
      printf("0");
  }
  cout << endl;
  return 0;
}
