#include <bits/stdc++.h>
using namespace std;
int parent[10000];
vector<int> g[10000];
bool visited[10000];
int n, r1, r2;
void dfs(int v) {
  visited[v] = true;
  for (int i = 0; i < g[v].size(); i++) {
    int temp = g[v][i];
    if (!visited[temp]) {
      if (temp == r1) {
        parent[temp] = v;
        break;
      } else {
        parent[temp] = v;
        dfs(temp);
      }
    }
  }
}
int main() {
  int a;
  scanf("%d%d%d", &n, &r1, &r2);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a);
    if (i != r1) {
      g[a].push_back(i);
      g[i].push_back(a);
      parent[i] = a;
    } else {
      i++;
      g[a].push_back(i);
      g[i].push_back(a);
      parent[i] = a;
    }
  }
  dfs(r2);
  for (int i = 1; i <= n; i++) {
    if (i != r2) {
      printf("%d ", parent[i]);
    }
  }
  return 0;
}
