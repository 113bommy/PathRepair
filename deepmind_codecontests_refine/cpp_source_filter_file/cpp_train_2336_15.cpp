#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e20;
const long long maxn = (1 << 20) + 10;
long long n, m, b, f[maxn], ans = inf;
struct Node {
  long long x, k, d;
  bool operator<(const Node b) const { return k < b.k; }
} p[110];
void cal(long long x) {
  for (long long i = 0; i < (1 << m); i++) {
    f[i | p[x].d] = min(f[i | p[x].d], f[i] + p[x].x);
  }
  ans = min(ans, f[(1 << m) - 1] + p[x].k * b);
}
signed main() {
  cin >> n >> m >> b;
  for (long long i = 1; i <= n; i++) {
    long long tot, x;
    cin >> p[i].x >> p[i].k >> tot;
    while (tot--) {
      cin >> x;
      p[i].d |= 1 << (x - 1);
    }
  }
  for (long long i = 0; i < (1 << m); i++) f[i] = inf;
  sort(p + 1, p + n + 1);
  f[0] = 0;
  for (long long i = 1; i <= n; i++) cal(i);
  if (ans >= inf) ans = -1;
  cout << ans << endl;
  return 0;
}
