#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 100007;
const int MAXL = 21;
const int MAXS = MAXN * 4;
const int MAX = 131072;
int n, m;
class hldT {
 public:
  hldT() { memset(la, -1, sizeof(la)); }
  void addedge(int u, int v) {
    edge[ke].setd(u, v, la[u]);
    la[u] = ke++;
    edge[ke].setd(v, u, la[v]);
    la[v] = ke++;
  }
  void build() {
    dfs(1, -1);
    memset(cid, -1, sizeof(cid));
    cs = cy.size();
    for (int i = 0; i < cs; ++i) cid[cy[i]] = i;
    int tk = ke;
    ke = 0;
    memset(la, -1, sizeof(la));
    int u, v;
    for (int i = 0; i < tk; i += 2) {
      u = edge[i].u, v = edge[i].v;
      if (cid[u] == -1 && cid[v] == -1)
        addedge(u, v);
      else if (cid[u] == -1)
        addedge(n + 1, u), lf[u] = v;
      else if (cid[v] == -1)
        addedge(n + 1, v), lf[v] = u;
    }
    dfs1(n + 1, -1, 1);
    dfs2(n + 1, -1, n + 1);
    memset(lca, -1, sizeof(lca));
    for (int i = 1; i <= n; ++i) lca[i][0] = fa[i];
    for (int j = 1; j < MAXL; ++j)
      for (int i = 1; i <= n; ++i)
        if (~lca[i][j - 1]) lca[i][j] = lca[lca[i][j - 1]][j - 1];
  }
  void flip(int u, int v) {
    int ru, rv;
    if (cid[u] == -1 && cid[v] == -1) {
      int nl = getlca(u, v);
      if (nl ^ (n + 1)) {
        _flip(u, v);
        return;
      }
    }
    if (cid[u] == -1) {
      _flip(u, n + 1);
      ru = cid[lf[goup(u, lev[u] - 2)]];
    } else
      ru = cid[u];
    if (cid[v] == -1) {
      _flip(v, n + 1);
      rv = cid[lf[goup(v, lev[v] - 2)]];
    } else
      rv = cid[v];
    if (ru == rv) return;
    bool sp = false;
    if (ru > rv) swap(ru, rv), sp = true;
    int d1 = rv - ru, d2 = cs - d1;
    if (d1 < d2 ||
        (d1 == d2 && ((!sp && cy[(ru + 1) % cs] < cy[(ru - 1 + cs) % cs]) ||
                      (sp && cy[(rv - 1 + cs) % cs] < cy[(rv + 1) % cs])))) {
      ++ru, ++rv;
      cyc.flip(ru + 1, rv);
    } else {
      ++ru, ++rv;
      cyc.flip(1, ru);
      cyc.flip(rv + 1, cs);
    }
  }
  int query() {
    int t = cyc.query(1, MAX);
    return n - st.query(1, MAX) - (((t) < (cs - 1)) ? (t) : (cs - 1));
  }

 private:
  bool dfs(int now, int nf) {
    if (ins[now]) {
      int t = nt;
      while (stk[t] ^ now) cy.push_back(stk[--t]);
      return true;
    }
    stk[nt++] = now;
    ins[now] = true;
    for (int i = la[now]; ~i; i = edge[i].last) {
      if (edge[i].v ^ nf && dfs(edge[i].v, now)) return true;
    }
    --nt;
    ins[now] = false;
    return false;
  }
  int dfs1(int now, int nf, int nl) {
    fa[now] = nf;
    lev[now] = nl;
    size[now] = 1;
    int maxi = -1, mp = -1, ret;
    for (int i = la[now]; ~i; i = edge[i].last) {
      if (edge[i].v ^ nf) {
        ret = dfs1(edge[i].v, now, nl + 1);
        size[now] += ret;
        if (ret > maxi) maxi = ret, mp = edge[i].v;
      }
    }
    ch[now] = mp;
    return size[now];
  }
  void dfs2(int now, int nf, int nt) {
    id[now] = ++kd;
    top[now] = nt;
    if (~ch[now]) dfs2(ch[now], now, nt);
    for (int i = la[now]; ~i; i = edge[i].last) {
      if (edge[i].v ^ nf && edge[i].v ^ ch[now]) {
        dfs2(edge[i].v, now, edge[i].v);
      }
    }
  }
  int getdist(int u, int v) { return lev[u] + lev[v] - 2 * lev[getlca(u, v)]; }
  void _flip(int u, int v) {
    int tu = top[u], tv = top[v];
    while (tu ^ tv) {
      if (lev[tu] < lev[tv]) swap(tu, tv), swap(u, v);
      st.flip(id[tu], id[u]);
      u = fa[tu], tu = top[u];
    }
    if (lev[u] > lev[v]) swap(u, v);
    if (u ^ v) st.flip(id[u] + 1, id[v]);
  }
  int query(int u, int v) {
    int tu = top[u], tv = top[v], ans = 0;
    while (tu ^ tv) {
      if (lev[tu] < lev[tv]) swap(tu, tv), swap(u, v);
      ans += st.query(id[tu], id[u]);
      u = fa[tu], tu = top[u];
    }
    if (lev[u] > lev[v]) swap(u, v);
    if (u ^ v) ans += st.query(id[u] + 1, id[v]);
    return ans;
  }
  int getlca(int u, int v) {
    if (lev[u] < lev[v]) swap(u, v);
    u = goup(u, lev[u] - lev[v]);
    if (u == v) return u;
    for (int i = MAXL - 1; i >= 0; --i) {
      if (lca[u][i] ^ lca[v][i]) u = lca[u][i], v = lca[v][i];
    }
    return fa[u];
  }
  int goup(int now, int nl) {
    int b = 0;
    while (nl) {
      if (nl & 1) now = lca[now][b];
      nl >>= 1;
      ++b;
    }
    return now;
  }
  int kd, cs;
  int fa[MAXN], lev[MAXN], top[MAXN], ch[MAXN], size[MAXN], id[MAXN],
      lca[MAXN][MAXL];
  int lf[MAXN];
  vector<int> cy;
  int cid[MAXN];
  int nt, stk[MAXN];
  bool ins[MAXN];
  struct eT {
    void setd(int _u, int _v, int _l) { u = _u, v = _v, last = _l; }
    int u, v, last;
  } edge[MAXN * 2];
  int ke, la[MAXN];
  class stT {
   public:
    void flip(int l, int r, int now = 1, int ll = 1, int rr = MAX) {
      if (ll >= l && rr <= r)
        tag[now] ^= 1, data[now] = rr - ll + 1 - data[now];
      else if (ll > r || rr < l)
        return;
      else {
        int mid = (ll + rr) >> 1;
        downtag(now, (rr - ll + 1) >> 1);
        flip(l, r, now << 1, ll, mid);
        flip(l, r, now << 1 | 1, mid + 1, rr);
        data[now] = data[now << 1] + data[now << 1 | 1];
      }
    }
    int query(int l, int r, int now = 1, int ll = 1, int rr = MAX) {
      if (ll >= l && rr <= r)
        return data[now];
      else if (ll > r || rr < l)
        return 0;
      else {
        int mid = (ll + rr) >> 1;
        downtag(now, (rr - ll + 1) >> 1);
        return query(l, r, now << 1, ll, mid) +
               query(l, r, now << 1 | 1, mid + 1, rr);
      }
    }

   private:
    void downtag(int now, int ns) {
      if (tag[now]) {
        data[now << 1] = ns - data[now << 1];
        data[now << 1 | 1] = ns - data[now << 1 | 1];
        tag[now << 1] ^= 1, tag[now << 1 | 1] ^= 1;
        tag[now] = false;
      }
    }
    int data[MAXS];
    bool tag[MAXS];
  } st, cyc;
} hld;
int u, v;
void init();
void input();
void inputq();
void work();
int main() {
  init();
  input();
  work();
}
void init() { ios::sync_with_stdio(false); }
void input() {
  scanf("%d%d", &n, &m);
  int u, v;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &u, &v);
    hld.addedge(u, v);
  }
}
void inputq() { scanf("%d%d", &u, &v); }
void work() {
  hld.build();
  for (int i = 0; i < m; ++i) {
    inputq();
    hld.flip(u, v);
    printf("%d\n", hld.query());
  }
}
