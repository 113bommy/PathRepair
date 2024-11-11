#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const double pi = acos(-1);
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int t, n, a, b, da, db;
struct p {
  int u, v, nxt;
} e[200005];
int inde[100005], tot, dep[100005];
void add(int u, int v) {
  e[++tot] = p{u, v, inde[u]};
  inde[u] = tot;
}
int S, T, mx;
void dfs(int u, int f) {
  int i, v;
  dep[u] = dep[f] + 1;
  if (dep[u] > dep[mx]) mx = u;
  for (i = inde[u]; i; i = e[i].nxt) {
    v = e[i].v;
    if (v == f) continue;
    dfs(v, u);
  }
}
int main() {
  int i, j, u, v;
  t = read();
  while (t--) {
    n = read(), a = read(), b = read(), da = read(), db = read();
    for (i = 1; i <= n; i++) inde[i] = 0;
    tot = 0;
    for (i = 1; i < n; i++) u = read(), v = read(), add(u, v), add(v, u);
    mx = dep[a] = 0;
    dfs(a, 0);
    if (dep[b] - dep[a] <= da) {
      puts("Alice");
      continue;
    }
    S = mx, mx = 0;
    dfs(S, 0);
    T = mx;
    if (dep[T] - dep[S] < 2 * da + 1) {
      puts("Alice");
      continue;
    }
    if (2 * da + 1 < db) {
      puts("Bob");
      continue;
    }
    puts("Alice");
  }
}
