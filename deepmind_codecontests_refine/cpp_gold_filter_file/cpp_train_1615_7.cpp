#include <bits/stdc++.h>
using namespace std;
const int maxN = 13e4;
vector<int> adjList[maxN];
int n, m, u, v;
bool inT[maxN], ua[maxN];
bool mark(int cur, int fr) {
  bool ret = 0;
  for (int i = 0; i < adjList[cur].size(); ++i)
    if (adjList[cur][i] != fr) ret |= mark(adjList[cur][i], cur);
  ret |= ua[cur];
  if (ret) inT[cur] = 1;
  return ret;
}
map<pair<int, int>, int> memo, vis;
int solve(int cur, int fr) {
  if (!inT[cur]) return -1;
  int &ret = memo[pair<int, int>(cur, fr)];
  if (vis[pair<int, int>(cur, fr)]++) return ret;
  for (int i = 0; i < adjList[cur].size(); ++i)
    if (adjList[cur][i] != fr) ret = max(ret, 1 + solve(adjList[cur][i], cur));
  return ret;
}
int main() {
  scanf("%d", &n), scanf("%d", &m);
  for (int i = 0; i < n - 1; ++i) {
    scanf("%d", &u), scanf("%d", &v);
    --u, --v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  for (int i = 0; i < m; ++i) scanf("%d", &v), ua[v - 1] = 1;
  mark(v - 1, -1);
  int out = 0, d = -1, id;
  for (int i = 0; i < n; ++i)
    if (inT[i])
      for (int j = 0; j < adjList[i].size(); ++j) out += inT[adjList[i][j]];
  for (int i = 0; i < n; ++i) {
    if (solve(i, n) > d) d = solve(i, n), id = i;
  }
  cout << id + 1 << "\n" << out - d;
}
