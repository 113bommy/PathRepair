#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10, inf = 0x3f3f3f3f;
int m, n, t;
pair<int, int> cost[maxn], dp[maxn], ans;
map<string, int> comp;
vector<int> words, grafo[maxn], metagrafo[maxn];
int low[maxn], scc[maxn], pre[maxn], tt, sccid;
stack<int> second;
void compress(string &second) {
  int qtdr = 0;
  for (int j = 0; j < second.size(); j++) {
    if (second[j] >= 'A' and second[j] <= 'Z') {
      second[j] += 32;
    }
    if (second[j] == 'r') qtdr++;
  }
  if (!comp[second]) {
    comp[second] = ++t;
    cost[t] = {qtdr, (int)second.size()};
  }
}
void tarjan(int u) {
  pre[u] = low[u] = ++tt;
  second.push(u);
  for (int i = 0; i < grafo[u].size(); i++) {
    int v = grafo[u][i];
    if (!pre[v]) tarjan(v);
    low[u] = min(low[u], low[v]);
  }
  if (low[u] == pre[u]) {
    int v = -1;
    sccid++;
    do {
      v = second.top(), second.pop();
      low[v] = inf;
      scc[v] = sccid;
    } while (u != v);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> m;
  for (int i = 1; i <= m; i++) {
    string second;
    cin >> second;
    compress(second);
    words.push_back(comp[second]);
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string u, v;
    cin >> u >> v;
    compress(u), compress(v);
    grafo[comp[u]].push_back(comp[v]);
  }
  for (int i = 1; i <= t; i++) {
    if (!pre[i]) tarjan(i);
  }
  memset(dp, inf, sizeof dp);
  for (int u = 1; u <= t; u++) {
    dp[scc[u]] = min(dp[scc[u]], cost[u]);
    for (int i = 0; i < grafo[u].size(); i++) {
      int v = grafo[u][i];
      if (scc[u] != scc[v]) {
        metagrafo[scc[u]].push_back(scc[v]);
      }
    }
  }
  for (int u = 1; u <= sccid; u++) {
    for (int i = 0; i < metagrafo[u].size(); i++) {
      int v = metagrafo[u][i];
      dp[u] = min(dp[u], dp[v]);
    }
  }
  for (int i = 0; i < words.size(); i++) {
    ans.first += dp[scc[words[i]]].first;
    ans.second += dp[scc[words[i]]].second;
  }
  cout << ans.first << " " << ans.second << "\n";
  return 0;
}
