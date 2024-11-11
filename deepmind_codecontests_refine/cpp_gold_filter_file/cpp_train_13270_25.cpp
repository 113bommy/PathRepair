#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
long long in() {
  char c;
  bool g = false;
  while (c = getchar(), c < '0' || c > '9')
    if (c == '-')
      g = true;
    else
      g = false;
  long long x = 0;
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - 48;
    c = getchar();
  }
  return g ? -x : x;
}
void out(long long x) {
  long long len = 0, data[20];
  while (x) {
    data[len++] = x % 10;
    x /= 10;
  }
  if (!len) data[len++] = 0;
  if (data[0] != abs(data[0])) putchar('-');
  while (len--) putchar(abs(data[len]) + 48);
  putchar('\n');
}
void out(string s) {
  long long len = 0;
  while (len++ < s.size()) putchar(s[len - 1]);
  putchar('\n');
}
const long long N = 1001000;
long long src = 2019, snk = 2020, ecnt, n, m, ml, fml;
char c[1010][1010];
long long from[N], to[N], cap[N], prv[N], head[N], ptr[N];
bool vis[1010][1010];
vector<pair<pair<long long, long long>, pair<long long, long long> > > v;
void add(long long v, long long u, long long vu, long long uv) {
  from[ecnt] = v, to[ecnt] = u, cap[ecnt] = vu, prv[ecnt] = head[v],
  head[v] = ecnt++;
  from[ecnt] = u, to[ecnt] = v, cap[ecnt] = uv, prv[ecnt] = head[u],
  head[u] = ecnt++;
}
long long q[N], d[N];
bool bfs() {
  for (long long i = 0; i < N; i++) d[i] = INF;
  for (int i = 0; i < N; i++) ptr[i] = head[i];
  d[src] = 0;
  long long bg = 0, ed = 0;
  q[ed++] = src;
  while (ed > bg) {
    long long v = q[bg++];
    for (long long i = head[v]; i != -1; i = prv[i])
      if (cap[i] && d[to[i]] > d[v] + 1) {
        d[to[i]] = d[v] + 1;
        q[ed++] = to[i];
      }
  }
  return (d[snk] < INF);
}
long long dfs(long long v = src, long long c = 1e18) {
  if (v == snk || !c) return c;
  long long ans = 0;
  for (; ptr[v] != -1; ptr[v] = prv[ptr[v]])
    if (d[to[ptr[v]]] == d[v] + 1) {
      long long k = dfs(to[ptr[v]], min(c, cap[ptr[v]]));
      ans += k;
      cap[ptr[v]] -= k;
      cap[ptr[v] ^ 1] += k;
      c -= k;
      if (!c) break;
    }
  return ans;
}
long long flw() {
  long long mx = 0;
  while (bfs()) mx += dfs();
  return mx;
}
pair<pair<pair<long long, long long>, pair<long long, bool> >, long long> qq[N];
void okbfs(pair<pair<long long, long long>, pair<long long, bool> > v,
           long long p, long long d) {
  long long bg = 0, ed = 0;
  qq[ed++] = {v, d};
  while (ed > bg) {
    pair<pair<long long, long long>, pair<long long, bool> > u = qq[bg].first;
    long long dis = qq[bg++].second;
    if (u.first.first < 0 || u.first.second < 0 || u.first.first >= n ||
        u.first.second >= m || dis < 0 ||
        c[u.first.first][u.first.second] == '#' ||
        vis[u.first.first][u.first.second])
      continue;
    vis[u.first.first][u.first.second] = true;
    add(u.second.second ? u.first.first * m + u.first.second + n * m : p,
        u.second.second ? p : u.first.first * m + u.first.second, 0, 1);
    u.first.first++;
    qq[ed++] = {u, dis - u.second.first};
    u.first.first -= 2;
    qq[ed++] = {u, dis - u.second.first};
    u.first.first++;
    u.first.second++;
    qq[ed++] = {u, dis - u.second.first};
    u.first.second -= 2;
    qq[ed++] = {u, dis - u.second.first};
    u.first.second++;
  }
}
int main() {
  n = in(), m = in(), ml = in(), fml = in();
  if (abs(ml - fml) - 1) return out(-1), 0;
  for (int i = 0; i < n; i++, getchar())
    for (int j = 0; j < m; j++) c[i][j] = getchar();
  int r = in(), c = in(), t = in();
  if (fml < ml)
    v.push_back({{r - 1, c - 1}, {t, 0}});
  else
    v.push_back({{r - 1, c - 1}, {t, 1}});
  for (long long i = 0; i < ml; i++) {
    r = in();
    c = in();
    t = in();
    v.push_back({{r - 1, c - 1}, {t, 1}});
  }
  for (long long i = 0; i < fml; i++) {
    r = in();
    c = in();
    t = in();
    v.push_back({{r - 1, c - 1}, {t, 0}});
  }
  long long lr = -1, rr = 5e11;
  while (rr - lr > 1) {
    ecnt = 0;
    memset(head, -1, sizeof(head));
    for (int i = 0; i < n * m; i++) add(i, i + n * m, 0, 1);
    long long mid = (lr + rr) / 2;
    for (long long i = 0; i < v.size(); i++) {
      for (int i = 0; i < 33; i++)
        for (int j = 0; j < 33; j++) vis[i][j] = false;
      okbfs(v[i], 2 * n * m + i, mid);
      add(v[i].second.second ? src : 2 * n * m + i,
          v[i].second.second ? 2 * n * m + i : snk, 1, 0);
    }
    if (flw() - (ml + fml + 1) / 2)
      lr = mid;
    else
      rr = mid;
  }
  if (rr == 5e11)
    out(-1);
  else
    out(rr);
  return 0;
}
