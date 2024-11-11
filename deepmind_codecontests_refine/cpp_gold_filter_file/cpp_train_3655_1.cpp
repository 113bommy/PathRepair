#include <bits/stdc++.h>
using namespace std;
inline int setBit(int N, int pos) { return N = N | (1 << pos); }
inline int resetBit(int N, int pos) { return N = N & ~(1 << pos); }
inline bool checkBit(int N, int pos) { return (bool)(N & (1 << pos)); }
namespace Lowest {
vector<int> E[300000 + 10];
int val[300000 + 10], parent[300000 + 10], parentVal[300000 + 10],
    sparseVal[20 + 2][300000 + 10], sparseTable[20 + 2][300000 + 10],
    level[300000 + 10], n;
void dfs(int node, int par, int currentLevel) {
  parent[node] = par;
  parentVal[node] = val[par];
  level[node] = currentLevel + 1;
  for (auto v : E[node]) {
    if (v != par) dfs(v, node, currentLevel + 1);
  }
}
void initSparseTable(vector<int> tree[], int _n, int value[]) {
  n = _n;
  val[0] = 0;
  for (int i = 1; i <= n; i++) E[i] = tree[i], val[i] = value[i];
  dfs(1, 0, 1);
  for (int i = 1; i <= n; i++)
    sparseTable[0][i] = parent[i], sparseVal[0][i] = parentVal[i];
  for (int p = 1; p <= 20; p++) {
    for (int u = 1; u <= n; u++) {
      sparseVal[p][u] =
          sparseVal[p - 1][sparseTable[p - 1][u]] + sparseVal[p - 1][u];
      sparseTable[p][u] = sparseTable[p - 1][sparseTable[p - 1][u]];
    }
  }
}
int findLCA(int u, int v) {
  if (level[v] > level[u]) swap(u, v);
  for (int i = 20; i >= 0; i--) {
    if ((1 << i) <= level[u] - level[v]) u = sparseTable[i][u];
  }
  if (u == v) return v;
  for (int i = 20; i >= 0; i--) {
    if (sparseTable[i][u] != sparseTable[i][v])
      u = sparseTable[i][u], v = sparseTable[i][v];
  }
  return parent[v];
}
int getDist(int u, int v) {
  if (level[v] > level[u]) swap(u, v);
  int ret = val[u];
  for (int i = 20; i >= 0; i--) {
    if ((1 << i) <= level[u] - level[v]) {
      ret += sparseVal[i][u];
      u = sparseTable[i][u];
    }
  }
  if (u == v) return ret;
  ret += val[v];
  for (int i = 20; i >= 0; i--) {
    if (sparseTable[i][u] != sparseTable[i][v]) {
      ret += sparseVal[i][u] + sparseVal[i][v];
      u = sparseTable[i][u], v = sparseTable[i][v];
    }
  }
  ret += sparseVal[0][v];
  return ret;
}
}  // namespace Lowest
namespace BCT {
vector<int> E[300000 + 10], stck, BCC[300000 + 10], AP, myBCC[300000 + 10];
int n, m, low[300000 + 10], disc[300000 + 10], BCC_cnt, parent[300000 + 10],
    sizeOfBCC[300000 + 10];
bool vis[300000 + 10], pushed[300000 + 10], isAP[300000 + 10];
bool checkAP(int u, int v, int children) {
  if (parent[u] == -1) {
    if (children > 1) return true;
    return false;
  } else {
    if (low[v] >= disc[u]) return true;
    return false;
  }
}
void dfs(int node) {
  vis[node] = 1;
  stck.push_back(node);
  if (parent[node] == -1)
    disc[node] = low[node] = 1;
  else
    disc[node] = low[node] = disc[parent[node]] + 1;
  int children = 0, v, u = node;
  for (int i = 0; i < E[u].size(); i++) {
    v = E[u][i];
    if (!vis[v]) {
      children++;
      parent[v] = u;
      dfs(v);
      low[u] = min(low[u], low[v]);
      if (checkAP(u, v, children)) {
        if (!pushed[u]) AP.push_back(u);
        pushed[u] = 1;
        BCC_cnt++;
        myBCC[u].push_back(BCC_cnt);
        BCC[BCC_cnt].push_back(u);
        while (true) {
          int nw = stck.back();
          myBCC[nw].push_back(BCC_cnt);
          BCC[BCC_cnt].push_back(nw);
          stck.pop_back();
          if (nw == v) break;
        }
      }
    } else if (v != parent[u])
      low[u] = min(low[u], disc[v]);
  }
  return;
}
void find_BCC() {
  for (int i = 0; i <= 300000; i++) BCC[i].clear(), myBCC[i].clear();
  memset((parent), -1, sizeof(parent));
  BCC_cnt = 0;
  memset((vis), 0, sizeof(vis));
  AP.clear();
  memset((pushed), 0, sizeof(pushed));
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
      if (!stck.empty()) BCC_cnt++;
      while (!stck.empty()) {
        myBCC[stck.back()].push_back(BCC_cnt);
        BCC[BCC_cnt].push_back(stck.back());
        stck.pop_back();
      }
    }
  }
}
vector<int> tree[300000 + 10];
int value[300000 + 10];
void createBlockCutTree(int _n, int &nNode) {
  memset((isAP), 0, sizeof(isAP));
  for (int i = 1; i <= 300000; i++) tree[i].clear();
  n = _n;
  find_BCC();
  for (int i = 1; i <= BCC_cnt; i++) sizeOfBCC[i] = BCC[i].size();
  for (int i = 1; i <= n; i++) {
    if (myBCC[i].size() > 1) {
      BCC_cnt++;
      for (int j = 0; j < myBCC[i].size(); j++) {
        int u = myBCC[i][j];
        int v = BCC_cnt;
        tree[u].push_back(v);
        tree[v].push_back(u);
        sizeOfBCC[u]--;
      }
      myBCC[i].push_back(BCC_cnt);
      BCC[BCC_cnt].push_back(i);
      isAP[BCC_cnt] = true;
      sizeOfBCC[BCC_cnt] = 1;
    }
  }
  nNode = BCC_cnt;
  for (int i = 1; i <= nNode; i++) {
    if (isAP[i] == 0)
      value[i] = 1;
    else
      value[i] = 0;
  }
  Lowest::initSparseTable(tree, nNode, value);
}
int solve(int u, int v) {
  if (u == v) return 0;
  u = myBCC[u].back();
  v = myBCC[v].back();
  return Lowest::getDist(u, v);
}
}  // namespace BCT
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int q;
  scanf("%d", &q);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    BCT::E[u].push_back(v);
    BCT::E[v].push_back(u);
  }
  int bla;
  BCT::createBlockCutTree(n, bla);
  while (q--) {
    int u, v;
    scanf("%d %d", &u, &v);
    printf("%d\n", BCT::solve(u, v));
  }
}
