#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXP = 16;
const int INF = 1000000000;
vector<int> adj[MAXN];
int maxh[MAXN][3], maxtop[MAXN], depth[MAXN];
int costNeg[MAXN][MAXP + 1], costPlus[MAXN][MAXP + 1], ancestor[MAXN][MAXP + 1];
void updateMax3(int a[3], int b) {
  for (int i = 0; i < 3; ++i)
    if (b > a[i]) {
      for (int j = 2; j > i; --j) a[j] = a[j - 1];
      a[i] = b;
      break;
    }
}
void getMax3(int x, int p = 0) {
  for (auto i = adj[x].begin(); i != adj[x].end(); ++i)
    if (*i != p) {
      getMax3(*i, x);
      updateMax3(maxh[x], maxh[*i][0] + 1);
    }
}
void dfs(int x, int p = 0) {
  ancestor[x][0] = p;
  for (auto i = adj[x].begin(); i != adj[x].end(); ++i)
    if (*i != p) {
      depth[*i] = depth[x] + 1;
      int maxOthers = maxh[*i][0] + 1 == maxh[x][0] ? maxh[x][1] : maxh[x][0];
      costNeg[*i][0] = maxOthers - depth[x];
      costPlus[*i][0] = maxOthers + depth[x];
      maxtop[*i] = max(maxtop[x], maxOthers) + 1;
      dfs(*i, x);
    }
}
int findLCA(int a, int b) {
  for (int p = MAXP; p >= 0; --p)
    if (depth[a] - (1 << p) >= depth[b]) a = ancestor[a][p];
  for (int p = MAXP; p >= 0; --p)
    if (ancestor[a][p] != ancestor[b][p]) {
      a = ancestor[a][p];
      b = ancestor[b][p];
    }
  return a == b ? a : ancestor[a][0];
}
int getMaxCost(int cost[][MAXP + 1], int v, int len, int &resv) {
  int ret = -INF;
  for (int p = MAXP; p >= 0; --p)
    if (len & (1 << p)) {
      ret = max(ret, cost[v][p]);
      v = ancestor[v][p];
    }
  resv = v;
  return ret;
}
int main() {
  int N, M;
  scanf("%d", &N);
  for (int i = 1; i < N; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  getMax3(1);
  dfs(1);
  costNeg[0][0] = costPlus[0][0] = -INF;
  for (int p = 1; p <= MAXP; ++p)
    for (int i = 0; i <= N; ++i) {
      int dad = ancestor[i][p - 1];
      ancestor[i][p] = ancestor[dad][p - 1];
      costNeg[i][p] = max(costNeg[i][p - 1], costNeg[dad][p - 1]);
      costPlus[i][p] = max(costPlus[i][p - 1], costPlus[dad][p - 1]);
    }
  scanf("%d", &M);
  while (M--) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (depth[a] < depth[b]) swap(a, b);
    int c = findLCA(a, b);
    int ac = depth[a] - depth[c], bc = depth[b] - depth[c];
    int pathLen = ac + bc;
    int half = min(pathLen / 2, ac - 1), v, w;
    int aCost = max(maxh[a][0], getMaxCost(costNeg, a, half, v) + depth[a]);
    int bCost = getMaxCost(costPlus, v, ac - 1 - half, v) - depth[c];
    int cPick = 0;
    if (c != b) {
      bCost = max(bCost, getMaxCost(costNeg, b, bc - 1, w) + depth[b]);
      bCost = max(bCost, maxh[b][0]);
      if (max(maxh[v][0], maxh[w][0]) + 1 == maxh[c][cPick]) ++cPick;
      if (min(maxh[v][0], maxh[w][0]) + 1 == maxh[c][cPick]) ++cPick;
    } else {
      if (maxh[v][0] + 1 == maxh[c][cPick]) ++cPick;
    }
    int cCost = max(maxh[c][cPick], maxtop[c]) + min(ac, bc);
    int ans = max(aCost, max(bCost, cCost));
    printf("%d\n", ans);
  }
}
