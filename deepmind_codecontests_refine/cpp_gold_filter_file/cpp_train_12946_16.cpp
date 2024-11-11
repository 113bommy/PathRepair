#include <bits/stdc++.h>
using namespace std;
struct pnode {
  int lz;
  pnode *L, *R;
  pnode(int z = 0, pnode* l = NULL, pnode* r = NULL) {
    lz = z;
    L = l;
    R = r;
  }
};
typedef pnode* node;
int n, ctr = 0, maxn;
vector<node> root;
node dummy;
vector<int> start, depth, en, destroy;
vector<vector<int>> graph, T;
void dfs(int node, int ht) {
  start[node] = ctr++;
  depth[node] = ht;
  for (auto it : graph[node]) dfs(it, ht + 1);
  en[node] = ctr++;
}
void init() {
  for (int j = 1; j <= maxn; j++) {
    for (int i = 0; i < n; i++) {
      if (T[i][j - 1] != -1) {
        T[i][j] = T[T[i][j - 1]][j - 1];
      }
    }
  }
}
int LCA(int x, int y) {
  if (depth[x] > depth[y]) swap(x, y);
  for (int i = maxn; i >= 0; i--) {
    if (depth[y] - (1 << i) >= depth[x]) {
      y = T[y][i];
    }
  }
  if (x == y) return x;
  for (int i = maxn; i >= 0; i--) {
    if (T[x][i] != T[y][i]) {
      x = T[x][i];
      y = T[y][i];
    }
  }
  return T[x][0];
}
int qry(node root, int L, int R, int idx) {
  if (L == R && L == idx)
    return root->lz;
  else {
    if (idx >= L && idx <= (L + R) / 2)
      return root->lz + qry(root->L, L, (L + R) / 2, idx);
    else
      return root->lz + qry(root->R, (L + R) / 2 + 1, R, idx);
  }
}
node upd(node root, int L, int R, int a, int b, int v) {
  if (a > R || b < L)
    return root;
  else if (a <= L && R <= b) {
    return new pnode(root->lz + v, root->L, root->R);
  } else {
    return new pnode(root->lz, upd(root->L, L, (L + R) / 2, a, b, v),
                     upd(root->R, (L + R) / 2 + 1, R, a, b, v));
  }
}
int g(int node, int cur, int yr) {
  if (node == -1) return 0;
  int res = depth[node];
  res -= qry(root[cur], 0, ctr, start[node]);
  res += qry(root[yr], 0, ctr, start[node]);
  return res;
}
int jump(int node, int v) {
  for (int i = maxn; i >= 0; i--) {
    if ((1 << i) <= v) {
      node = T[node][i];
      v -= (1 << i);
    }
  }
  return node;
}
int compute(int a, int b, int k, int cur, int yr) {
  int lc = LCA(a, b);
  int distance = depth[a] + depth[b] - 2 * depth[lc] + 1;
  int res = -1, L = 1, R = distance - 2, mid, v, node;
  while (L <= R) {
    mid = (L + R) / 2;
    if (mid > depth[a] - depth[lc]) {
      node = jump(b, depth[b] - depth[lc] - (mid - (depth[a] - depth[lc])));
      v = g(T[a][0], cur, yr) + g(node, cur, yr) - 2 * g(lc, cur, yr) +
          bool(destroy[lc] <= yr);
    } else {
      node = jump(a, mid);
      v = g(T[a][0], cur, yr) - g(T[node][0], cur, yr);
    }
    if (v < k) {
      L = mid + 1;
    } else {
      res = node + 1;
      R = mid - 1;
    }
  }
  return res;
}
int main(void) {
  dummy = new pnode();
  dummy->L = dummy->R = dummy;
  int m, P, king, t, c, a, b, k, y;
  scanf("%d", &n);
  maxn = int(log2(n)) + 1;
  graph.clear();
  graph.resize(n);
  start.clear();
  start.resize(n);
  en.clear();
  en.resize(n);
  depth.clear();
  depth.resize(n);
  T.clear();
  T.resize(n, vector<int>(maxn + 2, -1));
  for (int i = 0; i < n; i++) {
    scanf("%d", &P);
    P--;
    if (P == -1)
      king = i;
    else {
      T[i][0] = P;
      graph[P].push_back(i);
    }
  }
  dfs(king, 1);
  init();
  scanf("%d", &m);
  root.clear();
  root.resize(m + 1);
  destroy.clear();
  destroy.resize(n, -1);
  root[0] = dummy;
  for (int i = 1; i <= m; i++) {
    root[i] = root[i - 1];
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d", &c);
      c--;
      destroy[c] = i;
      root[i] = upd(root[i - 1], 0, ctr, start[c], en[c], 1);
    } else {
      scanf("%d%d%d%d", &a, &b, &k, &y);
      a--;
      b--;
      printf("%d\n", compute(a, b, k, i, y));
    }
  }
}
