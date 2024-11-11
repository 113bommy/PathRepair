#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
long double eps = 1e-9;
long long pp = 1000000007;
long long mo(long long a, long long pp) {
  if (a >= 0 && a < pp) return a;
  a %= pp;
  if (a < 0) a += pp;
  return a;
}
long long powmod(long long a, long long b, long long pp) {
  long long ans = 1;
  for (; b; b >>= 1, a = mo(a * a, pp))
    if (b & 1) ans = mo(ans * a, pp);
  return ans;
}
void fre() {
  freopen("c://test//input.in", "r", stdin);
  freopen("c://test//output.out", "w", stdout);
}
int dx[5] = {0, -1, 1, 0, 0}, dy[5] = {0, 0, 0, -1, 1};
long long read() {
  long long ans = 0;
  char last = ' ', ch = getchar();
  while (ch < '0' || ch > '9') last = ch, ch = getchar();
  while (ch >= '0' && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar();
  if (last == '-') ans = -ans;
  return ans;
}
const int N = 105, M = 50005, inf = 1 << 30;
int v[M], Next[M], head[N], c[M], val[M], gd[N], gf[N], gp[N], l[N], r[N], n, q,
    e;
queue<int> Q;
void add(int a, int b, int c_, int d) {
  v[++e] = b;
  Next[e] = head[a];
  head[a] = e;
  c[e] = c_;
  val[e] = d;
  v[++e] = a;
  Next[e] = head[b];
  head[b] = e;
  c[e] = 0;
  val[e] = -d;
}
int SPFA(int s, int t) {
  for (int i = 1; i <= n + n + 2; i++) gd[i] = inf;
  gd[s] = 0;
  Q.push(s);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int i = head[u]; i != -1; i = Next[i])
      if (c[i] && gd[v[i]] > gd[u] + val[i]) {
        gd[v[i]] = gd[u] + val[i];
        gf[v[i]] = u;
        gp[v[i]] = i;
        Q.push(v[i]);
      }
  }
  if (gd[t] == inf)
    return 0;
  else
    return 1;
}
int main() {
  while (~scanf("%d%d", &n, &q)) {
    memset(head, -1, sizeof(head));
    e = -1;
    for (int i = 1; i <= n; i++) l[i] = 1, r[i] = n;
    for (int i = 1; i <= q; i++) {
      int f = read(), a = read(), b = read(), c = read();
      if (f == 1)
        for (int j = a; j <= b; j++) l[j] = max(l[j], c);
      else
        for (int j = a; j <= b; j++) r[j] = min(r[j], c);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = l[i]; j <= r[i]; j++) add(i, n + j, 1, 0);
    }
    for (int i = 1; i <= n; i++) add(n + n + 1, i, 1, 0);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) add(n + i, n + n + 2, 1, j + j - 1);
    }
    int cost = 0, flow = 0;
    while (SPFA(n + n + 1, n + n + 2)) {
      int f = inf;
      for (int u = n + n + 2; u != n + n + 1; u = gf[u]) f = min(f, c[gp[u]]);
      flow += f;
      cost += f * gd[n + n + 2];
      for (int u = n + n + 2; u != n + n + 1; u = gf[u])
        c[gp[u]] -= f, c[gp[u] ^ 1] += f;
    }
    if (cost == 0)
      puts("-1");
    else
      printf("%d\n", cost);
  }
  return 0;
}
