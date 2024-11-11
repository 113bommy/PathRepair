#include <bits/stdc++.h>
using namespace std;
int visit[200005], value[200005];
vector<int> edge[200005];
pair<int, int> arr[200005];
void dfs(int node, int c) {
  value[node] = c;
  visit[node] = 1;
  for (size_t i = 0; i < edge[node].size(); i++) {
    if (visit[edge[node][i]] == 0) {
      dfs(edge[node][i], 3 - c);
    }
  }
}
int main() {
  int n, u, v;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> u >> v;
    arr[i].first = u;
    arr[i].second = v;
    edge[u].push_back(v);
    edge[v].push_back(u);
    edge[2 * i].push_back(2 * i - 1);
    edge[2 * i - 1].push_back(2 * i);
  }
  memset(visit, 0, sizeof(visit));
  for (int i = 1; i <= 2 * n; i++) {
    if (visit[i] == 1) continue;
    dfs(i, 1);
  }
  for (int i = 1; i <= n; i++) {
    cout << value[arr[i].first] << " " << value[arr[i].second] << endl;
  }
}
