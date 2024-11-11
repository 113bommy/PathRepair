#include <bits/stdc++.h>
using namespace std;
const int maxn = 200100;
const long long INF = LLONG_MAX;
vector<long long> adj[maxn];
vector<pair<int, int> > Edge;
int L[maxn], pre[maxn][20], P[maxn];
int chainHead[maxn], chainPos[maxn], chainInd[maxn], chainSize[maxn],
    posInBase[maxn], children[maxn];
long long Base[maxn], ST[4 * maxn];
int chainNo = 0, TIME = 0;
long long mul(long long L, long long R) {
  if (L <= INF / R) {
    return L * R;
  } else {
    return INF;
  }
}
class SegmentTree {
 public:
  void constructST(int s, int e, int c) {
    if (s == e) {
      ST[c] = Base[s];
      return;
    }
    int m = (s + e) >> 1;
    constructST(s, m, c + c + 1);
    constructST(m + 1, e, c + c + 2);
    ST[c] = mul(ST[c + c + 1], ST[c + c + 2]);
    return;
  }
  void updateST(int c, int s, int e, int x, long long val) {
    if (s == e) {
      ST[c] = val;
      return;
    }
    int mid = (s + e) >> 1;
    if (x <= mid)
      updateST(c + c + 1, s, mid, x, val);
    else
      updateST(c + c + 2, mid + 1, e, x, val);
    { ST[c] = mul(ST[c + c + 1], ST[c + c + 2]); }
    return;
  }
  long long queryST(int c, int s, int e, int L, int R) {
    if (s > R || e < L || s > e) return 1;
    if (s >= L && e <= R) return ST[c];
    int mid = (s + e) >> 1;
    long long pp = queryST(c + c + 1, s, mid, L, R);
    long long qq = queryST(c + c + 2, mid + 1, e, L, R);
    return mul(pp, qq);
  }
};
class WeightedGraph {
 public:
  void addEdge(int x, int y, long long c) {
    adj[x].push_back(y);
    adj[x].push_back(c);
    adj[y].push_back(x);
    adj[y].push_back(c);
    Edge.push_back(make_pair(x, y));
    return;
  }
  pair<int, int> get_ithEdge(int i) { return Edge[i]; }
  void dfs(int x) {
    for (int i = 0; i < adj[x].size(); i += 2) {
      int v = adj[x][i];
      long long val = adj[x][i + 1];
      if (v != P[x]) {
        P[v] = x;
        L[v] = L[x] + 1;
        dfs(v);
        children[x] += children[v];
      }
    }
    children[x]++;
    return;
  }
  void explore(int n) {
    for (int i = 0; i < n + 1; i++)
      for (int j = 0; (1 << j) < n; j++) pre[i][j] = -1;
    dfs(0);
    for (int i = 0; i < n + 1; i++) pre[i][0] = P[i];
    for (int j = 1; (1 << j) < n; j++)
      for (int i = 0; i < n + 1; i++)
        if (pre[i][j - 1] != -1) pre[i][j] = pre[pre[i][j - 1]][j - 1];
    return;
  }
  void decompose(int cur, long long cost) {
    if (chainHead[chainNo] == -1) chainHead[chainNo] = cur;
    chainInd[cur] = chainNo;
    chainPos[cur] = chainSize[chainNo];
    chainSize[chainNo]++;
    posInBase[cur] = TIME;
    Base[TIME++] = cost;
    int id = -1, maxC = -1;
    long long ncost;
    for (int i = 0; i < adj[cur].size(); i += 2) {
      if (adj[cur][i] == P[cur]) continue;
      if (children[adj[cur][i]] > maxC) {
        maxC = children[adj[cur][i]];
        ncost = adj[cur][i + 1];
        id = i;
      }
    }
    if (id >= 0) decompose(adj[cur][id], ncost);
    for (int i = 0; i < adj[cur].size(); i += 2) {
      if (adj[cur][i] == P[cur] || i == id) continue;
      chainNo++;
      decompose(adj[cur][i], adj[cur][i + 1]);
    }
    return;
  }
  int getLCA(int x, int y) {
    if (L[x] < L[y]) swap(x, y);
    int lg = 19;
    ;
    for (int i = lg; i >= 0; i--)
      if (L[x] - (1 << i) >= L[y]) x = pre[x][i];
    if (x == y) return x;
    for (int i = lg; i >= 0; i--) {
      if (pre[x][i] != -1 && pre[x][i] != pre[y][i]) {
        x = pre[x][i];
        y = pre[y][i];
      }
    }
    return P[x];
  }
  long long go_up(int u, int v, int n, SegmentTree HLDtree) {
    if (v == u) return 1;
    long long uchain, vchain = chainInd[v], ans = 1;
    while (true) {
      long long temp;
      uchain = chainInd[u];
      if (uchain == vchain) {
        if (u != v) {
          temp = HLDtree.queryST(0, 0, n - 1, posInBase[v] + 1, posInBase[u]);
          ans = mul(ans, temp);
        }
        break;
      }
      temp = HLDtree.queryST(0, 0, n - 1, posInBase[chainHead[uchain]],
                             posInBase[u]);
      ans = mul(ans, temp);
      u = P[chainHead[uchain]];
    }
    return ans;
  }
  void initChainheads(int n) {
    for (int i = 0; i < n; i++) chainHead[i] = -1;
    return;
  }
  void clearGraph(int n) {
    for (int i = 0; i < n; i++) adj[i].clear();
    return;
  }
};
int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  WeightedGraph g;
  SegmentTree Stree;
  for (int i = 1; i < n; i++) {
    int x, y;
    long long c;
    scanf("%d %d %I64d", &x, &y, &c);
    g.addEdge(x - 1, y - 1, c);
  }
  g.initChainheads(n);
  g.explore(n);
  g.decompose(0, 1);
  Stree.constructST(0, n - 1, 0);
  while (q--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int u, v;
      long long y;
      scanf("%d %d %I64d", &u, &v, &y);
      int lca = g.getLCA(u - 1, v - 1);
      long long uans = g.go_up(u - 1, lca, n, Stree);
      long long vans = g.go_up(v - 1, lca, n, Stree);
      long long ans = y / mul(uans, vans);
      printf("%I64d\n", ans);
    } else {
      int edgeNo;
      long long val;
      scanf("%d %I64d", &edgeNo, &val);
      pair<int, int> edge = g.get_ithEdge(edgeNo - 1);
      int u = edge.first, v = edge.second;
      if (L[v] < L[u]) swap(u, v);
      Stree.updateST(0, 0, n - 1, posInBase[v], val);
    }
  }
  return 0;
}
