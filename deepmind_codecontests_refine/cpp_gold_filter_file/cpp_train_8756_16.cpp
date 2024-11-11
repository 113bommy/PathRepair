#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
struct Node {
  int an;
  int cid[2];
  Node(int _an = -1, int _cid0 = -1, int _cid1 = -1) : an(_an) {
    cid[0] = _cid0;
    cid[1] = _cid1;
  }
  Node(const Node &Right) : an(Right.an) {
    cid[0] = Right.cid[0];
    cid[1] = Right.cid[1];
  }
} tree[MAXN << 2];
int n;
int up[MAXN][20], nid[MAXN], dep[MAXN], val[MAXN], tid[MAXN], tdep[MAXN << 2];
vector<int> child[MAXN];
int LOG[MAXN];
void init() {
  int two = 1;
  int cnt = 0;
  for (int i = 0; i < MAXN; i++) {
    if (i >= two * 2) {
      cnt++;
      two <<= 1;
    }
    LOG[i] = cnt;
  }
  memset(up, -1, sizeof(up));
  memset(nid, -1, sizeof(nid));
}
void initLCA(int id = 1, int fa = -1, int d = 0) {
  dep[id] = d;
  up[id][0] = fa;
  for (int i = 1; i < 20 && up[id][i - 1] != -1; i++) {
    up[id][i] = up[up[id][i - 1]][i - 1];
  }
  for (auto cid : child[id]) {
    initLCA(cid, id, d + 1);
  }
}
int LCA(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int dis = dep[x] - dep[y];
  while (dis) {
    int i = LOG[dis];
    dis -= (1 << i);
    x = up[x][i];
  }
  if (x == y) return x;
  for (int i = 19; i >= 0; i--) {
    if (up[x][i] != up[y][i]) {
      x = up[x][i];
      y = up[y][i];
    }
  }
  return up[x][0];
}
inline int maxdep(int x, int y) {
  if (dep[x] < dep[y]) return y;
  return x;
}
inline int mindep(int x, int y) {
  if (dep[x] < dep[y]) return x;
  return y;
}
void merge(Node &rt, const Node &ls, const Node &rs) {
  if (ls.an == -1 || rs.an == -1) {
    rt.an = -1;
    return;
  }
  int cid[4] = {ls.cid[0], ls.cid[1], rs.cid[0], rs.cid[1]};
  int minv = MAXN;
  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 4; j++) {
      int a = LCA(cid[i], cid[j]);
      if (dep[a] < minv) {
        rt.cid[0] = cid[i];
        rt.cid[1] = cid[j];
        rt.an = a;
        minv = dep[a];
      } else if (dep[a] == minv) {
      }
    }
  }
  if (dep[rt.cid[0]] < dep[rt.cid[1]]) swap(rt.cid[0], rt.cid[1]);
  int tmpcid[2] = {rt.cid[0], rt.cid[1]};
  for (int i = 0; i < 4; i++) {
    if (cid[i] == rt.cid[0] || cid[i] == rt.cid[1]) continue;
    bool flag = false;
    int lasta = rt.an;
    for (int j = 0; j < 2 && !flag; j++) {
      if (lasta != rt.an) continue;
      int tmpa = LCA(cid[i], tmpcid[j]);
      if (tmpa == tmpcid[j] || tmpa == cid[i]) {
        tmpcid[j] = maxdep(tmpcid[j], cid[i]);
        flag = true;
      }
      lasta = tmpa;
    }
    if (!flag) {
      rt.an = -1;
      return;
    }
  }
  rt.cid[0] = tmpcid[0];
  rt.cid[1] = tmpcid[1];
  if (dep[rt.cid[0]] < dep[rt.cid[1]]) swap(rt.cid[0], rt.cid[1]);
}
void pushUp(int id) { merge(tree[id], tree[(id << 1)], tree[(id << 1 | 1)]); }
void buildTree(int l, int r, int id, int d = 0) {
  Node &rt = tree[id];
  tdep[id] = d;
  if (l == r) {
    rt.an = rt.cid[0] = rt.cid[1] = nid[l];
    tid[l] = id;
    return;
  }
  int mid = (l + r) >> 1;
  buildTree(l, mid, id << 1, d + 1);
  buildTree(mid + 1, r, id << 1 | 1, d + 1);
  pushUp(id);
}
void update(int x, int y) {
  int xid = tid[val[x]];
  int yid = tid[val[y]];
  tree[xid].an = tree[xid].cid[0] = tree[xid].cid[1] = x;
  tree[yid].an = tree[yid].cid[0] = tree[yid].cid[1] = y;
  x = xid;
  y = yid;
  if (tdep[x] < tdep[y]) swap(x, y);
  while (tdep[x] > tdep[y]) {
    x >>= 1;
    pushUp(x);
  }
  while (true) {
    int fx = x >> 1;
    int fy = y >> 1;
    if (fx == fy) {
      break;
    }
    x = fx;
    y = fy;
    pushUp(x);
    pushUp(y);
  }
  while (x > 1) {
    x >>= 1;
    pushUp(x);
  }
}
const Node query(int L, int R, int l, int r, int id) {
  Node &rt = tree[id];
  if (L == l && r == R) {
    return rt;
  }
  int mid = (l + r) >> 1;
  if (R <= mid)
    return query(L, R, l, mid, id << 1);
  else if (L > mid)
    return query(L, R, mid + 1, r, id << 1 | 1);
  else {
    Node ret;
    merge(ret, query(L, mid, l, mid, id << 1),
          query(mid + 1, R, mid + 1, r, id << 1 | 1));
    return ret;
  }
}
int main() {
  init();
  scanf("%d", &n);
  for (int i = 1, v; i <= n; i++) {
    scanf("%d", &v);
    val[i] = v;
    nid[v] = i;
  }
  for (int i = 2, fa; i <= n; i++) {
    scanf("%d", &fa);
    child[fa].push_back(i);
  }
  initLCA();
  buildTree(0, n, 1);
  int q;
  scanf("%d", &q);
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x, y;
      scanf("%d%d", &x, &y);
      swap(val[x], val[y]);
      swap(nid[val[x]], nid[val[y]]);
      update(x, y);
    } else if (t == 2) {
      int l = 0, r = n;
      while (l < r) {
        int mid = (l + r) >> 1;
        Node ret = query(0, mid, 0, n, 1);
        if (ret.an >= 0) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
      printf("%d\n", l);
    }
  }
  return 0;
}
