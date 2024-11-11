#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)2e5 + 5;
const int inf = 1 << 29;
int n, m, ans[maxN];
vector<pair<int, int> > mstG[maxN];
vector<pair<int, pair<int, int> > > E;
map<pair<int, pair<int, int> >, int> eind;
int mpar[maxN], inMST[maxN];
void resetpar() {
  for (int i = 0; i < n; i++) mpar[i] = i;
}
int findpar(int x) {
  if (mpar[x] != x) mpar[x] = findpar(mpar[x]);
  return mpar[x];
}
void mst() {
  sort(E.begin(), E.end());
  resetpar();
  for (int i = 0; i < m; i++) {
    int a = E[i].second.first, b = E[i].second.second, c = E[i].first;
    int p1 = findpar(a), p2 = findpar(b);
    if (p1 != p2) {
      inMST[eind[pair<int, pair<int, int> >(c, pair<int, int>(a, b))]] = 1;
      mstG[a].push_back(pair<int, int>(b, c));
      mstG[b].push_back(pair<int, int>(a, c));
      mpar[p1] = p2;
    }
  }
}
int depth[maxN], tpar[maxN][20], maxE[maxN][20], tind[maxN];
void dfs(int cur, int pre, int d, int w) {
  depth[cur] = d;
  tpar[cur][0] = pre;
  maxE[cur][0] = w;
  for (int i = 1; i < 20; i++) {
    tpar[cur][i] = tpar[tpar[cur][i - 1]][i - 1];
    maxE[cur][i] = max(maxE[cur][i - 1], maxE[tpar[cur][i - 1]][i - 1]);
  }
  for (int i = 0; i < (int)mstG[cur].size(); i++) {
    int nxt = mstG[cur][i].first, nw = mstG[cur][i].second;
    if (nxt != pre) {
      tind[nxt] =
          eind[pair<int, pair<int, int> >(nw, pair<int, int>(cur, nxt))];
      dfs(nxt, cur, d + 1, nw);
    }
  }
}
int lca(int x, int y) {
  if (depth[x] > depth[y]) swap(x, y);
  for (int i = 19; i >= 0; i--) {
    if (depth[tpar[y][i]] >= depth[x]) y = tpar[y][i];
  }
  for (int i = 19; i >= 0; i--) {
    if (tpar[x][i] != tpar[y][i]) {
      x = tpar[x][i];
      y = tpar[y][i];
    }
  }
  return x == y ? y : tpar[y][0];
}
int findMaxEdge(int x, int y) {
  int res = 0;
  for (int i = 19; i >= 0; i--) {
    if (depth[tpar[y][i]] >= depth[x]) {
      res = max(res, maxE[y][i]);
      y = tpar[y][i];
    }
  }
  return res;
}
int calcNotIn(int x, int y) {
  int l = lca(x, y);
  return max(findMaxEdge(l, y), findMaxEdge(l, x));
}
int main(int argc, char** argv) {
  cin >> n >> m;
  int u, v, c;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> c;
    u--;
    v--;
    E.push_back(pair<int, pair<int, int> >(c, pair<int, int>(u, v)));
    eind[pair<int, pair<int, int> >(c, pair<int, int>(u, v))] = i;
    eind[pair<int, pair<int, int> >(c, pair<int, int>(v, u))] = i;
  }
  mst();
  dfs(0, 0, 0, 0);
  for (int i = 0; i < n; i++) ans[i] = inf;
  resetpar();
  for (int i = 0; i < m; i++) {
    if (!inMST[eind[E[i]]]) {
      u = E[i].second.first;
      v = E[i].second.second;
      ans[eind[E[i]]] = calcNotIn(u, v) - 1;
      while (1) {
        u = findpar(u);
        v = findpar(v);
        if (u == v) break;
        if (depth[v] > depth[u]) swap(v, u);
        ans[tind[u]] = E[i].first - 1;
        mpar[u] = findpar(tpar[u][0]);
      }
    }
  }
  for (int i = 0; i < m; i++) cout << ((ans[i] == inf) ? -1 : ans[i]) << ' ';
  return 0;
}
