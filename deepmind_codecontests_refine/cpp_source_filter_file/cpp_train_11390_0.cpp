#include <bits/stdc++.h>
using namespace std;
const int MAX = 500100;
int n, q;
vector<vector<int> > g;
int m = 0;
int pos[MAX];
int last[MAX];
int st[MAX * 4], lz[MAX * 4];
int chainNo = 0, chainHead[MAX], chainInd[MAX], chainPos[MAX], chainSize[MAX];
int subSz[MAX], par[MAX];
vector<vector<int> > chain;
vector<vector<int> > chainlz;
void hld(int u, int p = -1) {
  if (chainHead[chainNo] == -1) chainHead[chainNo] = u;
  chainInd[u] = chainNo;
  chainPos[u] = chainSize[chainNo]++;
  int M = 0, idx;
  for (int i = 0; i < (int)g[u].size(); i++) {
    int v = g[u][i];
    if (v != p) {
      if (M < subSz[v]) {
        idx = v;
        M = subSz[v];
      }
    }
  }
  if (M > 0) {
    hld(idx, u);
  }
  for (int i = 0; i < (int)g[u].size(); i++) {
    int v = g[u][i];
    if (v != p && v != idx) {
      chainNo++;
      hld(v, u);
    }
  }
}
int dfs(int u, int p = -1) {
  pos[u] = m++;
  subSz[u] = 1;
  par[u] = -1;
  for (int i = 0; i < (int)g[u].size(); i++) {
    int v = g[u][i];
    if (v != p) {
      subSz[u] += dfs(v, u);
    }
  }
  last[u] = m - 1;
  return subSz[u];
}
void update(int* st, int* lz, int node, int second, int e, int i, int j,
            int val) {
  if (lz[node] != 0) {
    st[node] = lz[node];
    if (second != e) {
      lz[2 * node + 1] = lz[2 * node + 2] = lz[node];
    }
    lz[node] = 0;
  }
  if (second > j || e < i) return;
  if (second >= i && e <= j) {
    st[node] = val;
    if (e != second) {
      lz[2 * node + 1] = lz[2 * node + 2] = val;
    }
    return;
  }
  update(st, lz, 2 * node + 1, second, (second + e) / 2, i, j, val);
  update(st, lz, 2 * node + 2, (second + e) / 2 + 1, e, i, j, val);
  st[node] = max(st[2 * node + 1], st[2 * node + 2]);
}
void update(vector<int>& st, vector<int>& lz, int node, int second, int e,
            int i, int j, int val) {
  if (lz[node] != 0) {
    st[node] = lz[node];
    if (second != e) {
      lz[2 * node + 1] = lz[2 * node + 2] = lz[node];
    }
    lz[node] = 0;
  }
  if (second > j || e < i) return;
  if (second >= i && e <= j) {
    st[node] = val;
    if (e != second) {
      lz[2 * node + 1] = lz[2 * node + 2] = val;
    }
    return;
  }
  update(st, lz, 2 * node + 1, second, (second + e) / 2, i, j, val);
  update(st, lz, 2 * node + 2, (second + e) / 2 + 1, e, i, j, val);
  st[node] = max(st[2 * node + 1], st[2 * node + 2]);
}
int query(int* st, int* lz, int node, int second, int e, int i) {
  if (lz[node] != 0) {
    st[node] = lz[node];
    if (second != e) {
      lz[2 * node + 1] = lz[2 * node + 2] = lz[node];
    }
    lz[node] = 0;
  }
  if (second > i || e < i) return -1;
  if (second == e) return st[node];
  return max(query(st, lz, 2 * node + 1, second, (second + e) / 2, i),
             query(st, lz, 2 * node + 2, (second + e) / 2 + 1, e, i));
}
void update(int u, int k) {
  if (u == -1) return;
  update(chain[chainInd[u]], chainlz[chainInd[u]], 0, 0,
         chainSize[chainInd[u]] - 1, 0, chainPos[u], k);
  update(par[chainHead[chainInd[u]]], k);
}
int main() {
  scanf("%d", &n);
  g.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    swap(u, v);
    g[u].push_back(v);
  }
  dfs(0);
  memset(st, 0, sizeof st);
  memset(lz, 0, sizeof lz);
  memset(chainHead, 0, sizeof chainHead);
  memset(chainSize, 0, sizeof chainSize);
  hld(0);
  chain.resize(++chainNo);
  chainlz.resize(chainNo);
  for (int i = 0; i < (int)chain.size(); i++) {
    chain[i].resize(chainSize[i] * 4, 0);
    chainlz[i].resize(chainSize[i] * 4, 0);
  }
  scanf("%d", &q);
  for (int k = 1; k <= q; k++) {
    int t, u;
    scanf("%d%d", &t, &u);
    --u;
    if (t == 1) {
      update(st, lz, 0, 0, n - 1, pos[u], last[u], k);
    } else if (t == 2) {
      update(u, k);
    } else {
      int a = query(st, lz, 0, 0, n - 1, pos[u]);
      int b = query(&chain[chainInd[u]][0], &chainlz[chainInd[u]][0], 0, 0,
                    chainSize[chainInd[u]] - 1, chainPos[u]);
      if (a > b)
        printf("1\n");
      else
        printf("0\n");
    }
  }
  return 0;
}
