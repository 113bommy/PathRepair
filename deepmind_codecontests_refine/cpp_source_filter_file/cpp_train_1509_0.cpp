#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
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
struct arr {
  long long x, s;
  bool operator<(const arr &A) const { return A.s > s; }
};
long long n, m, s, t, v[200005], w[200005], head[200005], nxt[200005], cnt,
    dis[200005], ds[200005], dt[200005], a[200005], f[2][2005][2005],
    num[2005][2005], sum[2005][2005], vis[200005];
long long sumx[2005][2005], sumy[2005][2005], numx[2005][2005],
    numy[2005][2005];
vector<long long> dds, ddt;
void add(long long a, long long b, long long c) {
  v[++cnt] = b;
  w[cnt] = c;
  nxt[cnt] = head[a];
  head[a] = cnt;
}
inline void dijkstra(long long S) {
  memset(dis, 999999, sizeof(dis));
  memset(vis, 0, sizeof(vis));
  dis[S] = 0;
  priority_queue<arr> q;
  q.push((arr){S, 0});
  while (!q.empty()) {
    long long x = q.top().x;
    q.pop();
    if (vis[x]) continue;
    vis[x] = 1;
    for (long long i = head[x]; i; i = nxt[i]) {
      if (dis[v[i]] > dis[x] + w[i]) {
        dis[v[i]] = dis[x] + w[i];
        q.push((arr){v[i], dis[v[i]]});
      }
    }
  }
}
long long getsumx(long long x, long long l, long long r) {
  return sumx[x][r] - sumx[x][l - 1];
}
long long getsumy(long long y, long long l, long long r) {
  return sumy[r][y] - sumy[l - 1][y];
}
long long getnumx(long long x, long long l, long long r) {
  return sumx[x][r] - sumx[x][l - 1];
}
long long getnumy(long long y, long long l, long long r) {
  return sumy[r][y] - sumy[l - 1][y];
}
signed main() {
  n = read();
  m = read();
  s = read();
  t = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i <= m; i++) {
    long long x = read(), y = read(), z = read();
    add(x, y, z);
    add(y, x, z);
  }
  dijkstra(s);
  for (long long i = 1; i <= n; i++) ds[i] = dis[i], dds.push_back(ds[i]);
  dijkstra(t);
  for (long long i = 1; i <= n; i++) dt[i] = dis[i], ddt.push_back(dt[i]);
  sort(dds.begin(), dds.end());
  sort(ddt.begin(), ddt.end());
  long long ds_ = unique(dds.begin(), dds.end()) - dds.begin();
  long long dt_ = unique(ddt.begin(), ddt.end()) - ddt.begin();
  for (long long i = 1; i <= n; i++) {
    long long xx = lower_bound(dds.begin(), dds.end(), ds[i]) - dds.begin() + 1;
    long long yy = lower_bound(ddt.begin(), ddt.end(), dt[i]) - ddt.begin() + 1;
    num[xx][yy]++;
    sum[xx][yy] += a[i];
  }
  for (long long i = 1; i <= dt_ + 1; i++) {
    for (long long j = 1; j <= ds_ + 1; j++) {
      sumx[i][j] = sumx[i][j - 1] + sum[i][j];
      sumy[i][j] = sumy[i - 1][j] + sum[i][j];
      numx[i][j] = numx[i][j - 1] + num[i][j];
      numy[i][j] = numy[i - 1][j] + num[i][j];
    }
  }
  for (long long i = dt_; i >= 0; i--) {
    for (long long j = ds_; j >= 0; j--) {
      if (i != dt_) {
        long long now = getnumx(i + 1, j + 1, ds_);
        long long sc = getsumx(i + 1, j + 1, ds_);
        if (!now)
          f[0][i][j] = f[0][i + 1][j];
        else
          f[0][i][j] = max(f[0][i + 1][j], f[1][i + 1][j]) + sc;
      }
      if (j != ds_) {
        long long now = getnumy(j + 1, i + 1, dt_);
        long long sc = getsumy(j + 1, i + 1, dt_);
        if (!now)
          f[1][i][j] = f[1][i][j + 1];
        else
          f[1][i][j] = min(f[0][i][j + 1], f[1][i][j + 1]) - sc;
      }
    }
  }
  if (f[0][0][0] > 0)
    puts("Break a heart");
  else if (f[0][0][0] == 0)
    puts("Flowers");
  else
    puts("Cry");
}
