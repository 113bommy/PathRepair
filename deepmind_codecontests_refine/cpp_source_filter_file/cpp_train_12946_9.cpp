#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 5;
int n, root, a[maxN * 2], year[maxN], destroy[maxN];
vector<int> child[maxN];
int first[maxN], last[maxN], counter = 0;
int lca[maxN][19], depth[maxN];
struct Node {
  int left, right, sum;
  Node() {}
  Node(int sum) : sum(sum), left(0), right(0) {}
  Node(int left, int right) : sum(0), left(left), right(right) {}
} it[maxN * 40];
int nNode = 0, ver[maxN], nVer = 0;
int build(int l = 1, int r = 2 * n) {
  int newNode = ++nNode;
  if (l == r) {
    it[newNode] = Node(a[l]);
    return newNode;
  }
  int mid = (l + r) >> 1;
  it[newNode].left = build(l, mid);
  it[newNode].right = build(mid + 1, r);
  it[newNode].sum = it[it[newNode].left].sum + it[it[newNode].right].sum;
  return newNode;
}
int update(int u, int x, int curNode, int l = 1, int r = 2 * n) {
  int newNode = ++nNode;
  if (l == r) {
    it[newNode] = Node(x);
    return newNode;
  }
  int mid = (l + r) >> 1;
  if (u <= mid) {
    it[newNode] =
        Node(update(u, x, it[curNode].left, l, mid), it[curNode].right);
  } else {
    it[newNode] =
        Node(it[curNode].left, update(u, x, it[curNode].right, mid + 1, r));
  }
  it[newNode].sum = it[it[newNode].left].sum + it[it[newNode].right].sum;
  return newNode;
}
void update(int u, int x) {
  nVer++;
  ver[nVer] = update(u, x, ver[nVer - 1]);
}
int get(int u, int v, int curNode, int l = 1, int r = 2 * n) {
  if (l > v || r < u) return 0;
  if (u <= l && r <= v) return it[curNode].sum;
  int mid = (l + r) >> 1;
  return get(u, v, it[curNode].left, l, mid) +
         get(u, v, it[curNode].right, mid + 1, r);
}
int path(int i, int j, int y) {
  return depth[j] - depth[i] + 1 + get(first[i], first[j], ver[nVer]) -
         get(first[i], first[j], ver[year[y]]);
}
void dfs(int u) {
  first[u] = ++counter;
  a[counter] = 1;
  for (int i = 0, _b = (int)child[u].size() - 1; i <= _b; i++)
    depth[child[u][i]] = depth[u] + 1, dfs(child[u][i]);
  last[u] = ++counter;
  a[counter] = -1;
}
void buildLCA() {
  for (int j = 1, _b = 18; j <= _b; j++)
    for (int i = 1, _b = n; i <= _b; i++) lca[i][j] = lca[lca[i][j - 1]][j - 1];
}
int LCA(int u, int v) {
  if (depth[u] > depth[v]) return LCA(v, u);
  for (int j = 18, _b = 0; j >= _b; j--)
    if (lca[v][j] && depth[lca[v][j]] >= depth[u]) v = lca[v][j];
  if (u == v) return u;
  for (int j = 18, _b = 0; j >= _b; j--)
    if (lca[u][j] && lca[u][j] != lca[v][j]) u = lca[u][j], v = lca[v][j];
  return lca[u][0];
}
int solve(int w, int u, int y, int k) {
  int res = u, du = destroy[u] <= y;
  for (int j = 18, _b = 0; j >= _b; j--)
    if (lca[res][j] && depth[lca[res][j]] >= depth[w]) {
      int debug = path(lca[res][j], u, y);
      if (path(lca[res][j], u, y) - du < k) res = lca[res][j];
    }
  return lca[res][0];
}
int main() {
  if (fopen("a.txt", "r")) {
    freopen("a.txt", "r", stdin);
  }
  scanf("%d", &n);
  int parI;
  for (int i = 1, _b = n; i <= _b; i++) {
    scanf("%d", &parI);
    if (!parI)
      root = i;
    else
      child[parI].push_back(i);
    lca[i][0] = parI;
  }
  buildLCA();
  dfs(root);
  ver[0] = build();
  int m;
  scanf("%d", &m);
  int ti, xi, ai, bi, y, k, prevYear = 0;
  for (int t = 1, _b = m; t <= _b; t++) {
    scanf("%d", &ti);
    if (ti == 1) {
      scanf("%d", &xi);
      update(first[xi], 0);
      update(last[xi], 0);
      year[t] = nVer;
      prevYear = t;
      destroy[xi] = t;
    } else {
      year[t] = year[prevYear];
      scanf("%d%d%d%d", &ai, &bi, &k, &y);
      if (ai == bi) {
        printf("-1\n");
        continue;
      }
      int w = LCA(ai, bi), dw = (destroy[w] <= y);
      int da = path(w, ai, y) - (destroy[ai] <= y) - dw * (w != ai),
          db = path(w, bi, y) - (destroy[bi] <= y) - dw * (w != bi);
      if (da + db + dw * (w != ai) * (w != bi) < k) {
        printf("-1\n");
        continue;
      }
      if (da + dw * (w != ai) * (w != bi) >= k) {
        printf("%d\n", solve(w, ai, y, k));
      } else {
        printf("%d\n",
               solve(w, bi, y, da + db + dw * (w != ai) * (w != bi) - k + 1));
      }
    }
  }
  return 0;
}
