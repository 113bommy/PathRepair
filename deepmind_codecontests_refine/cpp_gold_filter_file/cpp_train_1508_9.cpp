#include <bits/stdc++.h>
using namespace std;
void getre() {
  int x = 0;
  printf("%d\n", 1 / x);
}
void gettle() {
  int res = 1;
  while (1) res <<= 1;
  printf("%d\n", res);
}
template <typename T, typename S>
inline bool upmin(T &a, const S &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T, typename S>
inline bool upmax(T &a, const S &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename N, typename PN>
inline N flo(N a, PN b) {
  return a >= 0 ? a / b : -((-a - 1) / b) - 1;
}
template <typename N, typename PN>
inline N cei(N a, PN b) {
  return a > 0 ? (a - 1) / b + 1 : -(-a / b);
}
template <typename N>
N gcd(N a, N b) {
  return b ? gcd(b, a % b) : a;
}
template <typename N>
inline int sgn(N a) {
  return a > 0 ? 1 : (a < 0 ? -1 : 0);
}
inline void gn(long long &x) {
  int sg = 1;
  char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  c == '-' ? (sg = -1, x = 0) : (x = c - '0');
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= sg;
}
inline void gn(int &x) {
  long long t;
  gn(t);
  x = t;
}
inline void gn(unsigned long long &x) {
  long long t;
  gn(t);
  x = t;
}
inline void gn(double &x) {
  double t;
  scanf("%lf", &t);
  x = t;
}
inline void gn(long double &x) {
  double t;
  scanf("%lf", &t);
  x = t;
}
inline void gs(char *s) { scanf("%s", s); }
inline void gc(char &c) {
  while ((c = getchar()) > 126 || c < 33)
    ;
}
inline void pc(char c) { putchar(c); }
inline long long sqr(long long a) { return a * a; }
inline double sqrf(double a) { return a * a; }
const int inf = 0x3f3f3f3f;
const double pi = 3.14159265358979323846264338327950288L;
const double eps = 1e-6;
const int mo = 1;
int qp(int a, long long b) {
  int n = 1;
  do {
    if (b & 1) n = 1ll * n * a % mo;
    a = 1ll * a * a % mo;
  } while (b >>= 1);
  return n;
}
int n;
int a[222];
int nok[33333];
int ok[33333];
int bo[222][222];
const int dinic_inf = 0x3f3f3f3f;
const int DINIC_MAXV = 555 + 5;
const int DINIC_MAXE = 55555 + 5;
int s, t, vtot;
struct edge {
  int v, next;
  int f;
} e[DINIC_MAXE * 2];
int g[DINIC_MAXV], etot, eid;
int ae(int u, int v, int f) {
  upmax(vtot, u);
  upmax(vtot, v);
  e[etot].v = v;
  e[etot].f = f;
  e[etot].next = g[u];
  g[u] = etot++;
  e[etot].v = u;
  e[etot].f = 0;
  e[etot].next = g[v];
  g[v] = etot++;
  return eid++;
}
int d[DINIC_MAXV];
bool lb() {
  for (int i = 0; i <= vtot; i++) d[i] = 0;
  static int qu[DINIC_MAXV];
  int p = 0, q = 0;
  qu[q++] = s, d[s] = 1;
  while (p != q) {
    int u = qu[p++];
    for (int i = g[u]; ~i; i = e[i].next)
      if (e[i].f && !d[e[i].v]) {
        d[e[i].v] = d[u] + 1;
        if (e[i].v == t) return 1;
        qu[q++] = e[i].v;
      }
  }
  return 0;
}
int aug(int u, int mi) {
  if (u == t) return mi;
  int su = 0, del;
  for (int i = g[u]; ~i; i = e[i].next)
    if (e[i].f && d[e[i].v] == d[u] + 1) {
      del = aug(e[i].v, min(mi, e[i].f));
      e[i].f -= del;
      e[i ^ 1].f += del;
      mi -= del;
      su += del;
      if (!mi) break;
    }
  if (!su) d[u] = -1;
  return su;
}
int dinic() {
  int su = 0;
  while (lb()) su += aug(s, dinic_inf);
  return su;
}
void dinic_init() {
  static bool ini = 0;
  if (!ini) {
    ini = 1;
    memset(g, -1, sizeof(g));
  } else {
    for (int i = 0; i <= vtot; i++) g[i] = -1;
  }
  etot = eid = 0;
  vtot = 2, s = 1, t = 2;
}
inline int capaof(int ei) { return e[ei << 1].f + e[ei << 1 ^ 1].f; }
inline int flowof(int ei) { return e[ei << 1 ^ 1].f; }
inline int resiof(int ei) { return e[ei << 1].f; }
inline int uof(int ei) { return e[ei << 1 ^ 1].v; }
inline int vof(int ei) { return e[ei << 1].v; }
vector<int> nei[222];
int vis[222];
int cur = 0;
vector<int> ans[222];
void dfs(int u) {
  if (vis[u]) return;
  ans[cur].push_back(u);
  vis[u] = 1;
  dfs(nei[u][0]);
  dfs(nei[u][1]);
}
int main() {
  nok[1] = 1;
  for (int i = 2; i <= 30000; i++)
    if (!nok[i])
      for (int j = i + i; j <= 30000; j += i) nok[j] = 1;
  for (int i = 2; i <= 30000; i++) ok[i] = !nok[i];
  gn(n);
  for (int i = (1), _ed = (n + 1); i < _ed; i++) gn(a[i]);
  for (int i = (1), _ed = (n + 1); i < _ed; i++)
    for (int j = (1), _ed = (n + 1); j < _ed; j++)
      if (i != j && ok[a[i] + a[j]]) bo[i][j] = 1;
  int nu0 = 0, nu1 = 0;
  for (int i = (1), _ed = (n + 1); i < _ed; i++)
    if (a[i] & 1)
      nu1++;
    else
      nu0++;
  if (nu0 != nu1) {
    printf("Impossible\n");
    return 0;
  }
  dinic_init();
  for (int i = (1), _ed = (n + 1); i < _ed; i++)
    if (a[i] & 1)
      for (int j = (1), _ed = (n + 1); j < _ed; j++)
        if (bo[i][j]) ae(i, j, 1);
  s = n + 1, t = n + 2;
  for (int i = (1), _ed = (n + 1); i < _ed; i++)
    if (a[i] & 1)
      ae(s, i, 2);
    else
      ae(i, t, 2);
  int su = dinic();
  if (su != n) {
    printf("Impossible\n");
    return 0;
  }
  for (int i = (0), _ed = (eid); i < _ed; i++)
    if (uof(i) != s && vof(i) != t && flowof(i) == 1) {
      nei[uof(i)].push_back(vof(i));
      nei[vof(i)].push_back(uof(i));
    }
  for (int i = (1), _ed = (n + 1); i < _ed; i++)
    if (!vis[i]) {
      ++cur;
      dfs(i);
    }
  printf("%d", cur);
  for (int i = (1), _ed = (cur + 1); i < _ed; i++) {
    printf("\n%d", ans[i].size());
    for (int j = (0), _ed = (((int)(ans[i]).size())); j < _ed; j++)
      printf(" %d", ans[i][j]);
  }
  return 0;
}
