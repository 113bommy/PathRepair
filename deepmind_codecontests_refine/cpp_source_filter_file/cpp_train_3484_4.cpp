#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
const long long M = 2e5 + 5;
const long long inf = 1e9;
long long head[N], nt[M], to[M], w[M], tot;
long long d[N];
long long st, ed;
long long maxflow;
vector<pair<long long, long long> > fac[105];
long long idx;
long long id[105];
long long a[105];
long long n, m;
void add(long long x, long long y, long long z) {
  tot++;
  nt[tot] = head[x];
  head[x] = tot;
  to[tot] = y;
  w[tot] = z;
}
bool bfs() {
  queue<long long> q;
  q.push(st);
  for (long long i = 1; i <= idx; i++) d[i] = 0;
  d[st] = 1;
  while (!q.empty()) {
    long long x = q.front();
    q.pop();
    for (long long i = head[x]; i; i = nt[i]) {
      long long v = to[i];
      if (w[i] && !d[v]) {
        d[v] = d[x] + 1;
        q.push(v);
        if (v == ed) return 1;
      }
    }
  }
  return d[ed] != 0;
}
long long dfs(long long x, long long flow) {
  if (x == ed) return flow;
  long long res = flow;
  for (long long i = head[x]; i; i = nt[i]) {
    long long v = to[i];
    if (w[i] && d[v] == d[x] + 1) {
      long long k = dfs(v, min(res, w[i]));
      w[i] -= k;
      w[i ^ 1] += k;
      res -= k;
      if (!k) d[v] = -1;
      if (!res) break;
    }
  }
  return flow - res;
}
void dinic() {
  while (bfs()) {
    maxflow += dfs(st, inf);
  }
}
signed main() {
  cin >> n >> m;
  st = ++idx, ed = ++idx;
  for (long long i = 1; i <= n; i++) {
    id[i] = ++idx;
    if (i % 2 == 0) {
      add(st, id[i], inf);
      add(id[i], st, 0);
    } else {
      add(id[i], ed, inf);
      add(ed, id[i], 0);
    }
  }
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    long long x = a[i];
    for (long long j = 2; j * j <= x; j++) {
      if (x % j == 0) {
        long long cnt = 0;
        while (x % j == 0) x /= j, cnt++;
        fac[i].push_back({j, ++idx});
        if (i % 2 == 0) {
          add(id[i], idx, cnt);
          add(idx, id[i], 0);
        } else {
          add(idx, id[i], cnt);
          add(id[i], idx, 0);
        }
      }
    }
    if (x > 1) {
      fac[i].push_back({x, ++idx});
      if (i % 2 == 0) {
        add(id[i], idx, 1);
        add(idx, id[i], 0);
      } else {
        add(idx, id[i], 1);
        add(id[i], idx, 0);
      }
    }
  }
  for (long long i = 1; i <= m; i++) {
    long long a, b;
    cin >> a >> b;
    if (a % 2) swap(a, b);
    long long l = 0, r = 0;
    while (l < fac[a].size() && r < fac[b].size()) {
      long long v1 = fac[a][l].first;
      long long v2 = fac[b][r].first;
      long long id1 = fac[a][l].second;
      long long id2 = fac[b][r].second;
      if (v1 == v2) {
        add(id1, id2, inf);
        add(id2, id1, 0);
        l++, r++;
      } else if (v1 > v2) {
        r++;
      } else if (v1 < v2) {
        l++;
      }
    }
  }
  dinic();
  cout << maxflow << endl;
  return 0;
}
