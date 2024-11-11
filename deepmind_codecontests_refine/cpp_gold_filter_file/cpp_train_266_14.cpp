#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long xx = 0, ff = 1;
  char ch = getchar();
  while (ch < '0' or ch > '9') {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (ch >= '0' and ch <= '9') {
    xx = xx * 10 - '0' + ch;
    ch = getchar();
  }
  return xx * ff;
}
const long long N = 4e4 + 10;
const long long INF = 0x3f3f3f3f3f3f3f3f;
long long n, K, m;
long long a[N], b[N];
long long len[N];
long long poi[100], p_cnt;
long long is[N];
long long tot;
long long last[N], nex[N * 110 * 2], ver[N * 110 * 2];
inline void add(long long u, long long v) {
  nex[++tot] = last[u];
  ver[tot] = v;
  last[u] = tot;
}
long long dist[110][110];
bool vis[N];
pair<long long, long long> q[N * 10];
long long hd, ed;
void bfs(long long s, long long sign) {
  memset(vis, 0, sizeof vis);
  hd = ed = 0;
  vis[s] = 1;
  dist[sign][sign] = 0;
  q[ed++] = make_pair(s, 0);
  long long num = 1;
  while (hd != ed) {
    long long u = q[hd].first;
    long long d = q[hd++].second;
    for (long long i = last[u]; i; i = nex[i]) {
      long long r = ver[i];
      if (vis[r]) continue;
      vis[r] = true;
      if (is[r]) dist[sign][is[r]] = min(dist[sign][is[r]], d + 1), num++;
      if (num == p_cnt) return;
      q[ed++] = make_pair(r, d + 1);
    }
  }
}
long long f[1 << 21];
int main() {
  n = rd();
  K = rd();
  m = rd();
  for (long long i = 1; i <= K; i++) a[rd()] = 1;
  for (long long i = 1; i <= m; i++) len[i] = rd();
  for (long long i = 0; i <= n; i++) {
    b[i] = a[i] ^ a[i + 1];
    if (b[i]) {
      poi[++p_cnt] = i;
      is[i] = p_cnt;
    }
  }
  memset(dist, 0x3f, sizeof dist);
  for (long long i = 0; i <= n; i++)
    for (long long j = 1; j <= m; j++) {
      if (i - len[j] >= 0) add(i, i - len[j]);
      if (i + len[j] <= n) add(i, i + len[j]);
    }
  for (long long i = 1; i <= p_cnt; i++) bfs(poi[i], i);
  memset(f, 0x3f, sizeof f);
  f[0] = 0;
  for (long long i = 0; i < (1 << p_cnt); i++) {
    long long j = 1;
    for (; j <= p_cnt; j++)
      if ((i & (1 << (j - 1))) == 0) break;
    for (long long k = j + 1; k <= p_cnt; k++)
      if (!(i & (1 << (k - 1))))
        f[i | (1 << (j - 1)) | (1 << (k - 1))] =
            min(f[i | (1 << (j - 1)) | (1 << (k - 1))], f[i] + dist[j][k]);
  }
  long long ans = f[(1 << p_cnt) - 1] == INF ? -1 : f[(1 << p_cnt) - 1];
  printf("%lld", ans);
  return 0;
}
