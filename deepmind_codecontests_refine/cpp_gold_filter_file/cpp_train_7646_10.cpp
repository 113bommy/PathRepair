#include <bits/stdc++.h>
using namespace std;
vector<int> adj[2005], adjcolors[2005];
int endCicles[2005];
bool vis[2005];
map<pair<int, int>, bool> inCicle;
int dfs(int u, int pai) {
  if (vis[u]) {
    endCicles[u]++;
    return 1;
  }
  vis[u] = true;
  int cicles = 0;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == pai || inCicle[make_pair(u, v)]) continue;
    int ret = dfs(v, u);
    if (ret > 0) {
      cicles += ret;
      inCicle[make_pair(u, v)] = true;
      inCicle[make_pair(v, u)] = true;
    }
  }
  cicles -= endCicles[u];
  endCicles[u] = 0;
  return cicles;
}
int c[2005];
int csize[2005];
void color(int u, int col) {
  c[u] = col;
  csize[col]++;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (c[v] || !inCicle[make_pair(u, v)]) continue;
    color(v, col);
  }
}
int dpSize[2005][2005];
int getSize(int u, int pai) {
  if (dpSize[u][pai]) return dpSize[u][pai];
  dpSize[u][pai] = csize[u];
  for (int i = 0; i < adjcolors[u].size(); i++) {
    int v = adjcolors[u][i];
    if (v == pai) continue;
    dpSize[u][pai] += getSize(v, u);
  }
  return dpSize[u][pai];
}
int dpSolve[2005][2005];
int solve(int u, int pai) {
  if (dpSolve[u][pai]) return dpSolve[u][pai];
  dpSolve[u][pai] = csize[u] * csize[u];
  for (int i = 0; i < adjcolors[u].size(); i++) {
    int v = adjcolors[u][i];
    if (v == pai) continue;
    dpSolve[u][pai] += csize[u] * getSize(v, u) + solve(v, u);
  }
  return dpSolve[u][pai];
}
int main() {
  int n, m;
  scanf(" %d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf(" %d %d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 0);
  int colors = 0;
  for (int i = 1; i <= n; i++)
    if (!c[i]) color(i, ++colors);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      int v = adj[i][j];
      if (c[i] != c[v] && i < v) {
        adjcolors[c[i]].push_back(c[v]);
        adjcolors[c[v]].push_back(c[i]);
      }
    }
  }
  int bestAnswer = 0;
  for (int i = 1; i <= colors; i++) {
    int ans = csize[i] * n;
    vector<int> sizes;
    int sum = 0;
    for (int j = 0; j < adjcolors[i].size(); j++) {
      int v = adjcolors[i][j];
      ans += solve(v, i);
      sizes.push_back(getSize(v, i));
      sum += sizes.back();
    }
    bool bag[2005];
    memset(bag, false, sizeof(bag));
    bag[0] = true;
    int ret = 0;
    for (int j = 0; j < sizes.size(); j++) {
      for (int k = (sum / 2) - sizes[j]; k >= 0; k--) {
        if (bag[k] == true) {
          bag[k + sizes[j]] = true;
          ret = max(ret, k + sizes[j]);
        }
      }
    }
    ans += ret * (sum - ret);
    bestAnswer = max(bestAnswer, ans);
  }
  printf("%d", bestAnswer);
  return 0;
}
