#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxm = 5e3 + 10;
const int inf = 0x3f3f3f3f;
namespace io {
const int SIZE = (1 << 21) + 1;
char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c,
                                       qu[55];
int f, qr;
inline void flush() {
  fwrite(obuf, 1, oS - obuf, stdout);
  oS = obuf;
}
inline void putc(char x) {
  *oS++ = x;
  if (oS == oT) flush();
}
template <typename A>
inline bool read(A &x) {
  for (f = 1, c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                              (iS == iT ? EOF : *iS++))
                            : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    if (c == '-')
      f = -1;
    else if (c == EOF)
      return 0;
  for (x = 0; c <= '9' && c >= '0';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    x = x * 10 + (c & 15);
  x *= f;
  return 1;
}
inline bool read(char &x) {
  while ((x = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                           (iS == iT ? EOF : *iS++))
                        : *iS++)) == ' ' ||
         x == '\n' || x == '\r')
    ;
  return x != EOF;
}
inline bool read(char *x) {
  while ((*x = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                            (iS == iT ? EOF : *iS++))
                         : *iS++)) == '\n' ||
         *x == ' ' || *x == '\r')
    ;
  if (*x == EOF) return 0;
  while (!(*x == '\n' || *x == ' ' || *x == '\r' || *x == EOF))
    *(++x) = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                          (iS == iT ? EOF : *iS++))
                       : *iS++);
  *x = 0;
  return 1;
}
template <typename A, typename... B>
inline bool read(A &x, B &...y) {
  return read(x) && read(y...);
}
template <typename A>
inline bool write(A x) {
  if (!x) putc('0');
  if (x < 0) putc('-'), x = -x;
  while (x) qu[++qr] = x % 10 + '0', x /= 10;
  while (qr) putc(qu[qr--]);
  return 0;
}
inline bool write(char x) {
  putc(x);
  return 0;
}
inline bool write(const char *x) {
  while (*x) {
    putc(*x);
    ++x;
  }
  return 0;
}
inline bool write(char *x) {
  while (*x) {
    putc(*x);
    ++x;
  }
  return 0;
}
template <typename A, typename... B>
inline bool write(A x, B... y) {
  return write(x) || write(y...);
}
struct Flusher_ {
  ~Flusher_() { flush(); }
} io_flusher_;
}  // namespace io
using io ::putc;
using io ::read;
using io ::write;
vector<int> eee[maxm];
int s, t, dis[maxm], h[maxm], fnasiofnoas[maxm], pree[maxm], num[maxm];
struct edge {
  int u, v, c, w, rev;
  edge(int a = -1, int b = 0, int cc = 0, int d = 0, int f = 0)
      : rev(a), u(b), v(cc), c(d), w(f) {}
};
vector<edge> ed[maxm];
void addedge(int u, int v, int c, int w) {
  ed[u].push_back(edge((int)ed[v].size(), u, v, c, w));
  ed[v].push_back(edge((int)ed[u].size() - 1, v, u, 0, -w));
}
struct node {
  int id, val;
  node(int a = 0, int b = 0) : id(a), val(b) {}
  friend bool operator<(node e1, node e2) { return e1.val > e2.val; }
};
priority_queue<node> pq;
int costflow() {
  int res = 0;
  memset(h, 0, sizeof(h));
  int tot = inf;
  while (tot > 0) {
    memset(dis, 0x3f, sizeof(dis));
    while (!pq.empty()) pq.pop();
    dis[s] = 0;
    pq.push(node(s, 0));
    while (!pq.empty()) {
      node now = pq.top();
      pq.pop();
      int u = now.id;
      if (dis[u] < now.val) continue;
      int len = (int)ed[u].size();
      for (int i = 0; i < len; i++) {
        int v = ed[u][i].v;
        int f = ed[u][i].c;
        int w = ed[u][i].w;
        if (ed[u][i].c && dis[v] > dis[u] + w + h[u] - h[v]) {
          dis[v] = dis[u] + w + h[u] - h[v];
          fnasiofnoas[v] = u;
          pree[v] = i;
          pq.push(node(v, dis[v]));
        }
      }
    }
    if (dis[t] == inf) break;
    for (int i = 0; i <= t; i++) h[i] += dis[i];
    int flow = inf;
    for (int i = t; i; i = fnasiofnoas[i])
      flow = min(flow, ed[fnasiofnoas[i]][pree[i]].c);
    tot -= flow;
    res += flow * h[t];
    for (int i = t; i; i = fnasiofnoas[i]) {
      edge &e = ed[fnasiofnoas[i]][pree[i]];
      e.c -= flow;
      ed[e.v][e.rev].c += flow;
    }
  }
  return res;
}
int main() {
  int n, m, k, c, d;
  read(n, m, k, c, d);
  for (int i = 1; i <= k; i++) {
    int x;
    read(x);
    num[x]++;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    read(u, v);
    eee[u].push_back(v);
    eee[v].push_back(u);
  }
  s = 0, t = n * 100 + 1;
  for (int i = 1; i <= n; i++) addedge(s, i, num[i], 0);
  for (int i = 1; i <= 99; i++) {
    int N = (i - 1) * n;
    for (int j = 1; j <= n; j++) {
      for (int v : eee[j]) {
        for (int z = 1; z <= n; z++) {
          addedge(j + N, v + N + n, 1, (2 * z - 1) * d + c);
        }
      }
      addedge(j + N, j + N + n, inf, c);
    }
    addedge(N + 1, t, inf, 0);
  }
  addedge(99 * n + 1, t, inf, 0);
  printf("%d\n", costflow());
  return 0;
}
