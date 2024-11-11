#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans, ki, vi, ui, country[1005], countrySize[1005],
    countryEdges[1005], biggestCountry, countryCnt;
vector<int> graph[1005];
bool isGover[1005], hasGover[1005], visited[1005], edge[1005][1005];
void connect(int v, int u) {
  graph[v].push_back(u);
  graph[u].push_back(v);
}
void dfs(int node, int c) {
  visited[node] = 1;
  countrySize[c]++;
  country[node] = c;
  if (isGover[node]) {
    hasGover[c] = 1;
  }
  for (int i = 0; i < graph[node].size(); i++) {
    int child = graph[node][i];
    if (!edge[node][child]) {
      countryEdges[c]++;
    }
    edge[node][child] = edge[child][node] = 1;
    if (!visited[child]) {
      dfs(child, c);
    }
  }
}
int sumat(int x) { return x * (x + 1) / 2; }
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    cin >> ki;
    isGover[ki] = 1;
  }
  for (int i = 0; i < m; i++) {
    cin >> vi >> ui;
    connect(vi, ui);
  }
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      dfs(i, ++countryCnt);
    }
  }
  int noGovers = 0;
  for (int i = 1; i <= countryCnt; i++) {
    ans += sumat(countrySize[i] - 1) - countryEdges[i];
    if (!hasGover[i]) {
      if (noGovers) {
        ans += noGovers * countrySize[i];
      }
      noGovers += countrySize[i];
    } else {
      biggestCountry = max(biggestCountry, countrySize[i]);
    }
  }
  ans += biggestCountry * noGovers;
  cout << ans << endl;
  return 0;
}
