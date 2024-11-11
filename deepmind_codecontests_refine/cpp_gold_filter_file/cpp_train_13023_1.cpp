#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> edge[5][5];
int tempLen[5][5];
int sum[5][5];
int tempSub[5][5];
int tempDeg[5];
int deg[5];
pair<int, int> lst[6] = {pair<int, int>(1, 2), pair<int, int>(1, 3),
                         pair<int, int>(1, 4), pair<int, int>(2, 3),
                         pair<int, int>(2, 4), pair<int, int>(3, 4)};
void reset() {
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      tempSub[i][j] = 0;
      tempLen[i][j] = edge[i][j].size();
    }
    tempDeg[i] = deg[i];
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int u, val, v;
    cin >> u >> val >> v;
    edge[u][v].push_back(val);
    if (u != v) edge[v][u].push_back(val);
    sum[u][v] += val;
    if (u != v) sum[v][u] += val;
    deg[u]++;
    deg[v]++;
  }
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      sort(edge[i][j].begin(), edge[i][j].end());
      tempLen[i][j] = edge[i][j].size();
    }
  }
  int ans = 0;
  for (int i = 0; i < (1 << 6); i++) {
    reset();
    for (int j = 0; j < 6; j++) {
      if ((i & (1 << j)) == 0) continue;
      int u = lst[j].first;
      int v = lst[j].second;
      if (tempLen[u][v] == 0) continue;
      tempLen[u][v]--, tempLen[v][u]--;
      tempSub[u][v] = tempSub[v][u] = edge[u][v][0];
      tempDeg[u]--, tempDeg[v]--;
    }
    int c[5] = {0, 0, 0, 0, 0};
    for (int j = 1; j <= 4; j++) {
      if (c[j] == 1) continue;
      int curans = 0;
      queue<int> q;
      vector<int> nodes;
      q.push(j);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (c[u] == 1) continue;
        nodes.push_back(u);
        c[u] = 1;
        for (int v = 1; v <= 4; v++) {
          if (v == u) curans += sum[u][v] - tempSub[u][v];
          if (tempLen[u][v] > 0 && c[v] == 0) {
            curans += sum[u][v] - tempSub[u][v];
            q.push(v);
          }
        }
      }
      int numOdd = 0;
      for (int i = 0; i < nodes.size(); i++) {
        if ((tempDeg[nodes[i]] % 2) != 0) numOdd++;
      }
      if (numOdd == 0 || numOdd == 2) ans = max(ans, curans);
    }
  }
  cout << ans << "\n";
}
