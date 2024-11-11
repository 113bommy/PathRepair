#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, w = 0;
  char c = getchar();
  while (!isdigit(c)) w |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return w ? -x : x;
}
namespace star {
const long long maxn = 2e5 + 10;
long long n, m, f[maxn], path[maxn];
bool vis[maxn];
vector<long long> G[maxn];
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
void exgcd(long long &d, long long a, long long b, long long &x, long long &y) {
  if (!b)
    d = a, x = 1, y = 0;
  else
    exgcd(d, b, a % b, y, x), y -= (a / b) * x;
}
inline void work() {
  n = read(), m = read();
  for (long long i = 1; i <= n; i++) vis[read()] = 1;
  for (long long i = 0; i < m; i++)
    if (!vis[i]) G[gcd(i, m)].push_back(i);
  if (vis[0]) G[m].push_back(0);
  for (long long i = 1; i <= m; i++) {
    f[i] = 0;
    if (G[i].empty()) continue;
    for (long long j = 1; j < i; j++)
      if (!(i % j) and f[j] > f[i]) f[i] = f[j], path[i] = j;
    f[i] += G[i].size();
  }
  long long now = m;
  vector<long long> ans;
  while (!G[now].empty()) {
    for (long long i = 0; i < G[now].size(); i++) ans.push_back(G[now][i]);
    now = path[now];
  }
  reverse(ans.begin(), ans.end());
  if (vis[0]) ans.pop_back();
  printf("%lld\n", ans.size());
  long long cur = 1;
  for (long long i = 0; i < ans.size(); i++) {
    long long gcd, x, y, u = ans[i];
    exgcd(gcd, cur, m, x, y);
    printf("%lld ", (x * u / gcd % (m / gcd) + (m / gcd)) % (m / gcd));
    cur = u;
  }
}
}  // namespace star
signed main() {
  star::work();
  return 0;
}
