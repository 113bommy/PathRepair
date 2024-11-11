#include <bits/stdc++.h>
using namespace std;
const int iinf = 1e9 + 7;
const long long linf = 1ll << 62;
const double dinf = 1e10;
inline long long read() {
  bool f = 0;
  long long x = 0;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') {
    f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  if (f) x = -x;
  return x;
}
inline void scf(int &x) {
  bool f = 0;
  x = 0;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') {
    f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  if (f) x = -x;
  return;
}
void scf(int &x, int &y) {
  scf(x);
  return scf(y);
}
void scf(int &x, int &y, int &z) {
  scf(x);
  scf(y);
  return scf(z);
}
const int N = 233;
const int M = 50055;
int n, m;
long long G, S;
struct edge {
  int u, v;
  long long g, s;
  void in() {
    scf(u, v);
    g = read();
    s = read();
    return;
  }
} e[M];
int id[M];
int rar, rare;
int par[N];
int q[N], que[N];
inline int find(int u) { return par[u] == u ? u : par[u] = find(par[u]); }
inline bool cmp_g(int u, int v) { return e[u].g < e[v].g; }
inline bool cmp_s(int u, int v) { return e[u].s < e[v].s; }
int main() {
  scf(n, m);
  G = read();
  S = read();
  for (int i = 0; i < (m); i++) e[i].in(), id[i] = i;
  sort(id, id + m, cmp_g);
  long long ans = linf;
  for (int i = 0; i < (m); i++) {
    rare = 0;
    q[rar++] = id[i];
    sort(q, q + rar, cmp_s);
    for (int u = (1); u <= (n); u++) par[u] = u;
    long long mx = 0;
    for (int j = 0; j < (rar); j++) {
      const edge &E = e[q[j]];
      if (find(E.u) == find(E.v)) continue;
      mx = E.s;
      que[rare++] = q[j];
      par[find(E.u)] = find(E.v);
    }
    memcpy(q, que, sizeof(que));
    rar = rare;
    if (rar < n - 1) continue;
    long long calc = e[id[i]].g * G + mx * S;
    (calc < ans) && (ans = calc);
  }
  printf("%I64d\n", ans == linf ? -1 : ans);
  return 0;
}
