#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e3, maxm = 1e5, inf = LLONG_MAX >> 1;
long long n, m, s, t, x, y, z, tot, head[maxn + 1], suc[maxm << 1 | 1],
    len[maxm << 1 | 1], to[maxm << 1 | 1], dis[2][maxn + 1], p[maxn + 1],
    cnt[maxn + 1][maxn + 1], last[2][maxn + 1][maxn + 1],
    sum[maxn + 1][maxn + 1], f[2][maxn + 1][maxn + 1];
bool vis[maxn + 1];
pair<long long, long long> minx[2][maxn + 1][2];
struct city {
  long long dis, no;
  city(long long a = 0, long long b = 0) : dis(a), no(b) {}
} cities[2][maxn + 1];
inline bool cmp(const city &t1, const city &t2) { return t1.dis < t2.dis; }
inline void add_edge(long long x, long long y, long long z) {
  suc[++tot] = head[x];
  head[x] = tot;
  to[tot] = y;
  len[tot] = z;
  return;
}
void Dijkstra(long long opt, long long start) {
  memset(vis, 0, sizeof vis);
  dis[opt][start] = 0;
  for (long long i = 1; i <= n; ++i) {
    long long pos = 0;
    for (long long j = 1; j <= n; ++j)
      if (!vis[j] && dis[opt][j] < dis[opt][pos]) pos = j;
    vis[pos] = true;
    for (long long j = head[pos]; j; j = suc[j])
      if (dis[opt][to[j]] > dis[opt][pos] + len[j])
        dis[opt][to[j]] = dis[opt][pos] + len[j];
  }
  for (long long i = 1; i <= n; ++i) {
    cities[opt][i].dis = dis[opt][i];
    cities[opt][i].no = i;
  }
  sort(cities[opt] + 1, cities[opt] + n + 1, cmp);
  return;
}
signed main() {
  memset(dis, 0x3f, sizeof dis);
  scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
  for (long long i = 1; i <= n; ++i) scanf("%lld", &p[i]);
  for (long long i = 1; i <= m; ++i) {
    scanf("%lld%lld%lld", &x, &y, &z);
    add_edge(x, y, z);
    add_edge(y, x, z);
  }
  Dijkstra(0, s);
  Dijkstra(1, t);
  for (long long i = 1; i <= n; ++i) {
    long long pos1 = lower_bound(cities[0] + 1, cities[0] + n + 1,
                                 city(cities[0][i].dis, 0), cmp) -
                     cities[0] - 1,
              pos2 = lower_bound(cities[1] + 1, cities[1] + n + 1,
                                 city(dis[1][cities[0][i].no], 0), cmp) -
                     cities[1] - 1;
    ++cnt[pos1][pos2];
    sum[pos1][pos2] += p[cities[0][i].no];
  }
  for (long long i = n; ~i; --i)
    for (long long j = n; ~j; --j) {
      cnt[i][j] += cnt[i][j + 1] + cnt[i + 1][j] - cnt[i + 1][j + 1];
      sum[i][j] += sum[i][j + 1] + sum[i + 1][j] - sum[i + 1][j + 1];
    }
  for (long long i = n; ~i; --i)
    for (long long j = n; ~j; --j) {
      if (!cnt[i][j]) continue;
      f[0][i][j] =
          sum[i][j] - (minx[0][j][0].second == cnt[i][j] ? minx[0][j][1].first
                                                         : minx[0][j][0].first);
      f[1][i][j] =
          sum[i][j] - (minx[1][i][0].second == cnt[i][j] ? minx[1][i][1].first
                                                         : minx[1][i][0].first);
      if (minx[0][j][0].second == cnt[i][j])
        minx[0][j][0].first = min(minx[0][j][0].first, f[1][i][j]);
      else {
        minx[0][j][1] =
            min(minx[0][j][1],
                max(minx[0][j][0], make_pair(f[1][i][j], cnt[i][j])));
        minx[0][j][0] = min(minx[0][j][0], make_pair(f[1][i][j], cnt[i][j]));
      }
      if (minx[1][i][0].second == cnt[i][j])
        minx[1][i][0].first = min(minx[1][i][0].first, f[0][i][j]);
      else {
        minx[1][i][1] =
            min(minx[1][i][1],
                max(minx[1][i][0], make_pair(f[0][i][j], cnt[i][j])));
        minx[1][i][0] = min(minx[1][i][0], make_pair(f[0][i][j], cnt[i][j]));
      }
    }
  if (f[0][0][0] > sum[0][0] - f[0][0][0])
    puts("Break a heart");
  else if (f[0][0][0] < sum[0][0] - f[0][0][0])
    puts("Cry");
  else
    puts("Flowers");
  return 0;
}
