#include <bits/stdc++.h>
namespace io {
const int size = 1 << 24;
char buf[size], puf[size], d[20], *p1, *p2, *p = puf;
template <class type>
void inline read(type& a) {
  int f = 1,
      c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, size, stdin), p1 == p2)
               ? EOF
               : *p1++);
  for (; !(c >= 48 && c <= 57);
       f = c == 45 ? -1 : 1,
       c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, size, stdin), p1 == p2)
                ? EOF
                : *p1++))
    ;
  for (a = 0; (c >= 48 && c <= 57); a *= 10, a += c ^ 48,
      c = (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, size, stdin), p1 == p2)
               ? EOF
               : *p1++))
    ;
  a *= f;
}
void inline write(bool s, char c = '\n') {
  s ? ((*p++ = 'Y',
        p - puf == size ? (fwrite(puf, 1, p - puf, stdout), p = puf) : 0),
       (*p++ = 'E',
        p - puf == size ? (fwrite(puf, 1, p - puf, stdout), p = puf) : 0),
       (*p++ = 'S',
        p - puf == size ? (fwrite(puf, 1, p - puf, stdout), p = puf) : 0))
    : ((*p++ = 'N',
        p - puf == size ? (fwrite(puf, 1, p - puf, stdout), p = puf) : 0),
       (*p++ = 'O',
        p - puf == size ? (fwrite(puf, 1, p - puf, stdout), p = puf) : 0));
  (*p++ = c, p - puf == size ? (fwrite(puf, 1, p - puf, stdout), p = puf) : 0);
}
};  // namespace io
using namespace io;
using namespace std;
const int nsz = 3e5, lgsz = 19;
int n, m, q, k, kk, b, pt[nsz + 5], pts[nsz + 5], id[nsz + 5], tim[nsz + 5],
    tmp[nsz + 5], ans;
int t, sc, dfn[nsz + 5], low[nsz + 5], vis[nsz + 5], sid[nsz + 5], ss,
    stk[nsz + 5];
int tc, dep[nsz + 5], pr[nsz + 5][lgsz + 5], tid[nsz + 5];
pair<int, int> e[nsz + 5];
struct edge {
  int nxt, to, id;
  edge(int nxt = 0, int to = 0, int id = 0) {
    this->nxt = nxt, this->to = to, this->id = id;
  }
};
struct graph {
  int es, hd[nsz + 5];
  edge e[8 * nsz + 5];
  void inline link(int u, int v) {
    int id = es + 1;
    e[++es] = edge(hd[u], v, id), hd[u] = es;
    e[++es] = edge(hd[v], u, id), hd[v] = es;
  }
  edge& operator[](int id) { return e[id]; }
};
graph dat, g;
void tarjan(int u, int id = 0) {
  dfn[u] = low[u] = (!id ? t = 1 : ++t);
  stk[ss++] = u;
  vis[u] = 1;
  for (int i = dat.hd[u]; i; i = dat[i].nxt) {
    int v = dat[i].to;
    if (dat[i].id == id || vis[v] == 2) continue;
    if (!vis[v]) {
      tarjan(v, dat[i].id);
    }
    low[u] = min(low[u], low[v]);
  }
  if (dfn[u] != low[u]) return;
  ++sc;
  for (; ss;) {
    int v = stk[--ss];
    sid[v] = sc;
    vis[v] = 2;
    if (u == v) break;
  }
}
void tarjan2(int u, int id = 0) {
  dfn[u] = low[u] = (!id ? t = 1 : ++t);
  stk[ss++] = u;
  vis[u] = 1;
  for (int i = g.hd[u]; i; i = g[i].nxt) {
    int v = g[i].to;
    if (g[i].id == id || vis[v] == 2) continue;
    if (!vis[v]) {
      tarjan2(v, g[i].id);
    }
    low[u] = min(low[u], low[v]);
  }
  if (dfn[u] != low[u]) return;
  ++sc;
  for (; ss;) {
    int v = stk[--ss];
    sid[v] = sc;
    vis[v] = 2;
    if (u == v) break;
  }
}
void dfs(int u, int p = 0) {
  tim[u] = ++t;
  tid[u] = tc;
  for (int k = 1; k <= lgsz; ++k) {
    int p = pr[u][k - 1];
    if (!p) break;
    pr[u][k] = pr[p][k - 1];
  }
  for (int i = g.hd[u]; i; i = g[i].nxt) {
    int v = g[i].to;
    if (v == p) continue;
    pr[v][0] = u;
    dep[v] = dep[u] + 1;
    dfs(v, u);
  }
}
int inline lca(int u, int v) {
  if (tid[u] != tid[v]) return 0;
  if (dep[u] > dep[v]) {
    swap(u, v);
  }
  for (int k = 0; k <= lgsz; ++k) {
    if (((dep[v] - dep[u]) >> k) & 1) {
      v = pr[v][k];
    }
  }
  if (u == v) return u;
  for (int k = lgsz; k >= 0; --k) {
    if (pr[u][k] != pr[v][k]) {
      u = pr[u][k], v = pr[v][k];
    }
  }
  return pr[u][0];
}
bool inline cmp(int u, int v) { return tim[u] < tim[v]; }
void inline build(int k, int pt[]) {
  int sz = 0;
  for (int i = 1; i <= k; ++i) {
    int u = pt[i];
    if (sz == 0) {
      g.hd[u] = 0;
      stk[sz++] = u;
      continue;
    }
    int p = stk[sz - 1], pp = lca(u, p);
    for (; sz > 1 && dep[stk[sz - 2]] >= dep[pp]; --sz) {
      g.link(stk[sz - 2], stk[sz - 1]);
    }
    p = stk[sz - 1];
    if (pp != p) {
      g.hd[pp] = vis[pp] = 0;
      stk[sz - 1] = pp;
      g.link(p, pp);
    }
    g.hd[u] = vis[u] = 0;
    stk[sz++] = u;
  }
  for (; sz > 1; --sz) {
    g.link(stk[sz - 1], stk[sz - 2]);
  }
}
void inline dbg(int k, int pt[]) {
  for (int i = 1; i <= k; ++i) {
    int u = pt[i];
    cerr << u << ": ";
    for (int i = g.hd[u]; i; i = g[i].nxt) {
      int v = g[i].to;
      cerr << v << ' ';
    }
    cerr << '\n';
  }
}
int inline to(int a) {
  a = (a + ans) % n;
  return !a ? n : a;
}
int main() {
  read(n), read(m), read(q);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    read(u), read(v);
    dat.link(u, v);
  }
  for (int u = 1; u <= n; ++u) {
    if (vis[u]) continue;
    tarjan(u);
  }
  for (int u = 1; u <= n; ++u) {
    id[u] = sid[u];
    for (int i = dat.hd[u]; i; i = dat[i].nxt) {
      int v = dat[i].to, su = sid[u], sv = sid[v];
      if (su >= sv) continue;
      g.link(su, sv);
    }
  }
  t = 0;
  for (int u = 1; u <= sc; ++u) {
    if (pr[u][0]) continue;
    ++tc;
    dfs(u);
  }
  memset(g.hd, 0, sizeof(g.hd));
  for (int cs = 1; cs <= q; ++cs) {
    read(k), read(b);
    kk = k;
    for (int i = 1; i <= k; ++i) {
      int u;
      read(u);
      u = to(u);
      pt[i] = id[u];
      pts[i] = id[u];
    }
    for (int i = 1; i <= b; ++i) {
      int u, v;
      read(u), read(v);
      u = to(u), v = to(v);
      u = id[u], v = id[v];
      e[i] = make_pair(u, v);
      pt[++k] = u;
      pt[++k] = v;
    }
    sort(pt + 1, pt + k + 1, cmp);
    k = unique(pt + 1, pt + k + 1) - (pt + 1);
    int sz = 0;
    pt[k + 1] = 0;
    for (int i = 1; i <= k; ++i) {
      tmp[++sz] = pt[i];
      if (tid[pt[i]] != tid[pt[i + 1]]) {
        build(sz, tmp);
        sz = 0;
      }
    }
    for (int i = 1; i <= b; ++i) {
      int u = e[i].first, v = e[i].second;
      if (u == v) continue;
      g.link(u, v);
    }
    for (int i = 1; i <= k; ++i) {
      int u = pt[i];
      dfn[u] = low[u] = vis[u] = sid[u] = 0;
    }
    ss = sc = 0;
    for (int i = 1; i <= k; ++i) {
      int u = pt[i];
      if (!vis[u]) {
        tarjan2(u);
      }
    }
    for (int i = 1; i <= kk; ++i) {
      int u = pts[i];
    }
    bool flag = 1;
    for (int i = 1; i <= kk - 1; ++i) {
      flag &= sid[pts[i]] == sid[pts[i + 1]];
    }
    write(flag);
    ans = (ans + flag * cs) % n;
  }
  (fwrite(puf, 1, p - puf, stdout), p = puf);
}
