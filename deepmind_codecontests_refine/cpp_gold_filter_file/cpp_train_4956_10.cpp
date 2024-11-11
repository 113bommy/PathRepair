#include <bits/stdc++.h>
using namespace std;
const int Max = 10000;
int n, m, k;
int x[Max + 10];
int y[Max + 10];
int s;
vector<int> E[Max * 5 + 10];
vector<int> C[Max * 5 + 10];
void addEdge(int u, int v, int c) {
  E[u].push_back(v);
  C[u].push_back(c);
}
bool isadj(int a, int b) {
  if (x[a] == x[b]) {
    return abs(y[a] - y[b]) == 1;
  }
  if (y[a] == y[b]) {
    return abs(x[a] - x[b]) == 1;
  }
  return 0;
}
int dis[Max * 5 + 10];
const int INF = 1e9;
int ans = INF;
void spfa() {
  for (int i = 0; i < Max * 5 + 10; i++) {
    dis[i] = INF;
  }
  dis[s] = 0;
  queue<int> que;
  que.push(s);
  while (que.size()) {
    int u = que.front();
    que.pop();
    if (u < Max) {
      if (x[u] == n && y[u] == m) {
        ans = min(ans, dis[u]);
      }
    }
    int sz = E[u].size();
    for (int i = 0; i < sz; i++) {
      int v = E[u][i];
      if (dis[u] + C[u][i] < dis[v]) {
        dis[v] = dis[u] + C[u][i];
        que.push(v);
      }
    }
  }
}
int main() {
  cin >> n >> m >> k;
  x[0] = n;
  y[0] = m;
  bool hasT = 0;
  for (int i = 1; i <= k; i++) {
    scanf("%d %d", &x[i], &y[i]);
    if (x[i] == 1 && y[i] == 1) {
      s = i;
    }
    if (x[i] == n && y[i] == m) {
      hasT = 1;
    }
    if (x[i] > 1) {
      addEdge(i, Max * 1 + x[i] - 1, 1);
      addEdge(Max * 1 + x[i] - 1, i, 0);
    }
    if (x[i] < n) {
      addEdge(i, Max * 1 + x[i] + 1, 1);
      addEdge(Max * 1 + x[i] + 1, i, 0);
    }
    addEdge(i, Max * 1 + x[i], 1);
    addEdge(Max * 1 + x[i], i, 0);
    if (y[i] > 1) {
      addEdge(i, Max * 2 + y[i] - 1, 1);
      addEdge(Max * 2 + y[i] - 1, i, 0);
    }
    if (y[i] < m) {
      addEdge(i, Max * 2 + y[i] + 1, 1);
      addEdge(Max * 2 + y[i] + 1, i, 0);
    }
    addEdge(i, Max * 2 + y[i], 1);
    addEdge(Max * 2 + y[i], i, 0);
  }
  for (int i = 1; i < k; i++) {
    for (int j = i + 1; j <= k; j++) {
      if (isadj(i, j)) {
        addEdge(i, j, 0);
        addEdge(j, i, 0);
      }
    }
  }
  spfa();
  if (hasT)
    for (int i = 1; i <= k; i++) {
      if (isadj(0, i)) {
        ans = min(ans, dis[i]);
      }
    }
  ans = min(ans, dis[n + Max]);
  ans = min(ans, dis[m + Max * 2]);
  if (ans != INF) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
