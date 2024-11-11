#include <bits/stdc++.h>
using namespace std;
int h[212345];
vector<vector<int> > graph;
vector<int> mex;
vector<int> xors;
int get_mex(int v) {
  if (mex[v] != -1) return mex[v];
  vector<bool> seen(graph[v].size(), false);
  for (auto u : graph[v]) {
    int val = get_mex(u);
    if (val < seen.size()) seen[val] = true;
  }
  for (mex[v] = 0; mex[v] < seen.size(); mex[v]++) {
    if (!seen[mex[v]]) break;
  }
  return mex[v];
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &h[i]);
  graph.resize(n);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    graph[a].push_back(b);
  }
  mex.resize(n, -1);
  for (int i = 0; i < n; i++) {
    get_mex(i);
  }
  xors.resize(n, 0);
  int maxmex = 0;
  for (int i = 0; i < n; i++) {
    maxmex = max(maxmex, mex[i]);
    xors[mex[i]] ^= h[i];
  }
  int non_zero_mex = -1;
  for (int i = maxmex; i >= 0; i--) {
    if (xors[i] != 0) {
      non_zero_mex = i;
      break;
    }
  }
  if (non_zero_mex == -1) {
    printf("LOSE\n");
    return 0;
  }
  int v;
  for (v = 0; v < n; v++) {
    if (mex[v] == non_zero_mex)
      if (xors[mex[v]] ^ h[v] < h[v]) break;
  }
  h[v] ^= xors[mex[v]];
  xors[mex[v]] = 0;
  for (auto u : graph[v]) {
    if (xors[mex[u]] != 0) {
      h[u] ^= xors[mex[u]];
      xors[mex[u]] = 0;
    }
  }
  printf("WIN\n");
  for (int i = 0; i < n; i++) {
    printf("%d%c", h[i], (i + 1) == n ? '\n' : ' ');
  }
  return 0;
}
