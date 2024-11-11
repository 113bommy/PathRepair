#include <bits/stdc++.h>
using namespace std;
std::vector<int> adj[2051];
queue<int> que;
int visited[2051], done[1051];
int main() {
  int i, j, k, l, m;
  cin >> i >> j;
  char str[i + 1][j + 1];
  for (k = 0; k < i; k++) {
    for (l = 0; l < j; l++) cin >> str[k][l];
  }
  for (k = 0; k < i; k++) {
    for (l = 0; l < j; l++) {
      if (str[k][l] == '#') {
        adj[k].push_back(l + 1025);
        adj[l + 1025].push_back(k);
      }
    }
  }
  que.push(0);
  visited[0] = 0;
  while (!que.empty()) {
    k = que.front();
    que.pop();
    for (l = 0; l < adj[k].size(); l++) {
      if (adj[k][l] > 0 && visited[adj[k][l]] == 0) {
        que.push(adj[k][l]);
        visited[adj[k][l]] = visited[k] + 1;
      }
    }
  }
  if (visited[i - 1] > 0)
    cout << (visited[i - 1]) << endl;
  else
    cout << "-1\n";
  return 0;
}
