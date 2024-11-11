#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  register long long x(0);
  register char ch(getchar());
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') x = (x * 10) + (ch ^ 48), ch = getchar();
  return x;
}
const int N = 660, M = 1e5 + 10;
int h[N], cnt, in[N], ou[N], d[N];
struct edge {
  int next, to;
} e[M];
void add(int u, int v) { e[++cnt] = (edge){h[u], v}, h[u] = cnt; }
long long n, m, mod, f[N][N], g[N];
queue<int> q;
long long ksm(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return res;
}
void init(int s) {
  memset(g, 0, sizeof(g));
  memcpy(d, in, sizeof(in));
  g[s] = 1;
  for (int i = 1; i <= n; ++i)
    if (!in[i]) q.push(i);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = h[u], v; v = e[i].to, i; i = e[i].next) {
      d[v]--;
      g[v] = (g[v] + g[u]) % mod;
      if (!d[v]) q.push(v);
    }
  }
}
long long get() {
  long long ans = 1;
  for (int i = 1; i <= cnt; ++i) {
    int pos = 0;
    for (int j = i; j <= cnt; ++j)
      if (f[j][i]) pos = j;
    if (!pos) return 0;
    if (pos != i) ans = mod - ans, swap(f[pos], f[i]);
    long long inv = ksm(f[i][i], mod - 2);
    for (int j = i + 1; j <= cnt; ++j) {
      long long t = inv * f[j][i] % mod;
      for (int k = i; k <= cnt; ++k)
        f[j][k] = (f[j][k] - t * f[i][k] % mod) % mod;
    }
    ans = ans * f[i][i] % mod;
  }
  return ans;
}
int main() {
  n = read(), m = read(), mod = read();
  for (int i = 1; i <= m; ++i) {
    int u = read(), v = read();
    add(u, v);
    ++in[v];
    ++ou[u];
  }
  cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (!in[i]) {
      ++cnt;
      init(i);
      int tot = 0;
      for (int j = 1; j <= n; ++j) {
        if (!ou[j]) f[cnt][++tot] = g[j];
      }
    }
  }
  cout << get() << endl;
  return 0;
}
