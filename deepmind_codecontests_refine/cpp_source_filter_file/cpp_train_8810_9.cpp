#include <bits/stdc++.h>
using namespace std;
int64_t read() {
  bool b = 0;
  int64_t n = 0;
  char c = getchar();
  for (; !(('0') <= (c) && (c) <= ('9')); c = getchar()) b = (c == '-');
  for (; (('0') <= (c) && (c) <= ('9')); c = getchar()) n = 10 * n + (c - '0');
  if (b) n = -n;
  return n;
}
const int64_t N = 1e5 + 10;
int64_t _log[2 * N], ss[2 * N][20], bl[N][20];
vector<int64_t> adj[N];
int64_t h[N], first[N];
vector<int64_t> et;
int64_t V[N];
int64_t n, q;
int64_t tin[N], tout[N], t = -1;
int64_t stlen, sth;
int64_t lp[N];
int64_t st[2 * N];
void calc(int64_t i, int64_t k) {
  st[i] = st[i << 1] + st[i << 1 | 1] + lp[i] * k;
}
void app(int64_t i, int64_t vv, int64_t k) {
  st[i] += vv * k;
  if (i < stlen) lp[i] += vv;
}
void build(int64_t l, int64_t r) {
  int64_t k = 2;
  for (l += stlen, r += stlen - 1; l > 1; k <<= 1) {
    l >>= 1, r >>= 1;
    for (int64_t i = r; i >= l; --i) calc(i, k);
  }
}
void push(int64_t l, int64_t r) {
  int64_t s = sth, k = 1 << (sth - 1);
  for (l += stlen, r += stlen - 1; s > 0; --s, k >>= 1)
    for (int64_t i = l >> s; i <= r >> s; ++i)
      if (lp[i] != 0) {
        app(i << 1, lp[i], k);
        app(i << 1 | 1, lp[i], k);
        lp[i] = 0;
      }
}
void add(int64_t l, int64_t r, int64_t vv) {
  push(l, l + 1), push(r - 1, r);
  int64_t l0 = l, r0 = r, k = 1;
  for (l += stlen, r += stlen; l < r; l >>= 1, r >>= 1, k <<= 1) {
    if (l & 1) app(l++, vv, k);
    if (r & 1) app(--r, vv, k);
  }
  build(l0, l0 + 1), build(r0 - 1, r0);
}
int64_t query(int64_t l, int64_t r) {
  int64_t l0 = l, r0 = r;
  push(l, l + 1), push(r - 1, r);
  int64_t res = 0;
  for (l += stlen, r += stlen; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res += st[l++];
    if (r & 1) res += st[--r];
  }
  l = l0, r = r0;
  return res;
}
void _clog() {
  for (int64_t i = 2; i < 2 * N; ++i) _log[i] = _log[i >> 1] + 1;
}
void clca() {
  int64_t n = et.size();
  for (int64_t i = 0; (i) < (n); ++(i)) ss[i][0] = et[i];
  for (int64_t k = 1; (1 << k) <= n; ++k)
    for (int64_t i = 0; i + (1 << k) <= n; ++i) {
      int64_t j = i + (1 << (k - 1));
      if (h[ss[i][k - 1]] < h[ss[j][k - 1]])
        ss[i][k] = ss[i][k - 1];
      else
        ss[i][k] = ss[j][k - 1];
    }
}
int64_t lca(int64_t l, int64_t r) {
  l = first[l], r = first[r];
  if (r < l) swap(l, r);
  int64_t k = _log[r - l + 1];
  int64_t a = ss[l][k], b = ss[r - (1 << k) + 1][k];
  if (h[a] < h[b])
    return a;
  else
    return b;
}
void pdfs(int64_t v, int64_t p) {
  first[v] = int64_t((et).size());
  tin[v] = ++t;
  et.push_back(v);
  bl[v][0] = p;
  for (int64_t i = 0; (i) < (19); ++(i)) bl[v][i + 1] = bl[bl[v][i]][i];
  for (int64_t c : adj[v]) {
    if (c == p) continue;
    h[c] = h[v] + 1;
    pdfs(c, v);
    et.push_back(v);
  }
  tout[v] = t;
}
int64_t rlca(int64_t root, int64_t l, int64_t r) {
  return lca(l, root) ^ lca(r, root) ^ lca(l, r);
}
int64_t up(int64_t v, int64_t first) {
  for (int64_t i = 19; first && i >= 0; --i)
    if ((1 << i) <= first) v = bl[v][i], first -= (1 << i);
  return v;
}
int64_t qsub(int64_t v) { return query(tin[v], tout[v] + 1); }
void msub(int64_t v, int64_t vv) { add(tin[v], tout[v] + 1, vv); }
int main() {
  ;
  n = read(), q = read(), stlen = n;
  sth = 8 * sizeof(int) - __builtin_clz(stlen);
  ;
  for (int64_t i = 0; (i) < (n); ++(i)) V[i] = read();
  int64_t a, b;
  for (int64_t i = 0; (i) < (n - 1); ++(i)) {
    a = read() - 1, b = read() - 1;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  _log[1] = 0;
  _clog();
  pdfs(0, 0);
  clca();
  ;
  for (int64_t i = 0; (i) < (n); ++(i))
    ;
  ;
  ;
  ;
  for (int64_t i = 0; (i) < (n); ++(i))
    ;
  ;
  ;
  for (int64_t i = 0; (i) < (n); ++(i)) st[stlen + tin[i]] = V[i];
  build(0, n);
  int64_t op, root = 0;
  while (q--) {
    op = read();
    if (op == 1) {
      root = read() - 1;
    } else if (op == 2) {
      int64_t v = rlca(root, read() - 1, read() - 1);
      int64_t vv = read();
      if (root == v) {
        msub(0, vv);
      } else if (lca(v, root) == v) {
        ;
        msub(0, vv), msub(up(root, h[root] - h[v] - 1), -vv);
      } else {
        msub(v, vv);
      }
    } else {
      int64_t v = read() - 1;
      ;
      assert(op == 3);
      if (root == v) {
        printf("%ld\n", qsub(0));
      } else if (lca(v, root) == v) {
        ;
        ;
        printf("%ld\n", qsub(0) - qsub(up(root, h[root] - h[v] - 1)));
      } else {
        printf("%ld\n", qsub(v));
      }
    };
    for (int64_t i = 0; (i) < (n); ++(i))
      ;
    ;
    ;
  }
  return 0;
}
