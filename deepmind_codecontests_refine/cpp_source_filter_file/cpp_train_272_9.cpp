#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > graph;
stack<int> dfs;
vector<int> visited[2];
vector<pair<int, int> > paths;
int recurr(int v, int l) {
  dfs.push(v);
  visited[l][v] = 1;
  int ret = -2, t;
  if (graph[v].size() == 0 && l == 1) {
    return 0;
  }
  for (int i = 0; i < graph[v].size(); i++) {
    if (visited[!l][graph[v][i]] == 0) {
      t = recurr(graph[v][i], !l);
      if (t == 0) {
        return 0;
      } else if (t == -1) {
        ret = -1;
      }
    }
    if (visited[0][graph[v][i]] == 1 || visited[1][graph[v][i]] == 1) {
      return -1;
    }
  }
  visited[l % 2][v] = 2;
  dfs.pop();
  return ret;
}
void printStack() {
  if (dfs.size() > 0) {
    int t = dfs.top() + 1;
    dfs.pop();
    printStack();
    cout << t << " ";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, c, s;
  cin >> n >> m;
  graph.resize(n);
  visited[0].resize(n, 0);
  visited[1].resize(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> c;
    graph[i].resize(c);
    for (int j = 0; j < c; j++) {
      cin >> graph[i][j];
      graph[i][j]--;
    }
  }
  cin >> s;
  s--;
  switch (recurr(s, 0)) {
    case 0:
      cout << "Win" << endl;
      printStack();
      cout << endl;
      break;
    case -1:
      cout << "Draw" << endl;
      break;
    case -2:
      cout << "Lose" << endl;
      break;
  }
  return 0;
}
