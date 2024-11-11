#include <bits/stdc++.h>
using namespace std;
const double pi = acos(0.0) * 2.0;
const long double eps = 1e-10;
const int step[8][2] = {{-1, 0}, {0, 1}, {1, 0},  {0, -1},
                        {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
template <class T>
inline T abs1(T a) {
  return a < 0 ? -a : a;
}
template <typename t, typename t1>
t min1(t a, t1 b) {
  return a < b ? a : b;
}
template <typename t, typename... arg>
t min1(t a, arg... arr) {
  return min1(a, min1(arr...));
}
template <typename t, typename t1>
t max1(t a, t1 b) {
  return a > b ? a : b;
}
template <typename t, typename... arg>
t max1(t a, arg... arr) {
  return max1(a, max1(arr...));
}
inline int jud(double a, double b) {
  if (abs(a) < eps && abs(b) < eps)
    return 0;
  else if (abs1(a - b) / abs1(a) < eps)
    return 0;
  if (a < b) return -1;
  return 1;
}
template <typename t>
inline int jud(t a, t b) {
  if (a < b) return -1;
  if (a == b) return 0;
  return 1;
}
template <typename it, typename t1>
inline int find(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1) {
  int be = 0, en = na - 1;
  if (*a <= *(a + na - 1)) {
    if (f_lb == 0)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != 1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != -1)
          en = mid;
        else
          be = mid + 1;
      }
    if (f_small && jud(*(a + be), val) == 1) be--;
    if (!f_small && jud(*(a + be), val) == -1) be++;
  } else {
    if (f_lb)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != -1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != 1)
          en = mid;
        else
          be = mid + 1;
      }
    if (!f_small && jud(*(a + be), val) == -1) be--;
    if (f_small && jud(*(a + be), val) == 1) be++;
  }
  return be;
}
template <class T>
inline T lowb(T num) {
  return num & (-num);
}
inline int bitnum(unsigned int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(unsigned long long nValue) {
  return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32);
}
inline int bitnum(long long nValue) {
  return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32);
}
inline int bitmaxl(unsigned int a) {
  if (a == 0) return 0;
  return 32 - __builtin_clz(a);
}
inline int bitmaxl(int a) {
  if (a == 0) return 0;
  return 32 - __builtin_clz(a);
}
inline int bitmaxl(unsigned long long a) {
  int temp = a >> 32;
  if (temp) return 32 - __builtin_clz(temp) + 32;
  return bitmaxl(int(a));
}
inline int bitmaxl(long long a) {
  int temp = a >> 32;
  if (temp) return 32 - __builtin_clz(temp) + 32;
  return bitmaxl(int(a));
}
long long pow(long long n, long long m, long long mod = 0) {
  if (m < 0) return 0;
  long long ans = 1;
  long long k = n;
  while (m) {
    if (m & 1) {
      ans *= k;
      if (mod) ans %= mod;
    }
    k *= k;
    if (mod) k %= mod;
    m >>= 1;
  }
  return ans;
}
template <class t1, class t2>
inline void add(t1 &a, t2 b, int mod = -1) {
  if (mod == -1) mod = 1000000007;
  a += b;
  while (a >= mod) a -= mod;
  while (a < 0) a += mod;
}
template <class t>
void output1(t arr) {
  for (int i = 0; i < (int)arr.size(); i++) cerr << arr[i] << ' ';
  cerr << endl;
}
template <class t>
void output2(t arr) {
  for (int i = 0; i < (int)arr.size(); i++) output1(arr[i]);
}
const int maxn = 100100;
struct edge {
  int to, nxt, val;
} e[maxn * 2];
int head[maxn], le;
int fa[maxn], anc[maxn], sz[maxn], hv[maxn], deep[maxn], loc[maxn];
int orig[maxn], lorig;
int n, nq;
int f[maxn];
pair<int, int> st[2][maxn];
int lst[2];
int ans[maxn];
struct node {
  int a, b, cate;
  int yul;
  bool operator<(const node &a) const {
    if (yul == a.yul) return cate < a.cate;
    return yul < a.yul;
  }
} arr[maxn * 2];
int larr;
struct segment_node {
  int be, en;
  int sumv, lef, rig;
  bool flag;
};
struct segment_tree {
  int l;
  segment_node tree[maxn * 4];
  inline int gleft(int no) { return no << 1; }
  inline int gright(int no) { return (no << 1) + 1; }
  inline int gfa(int no) { return no >> 1; }
  inline segment_tree() { l = 0; }
  void build(int no, int l, int r, int orig = 0, int *a = NULL) {
    if (l > r) r = l;
    if (l == r) {
      tree[no].be = tree[no].en = l;
      tree[no].sumv = 0;
      tree[no].lef = tree[no].rig = 0;
      tree[no].flag = 0;
      return;
    }
    tree[no].be = l;
    tree[no].en = r;
    int mid = (l + r) / 2;
    build(gleft(no), l, mid, orig, a);
    build(gright(no), mid + 1, r, orig, a);
    tree[no].sumv = 0;
    tree[no].lef = tree[no].rig = 0;
  }
  inline void pushup(segment_node *no, segment_node *nl, segment_node *nr) {
    if (nl->flag && nr->flag) {
      no->lef = no->rig = nr->lef + nl->rig;
      no->sumv = 0;
      no->flag = 1;
      return;
    }
    if (nl->flag && nl->lef == 0) {
      memcpy(no, nr, sizeof(segment_node));
      return;
    }
    if (nr->flag && nr->lef == 0) {
      memcpy(no, nl, sizeof(segment_node));
      return;
    }
    no->flag = 0;
    if (nl->flag) {
      no->lef = nr->lef + nl->rig;
      no->rig = nr->rig;
      no->sumv = nr->sumv;
      return;
    }
    if (nr->flag) {
      no->lef = nl->lef;
      no->rig = nl->rig + nr->lef;
      no->sumv = nl->sumv;
      return;
    }
    no->lef = nl->lef;
    no->rig = nr->rig;
    no->sumv = nl->sumv + nr->sumv + f[nl->rig + nr->lef];
  }
  void down(int loc, int no) {
    if (loc <= tree[no].be && loc >= tree[no].en) {
      tree[no].rig = tree[no].lef = 1;
      tree[no].flag = 1;
      tree[no].sumv = 0;
      return;
    }
    int mid = (tree[no].be + tree[no].en) >> 1;
    if (loc <= mid)
      down(loc, gleft(no));
    else
      down(loc, gright(no));
    pushup(tree + no, tree + gleft(no), tree + gright(no));
  }
  void getsum(int l, int r, int no, int pp1) {
    if (l > r) return;
    int pp2 = pp1 + 100;
    if (l <= tree[no].be && r >= tree[no].en) {
      pushup(tree + pp2, tree + pp1, tree + no);
      tree[pp1] = tree[pp2];
      return;
    }
    int mid = (tree[no].be + tree[no].en) >> 1;
    if (r >= tree[no].be && l <= mid) getsum(l, r, gleft(no), pp1);
    if (r >= mid + 1 && l <= tree[no].en) getsum(l, r, gright(no), pp1);
  }
} sgt;
void dfs(int no) {
  sz[no] = 1;
  hv[no] = -1;
  for (int i = head[no]; i != -1; i = e[i].nxt)
    if (e[i].to != fa[no]) {
      fa[e[i].to] = no;
      deep[e[i].to] = deep[no] + 1;
      dfs(e[i].to);
      sz[no] += sz[e[i].to];
      if (hv[no] == -1 || sz[hv[no]] < sz[e[i].to]) hv[no] = e[i].to;
    }
}
void dfs1(int no) {
  orig[lorig] = no;
  loc[no] = lorig++;
  if (hv[no] != -1) {
    anc[hv[no]] = anc[no];
    dfs1(hv[no]);
  }
  for (int i = head[no]; i != -1; i = e[i].nxt)
    if (e[i].to != fa[no] && e[i].to != hv[no]) {
      anc[e[i].to] = e[i].to;
      dfs1(e[i].to);
    }
}
void addedge(int a, int b, int c) {
  e[le].to = b;
  e[le].nxt = head[a];
  e[le].val = c;
  head[a] = le++;
}
int main() {
  ios_base::sync_with_stdio(0);
  memset(head, -1, sizeof(head));
  scanf("%d%d", &n, &nq);
  for (int i = 1; i < n; i++) scanf("%d", f + i);
  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    a--;
    b--;
    addedge(a, b, c);
    addedge(b, a, c);
    arr[i].a = a;
    arr[i].b = b;
    arr[i].yul = -c;
    arr[i].cate = -(i + 1);
  }
  sgt.build(1, 0, n);
  dfs(0);
  dfs1(0);
  for (int i = 0; i < nq; i++) {
    scanf("%d%d%d", &arr[i + n - 1].a, &arr[i + n - 1].b, &arr[i + n - 1].yul);
    arr[i + n - 1].cate = i;
    arr[i + n - 1].a--;
    arr[i + n - 1].b--;
    arr[i + n - 1].yul = -arr[i + n - 1].yul;
  }
  sort(arr, arr + nq + n - 1);
  for (int i = 0; i < nq + n - 1; i++) {
    if (arr[i].cate < 0) {
      int no = arr[i].a;
      if (deep[arr[i].b] > deep[no]) no = arr[i].b;
      sgt.down(loc[no], 1);
    } else {
      int a = arr[i].a, b = arr[i].b;
      int l = 0;
      lst[0] = lst[1] = 0;
      while (anc[a] != anc[b]) {
        int no = a, cate = 0;
        if (deep[anc[a]] < deep[anc[b]]) {
          no = b;
          cate = 1;
        }
        st[cate][lst[cate]++] = make_pair(loc[anc[no]], loc[no]);
        l += abs(loc[anc[no]] - loc[no]) + 1;
        if (deep[anc[a]] < deep[anc[b]])
          b = fa[anc[no]];
        else
          a = fa[anc[no]];
      }
      if (a != b) {
        if (deep[a] > deep[b])
          st[0][lst[0]++] = make_pair(loc[b] + 1, loc[a]);
        else
          st[1][lst[1]++] = make_pair(loc[a] + 1, loc[b]);
        l += abs(deep[a] - deep[b]);
      }
      int ff1 = 400000, ff2 = ff1 + 1, ff3 = ff1 + 2;
      sgt.tree[ff1].rig = sgt.tree[ff1].lef = sgt.tree[ff1].sumv = 0;
      sgt.tree[ff1].flag = 1;
      sgt.tree[ff2].rig = sgt.tree[ff2].lef = sgt.tree[ff2].sumv = 0;
      sgt.tree[ff2].flag = 1;
      for (int i = lst[0] - 1; i >= 0; i--)
        sgt.getsum(st[0][i].first, st[0][i].second, 1, ff1);
      for (int i = lst[1] - 1; i >= 0; i--)
        sgt.getsum(st[1][i].first, st[1][i].second, 1, ff2);
      swap(sgt.tree[ff1].lef, sgt.tree[ff1].rig);
      sgt.pushup(sgt.tree + ff3, sgt.tree + ff1, sgt.tree + ff2);
      int rans = sgt.tree[ff3].sumv + f[sgt.tree[ff3].lef];
      if (!sgt.tree[ff3].flag) rans += f[sgt.tree[ff3].rig];
      ans[arr[i].cate] = rans;
    }
  }
  for (int i = 0; i < nq; i++) printf("%d\n", ans[i]);
  return 0;
}
