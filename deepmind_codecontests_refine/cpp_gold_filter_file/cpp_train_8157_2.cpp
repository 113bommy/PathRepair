#include <bits/stdc++.h>
using namespace std;
vector<int> graph[10][10];
int deg[10];
vector<pair<int, int> > edge;
vector<int> T, S;
void dfs(int node) {
  int i = 0;
  for (i = 0; i <= 6; i++)
    if (graph[node][i].size() > 0) {
      int e = graph[node][i].back();
      graph[node][i].pop_back();
      graph[i][node].erase(
          find(graph[i][node].begin(), graph[i][node].end(), -e));
      T.push_back(e);
      dfs(i);
      while (!T.empty()) {
        S.push_back(T.back());
        T.pop_back();
        if (S.back() == e) break;
      }
    }
}
int main() {
  int n, u, v;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> u >> v;
    graph[u][v].push_back(i);
    graph[v][u].push_back(-i);
    deg[u]++;
    deg[v]++;
    edge.push_back(make_pair(u, v));
  }
  int start = -1;
  int odd = 0;
  bool bad = false;
  for (int i = 0; i <= 6; i++) {
    if (deg[i] % 2 == 1) {
      start = i;
      odd++;
    } else if (start == -1 and deg[i] > 0) {
      start = i;
    }
  }
  if (odd > 2) bad = true;
  dfs(start);
  if (S.size() != n) bad = true;
  if (bad) {
    cout << "No solution\n";
  } else {
    while (!S.empty()) {
      int cur = S.back();
      S.pop_back();
      cout << abs(cur) << " " << ((cur < 0) ? '-' : '+') << "\n";
    }
  }
  return 0;
}
