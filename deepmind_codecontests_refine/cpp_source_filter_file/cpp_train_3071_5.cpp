#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast,no-stack-protector")
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "\n";
  err(++it, args...);
}
function<void(void)> ____ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
};
template <typename T>
vector<T> &operator<<(vector<T> &__container, T x) {
  __container.push_back(x);
  return __container;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> &__container) {
  for (T _ : __container) out << _ << ' ';
  return out;
}
void sci() {}
template <typename... Args>
void sci(int &x, Args &...args) {
  scanf("%d", &x);
  sci(args...);
}
void scl() {}
template <typename... Args>
void scl(long long int &x, Args &...args) {
  scanf("%lld", &x);
  scl(args...);
}
const int MAXN = 1e6 + 7;
int n, m;
struct SegmentTree {
  int w[MAXN << 2], l[MAXN << 2], r[MAXN << 2];
  void build(int L, int R, int rt = 1) {
    l[rt] = L;
    r[rt] = R;
    w[rt] = 0;
    if (L + 1 == R) return;
    int mid = (L + R) >> 1;
    build(L, mid, rt << 1);
    build(mid, R, rt << 1 | 1);
  }
  void down(int rt) {
    if (w[rt]) w[rt << 1] = w[rt << 1 | 1] = w[rt], w[rt] = 0;
  }
  void modify(int L, int R, int x, int rt = 1) {
    if (L >= r[rt] or l[rt] >= R) return;
    if (L <= l[rt] and r[rt] <= R) {
      w[rt] = x;
      return;
    }
    down(x);
    modify(L, R, x, rt << 1);
    modify(L, R, x, rt << 1 | 1);
  }
  int query(int pos, int rt = 1) {
    if (l[rt] + 1 == r[rt]) return w[rt];
    down(rt);
    int mid = (l[rt] + r[rt]) >> 1;
    if (pos < mid)
      return query(pos, rt << 1);
    else
      return query(pos, rt << 1 | 1);
  }
} seg;
struct FenwickTree {
  long long int sum[MAXN];
  void modify(int pos, int x) {
    while (pos < MAXN) sum[pos] += x, pos += (pos & (-pos));
  }
  long long int qsum(int pos) {
    long long int ret = 0;
    while (pos) ret += sum[pos], pos -= (pos & (-pos));
    return ret;
  }
} bit;
struct Query {
  int op;
  int x, y, time, qid;
} Q[MAXN];
struct Disjoint_Set_Union {
  int fa[MAXN];
  Disjoint_Set_Union() {
    for (int i = 0; i < MAXN; i++) fa[i] = i;
  }
  int findx(int x) { return x == fa[x] ? x : fa[x] = findx(fa[x]); }
  void merge(int x, int y) {
    if (findx(x) != findx(y)) fa[findx(x)] = findx(y);
  }
} dsu[2];
struct Graph {
  vector<int> g[MAXN];
  int tot, dfn[MAXN], idx, sz[MAXN], ed[MAXN];
  vector<int> &operator[](int ID) { return g[ID]; }
  void dfs(int u) {
    dfn[u] = ++idx;
    sz[u] = u <= n ? 1 : 0;
    for (int v : g[u]) dfs(v), sz[u] += sz[v];
    ed[u] = idx;
  }
} G[2];
long long int ret[MAXN];
int exc(char ch) {
  if (ch == 'U') return 1;
  if (ch == 'M') return 2;
  if (ch == 'A') return 3;
  if (ch == 'Z') return 4;
  if (ch == 'Q') return 5;
}
void solve() {
  static char buf[233];
  sci(n, m);
  G[0].tot = G[1].tot = n;
  G[0].idx = G[1].idx = 0;
  for (int i = 0; i <= (n << 1); i++) dsu[0].fa[i] = dsu[1].fa[i] = i;
  for (int i = 0; i <= (n << 1); i++) G[0][i].clear(), G[1][i].clear();
  for (int i = 0; i <= (n << 1); i++) bit.sum[i] = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%s", buf);
    Q[i].op = exc(buf[0]);
    assert(Q[i].op >= 1 and Q[i].op <= 5);
    Q[i].time = i;
    if (Q[i].op == 1) {
      scanf("%d %d", &Q[i].x, &Q[i].y);
      G[1].tot++;
      G[1][G[1].tot].push_back(dsu[1].findx(Q[i].x));
      G[1][G[1].tot].push_back(dsu[1].findx(Q[i].y));
      dsu[1].merge(Q[i].x, G[1].tot);
      dsu[1].merge(Q[i].y, G[1].tot);
    } else if (Q[i].op == 2) {
      scanf("%d %d", &Q[i].x, &Q[i].y);
      G[0].tot++;
      G[0][G[0].tot].push_back(dsu[0].findx(Q[i].x));
      G[0][G[0].tot].push_back(dsu[0].findx(Q[i].y));
      dsu[0].merge(Q[i].x, G[0].tot);
      dsu[0].merge(Q[i].y, G[0].tot);
    } else if (Q[i].op == 3) {
      scanf("%d", &Q[i].x);
      Q[i].x = dsu[0].findx(Q[i].x);
    } else if (Q[i].op == 4) {
      scanf("%d", &Q[i].x);
      Q[i].x = dsu[1].findx(Q[i].x);
    } else
      scanf("%d", &Q[i].x);
  }
  G[0].tot++;
  G[1].tot++;
  for (int i = 1; i < G[0].tot; i++)
    if (dsu[0].findx(i) == i) G[0].g[G[0].tot] << i;
  for (int i = 1; i < G[1].tot; i++)
    if (dsu[1].findx(i) == i) G[1].g[G[1].tot] << i;
  G[0].dfs(G[0].tot);
  G[1].dfs(G[1].tot);
  vector<Query> vec;
  seg.build(1, MAXN);
  int queryid = 0;
  for (int i = 1; i <= m; i++) {
    if (Q[i].op == 3)
      vec << Q[i];
    else if (Q[i].op == 4) {
      int st = G[0].dfn[Q[i].x], ed = G[0].ed[Q[i].x];
      seg.modify(st, ed + 1, i);
    } else if (Q[i].op == 5) {
      Q[i].y = 1;
      Q[i].qid = ++queryid;
      vec << Q[i];
      int p = seg.query(G[0].dfn[Q[i].x]);
      if (p != 0) {
        Q[i].y = -1;
        Q[i].time = p;
        vec << Q[i];
      }
    }
  }
  sort(vec.begin(), vec.end(),
       [&](const Query &A, const Query &B) { return A.time < B.time; });
  for (Query &qs : vec) {
    if (qs.op == 3) {
      int sz = G[1].sz[qs.x], st = G[1].dfn[qs.x], ed = G[1].ed[qs.x];
      bit.modify(st, sz);
      bit.modify(ed + 1, -sz);
    } else if (qs.op == 5)
      ret[qs.qid] += qs.y * bit.qsum(G[1].dfn[qs.x]);
  }
  for (int i = 1; i <= queryid; i++) cout << ret[i] << "\n";
}
int main() {
  solve();
  return 0;
}
