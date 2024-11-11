#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
template <typename T>
inline void read(T &x) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  }
  x *= f;
}
struct edge {
  int u, v, next;
  edge(int u, int v, int next) : u(u), v(v), next(next) {}
  edge() {}
} e[maxn << 1];
int head[maxn], ecnt;
inline void add(int u, int v) {
  e[ecnt] = edge(u, v, head[u]);
  head[u] = ecnt++;
}
int n;
double S[maxn], T[maxn], sum[maxn], ans;
int siz[maxn];
void dfs(int u, int fa) {
  siz[u] = 1;
  sum[u] = S[u];
  double res = 0;
  for (int i = head[u]; ~i; i = e[i].next) {
    int v = e[i].v;
    if (v == fa) continue;
    dfs(v, u);
    siz[u] += siz[v];
    sum[u] += sum[v];
    res += sum[v] * siz[v];
  }
  res += (1 - sum[u]) * (n - siz[u]);
  ans += res * T[u];
}
int main() {
  read(n);
  memset(head, -1, sizeof(head));
  for (int i = 1, u, v; i < n; ++i) {
    read(u), read(v);
    add(u, v);
    add(v, u);
  }
  double totS = 0, totT = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%lf %lf", &S[i], &T[i]);
    totS += S[i], totT += T[i];
  }
  for (int i = 1; i <= n; ++i) S[i] /= totS, T[i] /= totT;
  dfs(1, 0);
  printf("%lf\n", ans);
  return 0;
}
