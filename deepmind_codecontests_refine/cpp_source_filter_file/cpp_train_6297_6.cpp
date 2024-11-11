#include <bits/stdc++.h>
const long long mod = 1000000007, maxn = 100005;
using namespace std;
long long n, m, vis[maxn], ans, col[maxn], cnt, x, y, z, head[maxn];
struct line {
  long long to, next, val;
} q[maxn];
void pushline(long long x, long long y, long long z) {
  q[++cnt].next = head[x];
  head[x] = cnt;
  q[cnt].to = y;
  q[cnt].val = z;
}
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return res;
}
void dfs(long long x, long long fa, long long cl) {
  if (vis[x]) {
    if (col[x] != cl) cout << "0" << endl, exit(0);
    return;
  }
  vis[x] = 1;
  col[x] = cl;
  for (long long p = head[x]; p; p = q[p].next) {
    long long v = q[p].to;
    if (v == fa) continue;
    dfs(v, x, (q[p].val ? cl : -cl));
  }
}
signed main() {
  cin >> n >> m;
  for (long long i = 1; i <= m; i++)
    cin >> x >> y >> z, pushline(x, y, z), pushline(y, x, z);
  for (long long i = 1; i <= n; i++)
    if (!vis[i]) ans++, dfs(i, 0, 1);
  printf("%d\n", qpow(2, ans - 1));
  return 0;
}
