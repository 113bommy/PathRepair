#include <bits/stdc++.h>
using namespace std;
const long long N = 100005;
const long long M = 200005;
const long long MOD = 1e9 + 7;
long long n, m;
struct qq {
  long long x, y, z, last;
} e[M * 2];
long long num, last[N];
void init(long long x, long long y, long long z) {
  num++;
  e[num].x = x;
  e[num].y = y;
  e[num].z = z;
  e[num].last = last[x];
  last[x] = num;
}
bool vis[N];
long long ans = 0;
long long dep[N];
long long f[65];
long long p[65][2];
void Ins(long long x) {
  for (long long u = 62; u >= 0; u--)
    if ((x >> u) & 1) {
      if (f[u] == 0) {
        f[u] = x;
        return;
      }
      x ^= f[u];
    }
}
void dfs(long long x, long long fa) {
  for (long long u = 0; u <= 62; u++) p[u][(dep[x] >> u) & 1]++;
  vis[x] = true;
  for (long long u = last[x]; u != -1; u = e[u].last) {
    long long y = e[u].y;
    if (y == fa) continue;
    if (vis[y])
      Ins(dep[x] ^ e[u].z ^ dep[y]);
    else {
      dep[y] = (dep[x] ^ e[u].z);
      dfs(y, x);
    }
  }
}
void add(long long &x, long long y) { x = (x + y) % MOD; }
int main() {
  memset(vis, false, sizeof(vis));
  num = 0;
  memset(last, -1, sizeof(last));
  scanf("%I64d%I64d", &n, &m);
  for (long long u = 1; u <= m; u++) {
    long long x, y, z;
    scanf("%I64d%I64d%I64d", &x, &y, &z);
    init(x, y, z);
    init(y, x, z);
  }
  for (long long u = 1; u <= n; u++)
    if (!vis[u]) {
      memset(f, 0, sizeof(f));
      memset(p, 0, sizeof(p));
      dfs(u, 0);
      long long cnt = 0;
      for (long long u = 0; u <= 62; u++)
        if (f[u] != 0) cnt++;
      for (long long u = 0; u <= 62; u++) {
        bool tf = false;
        long long tot = 0;
        for (long long i = 0; i <= 62; i++) {
          if ((f[i] >> u) & 1) {
            tf = true;
            break;
          }
        }
        long long x;
        if (tf == true) {
          long long z = (1LL << cnt - 1) % MOD;
          x = p[u][0] * (p[u][0] - 1) / 2;
          x %= MOD;
          add(tot, x * z % MOD);
          x = p[u][1] * (p[u][1] - 1) / 2;
          x %= MOD;
          add(tot, x * z % MOD);
          x = p[u][0] * p[u][1];
          x %= MOD;
          add(tot, x * z % MOD);
        } else {
          x = p[u][0] * p[u][1];
          x %= MOD;
          add(tot, (1LL << cnt) % MOD * x % MOD);
        }
        add(ans, (1LL << u) % MOD * tot % MOD);
      }
    }
  printf("%I64d\n", ans);
  return 0;
}
