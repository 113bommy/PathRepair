#include <bits/stdc++.h>
using namespace std;
const long long N = 1010;
struct node {
  long long x, y, v;
} ans[N * N];
long long s[N][N], sum[N][N], minx[N][N], miny[N][N];
long long q[N], hd, tl;
bool vis[N][N];
priority_queue<pair<long long, pair<long long, long long> > > pq;
signed main() {
  long long n, m, a, b, num = 0;
  scanf("%lld%lld%lld%lld", &n, &m, &a, &b);
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) {
      scanf("%lld", &s[i][j]);
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + s[i][j];
    }
  for (long long i = 1; i <= n; i++) {
    hd = 1, tl = 0;
    for (long long j = 1; j <= m; j++) {
      while (tl >= hd && s[i][q[tl]] > s[i][j]) tl--;
      q[++tl] = j;
      while (tl >= hd && q[hd] <= j - b) hd++;
      if (j >= b) minx[i][j - b + 1] = s[i][q[hd]];
    }
  }
  for (long long j = 1; j <= m - b + 1; j++) {
    hd = 1, tl = 0;
    for (long long i = 1; i <= n; i++) {
      while (tl >= hd && minx[q[tl]][j] > minx[i][j]) tl--;
      q[++tl] = i;
      while (tl >= hd && q[hd] <= i - a) hd++;
      if (i >= a) miny[i - a + 1][j] = minx[q[hd]][j];
    }
  }
  for (long long i = 1; i + a - 1 <= n; i++) {
    for (long long j = 1; j + b - 1 <= m; j++) {
      long long ti = i + a - 1, tj = j + b - 1,
                tmp = sum[ti][tj] - sum[ti][j - 1] - sum[i - 1][tj] +
                      sum[i - 1][j - 1] - a * b * miny[i][j];
      pq.push(make_pair(-tmp, make_pair(-i, -j)));
    }
  }
  while (!pq.empty()) {
    long long x = -pq.top().second.first, y = -pq.top().second.second,
              v = -pq.top().first;
    pq.pop();
    if (vis[x][y]) continue;
    ans[++num].x = x, ans[num].y = y, ans[num].v = v;
    for (long long i = max(1ll, x - a + 1); i <= min(n, x + a - 1); i++)
      for (long long j = max(1ll, y - b + 1); j <= min(m, y + b - 1); j++)
        vis[i][j] = 1;
  }
  printf("%lld\n", num);
  for (long long i = 1; i <= num; i++)
    printf("%lld %lld %lld\n", ans[i].x, ans[i].y, ans[i].v);
  return 0;
}
