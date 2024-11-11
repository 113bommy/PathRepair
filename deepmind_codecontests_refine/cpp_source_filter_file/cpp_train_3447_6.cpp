#include <bits/stdc++.h>
using namespace std;
const int mx = 100050;
vector<int> vec[mx];
int sparse[mx][20];
pair<int, int> sf[mx];
int tmm[2 * mx];
int par[mx];
pair<int, int> tree[4 * mx];
int level[mx];
int somoy = 0;
void dfs(int u, int from, int lv) {
  level[u] = lv;
  somoy++;
  tmm[somoy] = u;
  sf[u].first = somoy;
  par[u] = from;
  int i, j, v, l = vec[u].size();
  for (i = 0; i < l; i++) {
    v = vec[u][i];
    dfs(v, u, lv + 1);
  }
  somoy++;
  tmm[somoy] = u;
  sf[u].second = somoy;
}
void buildtree(int l, int r, int idx) {
  if (l == r) {
    tree[idx] = make_pair(sf[l].first, sf[l].second);
    return;
  }
  int mid, lc, rc;
  mid = (l + r) / 2;
  lc = 2 * idx;
  rc = lc + 1;
  buildtree(l, mid, lc);
  buildtree(mid + 1, r, rc);
  tree[idx].first = min(tree[lc].first, tree[rc].first);
  tree[idx].second = max(tree[lc].second, tree[rc].second);
}
pair<int, int> query(int l, int r, int idx, int le, int ri) {
  if (l > ri || r < le) {
    return make_pair(300000, 0);
  }
  if (l >= le && r <= ri) {
    return tree[idx];
  }
  int mid, lc, rc;
  mid = (l + r) / 2;
  lc = 2 * idx;
  rc = lc + 1;
  pair<int, int> a, b, ans;
  a = query(l, mid, lc, le, ri);
  b = query(mid + 1, r, rc, le, ri);
  ans.first = min(a.first, b.first);
  ans.second = max(a.second, b.second);
  return ans;
}
int lca(int p, pair<int, int> ran) {
  int i, j, k, q;
  if (sf[p].first <= ran.first && sf[p].second >= ran.second) return p;
  for (i = 19; i >= 0; i--) {
    q = sparse[p][i];
    if (q == -1) continue;
    if (sf[q].first < ran.first && sf[q].second > ran.second) continue;
    p = q;
  }
  return par[p];
}
int main() {
  int p, n, m, i, j, k, q, u, v, l, r;
  scanf("%d %d", &n, &q);
  for (i = 2; i <= n; i++) {
    scanf("%d", &p);
    vec[p].push_back(i);
  }
  dfs(1, -1, 0);
  for (i = 1; i <= n; i++) vec[i].clear();
  buildtree(1, n, 1);
  for (i = 1; i <= n; i++) sparse[i][0] = par[i];
  for (j = 1; j < 20; j++) {
    for (i = 1; i <= n; i++) {
      if (sparse[i][j - 1] == -1)
        sparse[i][j] = -1;
      else {
        sparse[i][j] = sparse[sparse[i][j - 1]][j - 1];
      }
    }
  }
  pair<int, int> mm;
  int ans1, ans2, ans, x, y, x1, y1, x2, y2;
  while (q--) {
    scanf("%d %d", &l, &r);
    mm = query(1, n, 1, l, r);
    u = tmm[mm.first];
    v = tmm[mm.second];
    if (l == u) {
      x = -1;
    } else {
      mm = query(1, n, 1, l, u - 1);
      x = lca(l, mm);
    }
    if (r == u) {
      y = -1;
    } else {
      mm = query(1, n, 1, u + 1, r);
      y = lca(r, mm);
    }
    if (x == -1) x = y;
    if (y == -1) y = x;
    ans1 = lca(x, make_pair(min(sf[x].first, sf[y].first),
                            max(sf[x].second, sf[y].second)));
    if (l == v) {
      x = -1;
    } else {
      mm = query(1, n, 1, l, v - 1);
      x = lca(l, mm);
    }
    if (r == v) {
      y = -1;
    } else {
      mm = query(1, n, 1, v + 1, r);
      y = lca(r, mm);
    }
    if (x == -1) x = y;
    if (y == -1) y = x;
    ans2 = lca(x, make_pair(min(sf[x].first, sf[y].first),
                            max(sf[x].second, sf[y].second)));
    if (level[ans1] >= level[ans2])
      ans = ans1, p = u;
    else
      ans = ans2, p = v;
    printf("%d %d\n", p, level[ans]);
  }
  return 0;
}
