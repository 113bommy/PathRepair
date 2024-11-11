#include <bits/stdc++.h>
using namespace std;
int V;
vector<vector<int> > adjList;
const int MAX = 100001;
int a[MAX], b[MAX];
int col[MAX << 1];
bool isB(int s) {
  queue<int> q;
  q.push(s);
  col[s] = 0;
  while (!q.empty()) {
    int cur = q.back();
    q.pop();
    for (auto &v : adjList[cur]) {
      if (col[v] == -1) {
        col[v] = 1 - col[cur];
        q.push(v);
      } else if (col[v] == col[cur])
        return false;
    }
  }
  return true;
}
int main() {
  scanf("%d", &V);
  adjList.assign(V << 1, vector<int>());
  memset(col, -1, sizeof(col));
  for (int i = 0; i < V; ++i) {
    scanf("%d %d", &a[i], &b[i]), a[i]--, b[i]--;
    adjList[a[i]].push_back(b[i]);
    adjList[b[i]].push_back(a[i]);
  }
  for (int i = 0; i < 2 * V; i += 2) {
    adjList[i].push_back(i + 1);
    adjList[i + 1].push_back(i);
  }
  bool allOk = 1;
  for (int i = 0; i < 2 * V; ++i) {
    if (col[i] == -1) {
      allOk &= isB(i);
    }
    if (!allOk) break;
  }
  if (allOk) {
    for (int i = 0; i < V; ++i) {
      printf("%d %d\n", col[a[i]] + 1, col[b[i]] + 1);
    }
  } else {
    printf("%d\n", -1);
  }
  return 0;
}
