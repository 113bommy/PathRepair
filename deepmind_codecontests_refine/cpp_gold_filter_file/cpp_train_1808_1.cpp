#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:50000000")
using namespace std;
const int MOD = 1000000007;
const int nmax = 100000;
vector<int> adj[nmax];
int depth[nmax], black[nmax];
int par[nmax][18];
int cycleNum[nmax];
int pow2[nmax];
vector<int> st;
bool stacked[nmax];
void dfsCycles(int v, int p) {
  stacked[v] = true;
  st.push_back(v);
  for (int i = 0; i < adj[v].size(); i++) {
    int w = adj[v][i];
    if (w == p) continue;
    if (stacked[w]) {
      for (int j = st.size() - 1; j >= 0; j--) {
        cycleNum[st[j]] = w;
        if (st[j] == w) break;
      }
      continue;
    }
    dfsCycles(w, v);
  }
  st.pop_back();
  stacked[v] = false;
}
void dfsTree(int v, int p, int d, int b) {
  depth[v] = d;
  if (cycleNum[v] != -1) ++b;
  black[v] = b;
  par[v][0] = p;
  for (int i = 1; i < 18; i++)
    if (par[v][i - 1] == -1)
      par[v][i] = -1;
    else
      par[v][i] = par[par[v][i - 1]][i - 1];
  for (int i = 0; i < adj[v].size(); i++) {
    int w = adj[v][i];
    if (w == p) continue;
    dfsTree(w, v, d + 1, b);
  }
}
int getLCA(int u, int v) {
  int i;
  if (depth[u] < depth[v]) swap(u, v);
  for (i = 17; i >= 0; i--)
    if (depth[u] - (1 << i) >= depth[v]) u = par[u][i];
  if (u == v) return u;
  for (i = 17; i >= 0; i--) {
    if (par[u][i] != par[v][i]) {
      u = par[u][i];
      v = par[v][i];
    }
  }
  return par[u][0];
}
int getBlack(int u, int v) {
  if (cycleNum[u] != -1) u = cycleNum[u];
  if (cycleNum[v] != -1) v = cycleNum[v];
  int p = getLCA(u, v);
  return black[u] + black[v] - 2 * black[p] + (cycleNum[p] != -1);
}
int main() {
  int t, i, j, k, n, m, x1, y1, z1, x, y, z;
  scanf("%d%d", &n, &m);
  while (m--) {
    scanf("%d%d", &i, &j);
    --i;
    --j;
    adj[i].push_back(j);
    adj[j].push_back(i);
  }
  memset(cycleNum, -1, sizeof(cycleNum));
  dfsCycles(0, -1);
  for (i = 0; i < n; i++) {
    if (cycleNum[i] == -1 || cycleNum[i] == i) continue;
    for (j = 0; j < adj[i].size(); j++) adj[cycleNum[i]].push_back(adj[i][j]);
  }
  for (i = 0; i < n; i++) {
    if (cycleNum[i] != -1 && cycleNum[i] != i) continue;
    for (j = 0; j < adj[i].size(); j++) {
      k = adj[i][j];
      if (cycleNum[k] == -1) continue;
      if (cycleNum[k] == i) {
        adj[i][j] = adj[i].back();
        adj[i].pop_back();
        --j;
      } else {
        adj[i][j] = cycleNum[k];
      }
    }
  }
  memset(par, -1, sizeof(par));
  dfsTree(cycleNum[0] == -1 ? 0 : cycleNum[0], -1, 0, 0);
  pow2[0] = 1;
  for (i = 1; i < nmax; i++) pow2[i] = pow2[i - 1] * 2 % MOD;
  scanf("%d", &m);
  while (m--) {
    scanf("%d%d", &i, &j);
    printf("%d\n", pow2[getBlack(i - 1, j - 1)]);
  }
  return 0;
}
