#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while ((c < '0' || c > '9') && c - '-') c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - 48;
    c = getchar();
  }
  return x * f;
}
const int N = 2e5 + 10;
const long long mo = 998244353;
int first[N], ne[N], to[N], cnt = 0;
inline void add(int x, int y) {
  cnt++;
  ne[cnt] = first[x];
  first[x] = cnt;
  to[cnt] = y;
}
int n;
long long f[N], g[N], h[N];
void dfs(int u) {
  if (!first[u]) {
    g[u] = 1;
    return;
  }
  h[u] = 1;
  for (int i = first[u]; i; i = ne[i]) {
    int v = to[i];
    dfs(v);
    g[u] =
        (g[u] * (f[v] + (g[v] << 1) + h[v]) % mo + f[u] * (f[v] + g[v]) % mo) %
        mo;
    f[u] = (f[u] * (g[v] + h[v]) % mo + h[u] * (g[v] + f[v]) % mo) % mo;
    h[u] = (h[u] * (g[v] + h[v])) % mo;
  }
}
int main() {
  n = read();
  for (int i = 2; i <= n; i++) add(read(), i);
  dfs(1);
  cout << (g[1] + h[1]) % mo << "\n";
  return 0;
}
