#include <bits/stdc++.h>
using namespace std;
int n, m, h;
int values[100005];
vector<int> adjList[100005];
vector<int> adjListRev[100005];
bool seen[100005];
stack<int> order;
vector<int> SCC[100005];
int whichSCC[100005];
void dfs(int x) {
  seen[x] = true;
  for (int i = 0; i < adjList[x].size(); i++) {
    int next = adjList[x][i];
    if (!seen[next]) dfs(next);
  }
  order.push(x);
}
void dfsRev(int x, int scc) {
  seen[x] = true;
  SCC[scc].push_back(x);
  whichSCC[x] = scc;
  for (int i = 0; i < adjListRev[x].size(); i++) {
    int next = adjListRev[x][i];
    if (!seen[next]) dfsRev(next, scc);
  }
}
int sccSize(int scc) {
  int size = 0;
  for (int i = 0; i < SCC[scc].size(); i++) {
    int node = SCC[scc][i];
    size++;
    for (int j = 0; j < adjList[node].size(); j++) {
      int next = adjList[node][j];
      if (whichSCC[next] != scc) {
        return 2e9;
      }
    }
  }
  return size;
}
int main() {
  scanf("%d%d%d", &n, &m, &h);
  for (int i = 0; i < n; i++) {
    scanf("%d", &values[i]);
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    if ((values[a] + 1) % h == values[b]) {
      adjList[a].push_back(b);
      adjListRev[b].push_back(a);
    }
    if ((values[b] + 1) % h == values[a]) {
      adjList[b].push_back(a);
      adjListRev[a].push_back(b);
    }
  }
  for (int i = 0; i < n; i++) {
    if (!seen[i]) {
      dfs(i);
    }
  }
  for (int i = 0; i < n; i++) {
    seen[i] = false;
  }
  int scc = 0;
  while (!order.empty()) {
    int top = order.top();
    order.pop();
    if (seen[top]) continue;
    dfsRev(top, scc++);
  }
  int best = 1e9;
  int bestScc = -1;
  for (int i = 0; i < scc; i++) {
    int size = sccSize(i);
    if (size < best) {
      best = size;
      bestScc = i;
    }
  }
  printf("%d\n", SCC[bestScc].size());
  for (int i = 0; i < SCC[bestScc].size(); i++) {
    printf("%d ", SCC[bestScc][i] + 1);
  }
  printf("\n");
}
