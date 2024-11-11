#include <bits/stdc++.h>
using namespace std;
unsigned long long read() {
  unsigned long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
map<unsigned long long, unsigned long long> Mp;
bitset<30005> G[30005];
unsigned long long n, k, Now[30005], p[30005], A[30005], B[30005], cnt,
    vis[30005];
pair<unsigned long long, unsigned long long> a[30005];
vector<unsigned long long> E[30005];
void add(unsigned long long x, unsigned long long y) {
  if (G[x][y]) return;
  G[x][y] = G[y][x] = 1;
  A[++cnt] = x;
  B[cnt] = y;
  vis[x] = vis[y] = 1;
}
signed main() {
  n = read();
  k = read();
  for (unsigned long long i = 1; i <= k; i++) {
    unsigned long long now = 0;
    for (unsigned long long j = 1; j <= n; j++) Now[j] = read();
    for (unsigned long long j = 1; j <= n; j++)
      if (!Now[j]) {
        now = j;
        break;
      }
    if (!now) return puts("-1"), 0;
    for (unsigned long long j = now + 1; j <= n; j++)
      if (!Now[j]) return puts("-1"), 0;
    p[i] = now;
    E[now].push_back(0);
    for (unsigned long long j = 1; j <= n; j++) E[now].push_back(Now[j]);
  }
  for (unsigned long long i = 1; i <= n; i++) a[i] = make_pair(E[p[1]][i], i);
  vis[p[1]] = 1;
  sort(a + 1, a + 1 + n);
  for (unsigned long long i = 2; i <= k; i++) {
    unsigned long long now = p[1];
    for (unsigned long long j = 2; j <= n; j++) {
      unsigned long long x = a[j].second;
      if (a[j].first + E[p[i]][x] == E[p[1]][p[i]]) add(now, x), now = x;
    }
  }
  for (unsigned long long i = 1; i <= n; i++) {
    if (!vis[i]) continue;
    unsigned long long Hash = 0;
    for (unsigned long long j = 1; j <= k; j++)
      Hash = Hash * 44042137 + E[p[j]][i];
    Mp[Hash] = i;
  }
  for (unsigned long long i = 2; i <= n; i++) {
    unsigned long long x = a[i].second;
    if (vis[x]) continue;
    unsigned long long Hash = 0;
    for (unsigned long long j = 1; j <= k; j++) {
      Hash = Hash * 44042137 + E[p[j]][x] - 1ll;
    }
    if (!Mp[Hash]) return puts("-1"), 0;
    add(Mp[Hash], x);
    Hash = 0;
    for (unsigned long long j = 1; j <= k; j++)
      Hash = Hash * 44042137 + E[p[j]][x];
    Mp[Hash] = x;
  }
  for (unsigned long long i = 1; i <= cnt; i++)
    printf("%lld %lld\n", A[i], B[i]);
  return 0;
}
