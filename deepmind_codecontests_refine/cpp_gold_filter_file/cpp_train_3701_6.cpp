#include <bits/stdc++.h>
using namespace std;
vector<int> adj[200001];
vector<int> root;
bool visited[200001];
bool visited2[200001];
int par[200001];
int change;
void dfs(int i) {
  for (int next : adj[i]) {
    if (!visited[next]) {
      visited[next] = true;
      dfs(next);
    }
  }
}
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int t;
    scanf("%d", &t);
    if (t != i)
      adj[t].push_back(i);
    else
      root.push_back(i);
    par[i] = t;
  }
  int cnt = 0;
  for (int i : root) {
    if (i == root[0]) cnt--;
    visited[i] = true;
    dfs(i);
    cnt++;
    par[i] = root[0];
  }
  bool exist = true;
  if (root.size() == 0) exist = false;
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      int p = par[i];
      visited2[i] = true;
      while (!visited2[p]) {
        visited2[p] = true;
        p = par[p];
      }
      if (!exist) {
        root.push_back(p);
        exist = true;
        visited[p] = true;
        dfs(p);
        cnt++;
        par[p] = root[0];
      } else {
        visited[p] = true;
        dfs(p);
        cnt++;
        par[p] = root[0];
      }
    }
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= n; i++) printf("%d ", par[i]);
}
