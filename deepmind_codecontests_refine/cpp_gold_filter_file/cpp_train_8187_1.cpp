#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const long long N = 20000;
long long n, m, s, t;
vector<pair<long long, long long> > nei[N + 1];
vector<long long> rv[N + 1];
vector<long long> id[N + 1];
void ae(long long x, long long y, long long z, long long i) {
  nei[x].push_back(make_pair(y, z)), nei[y].push_back(make_pair(x, 0));
  rv[x].push_back(nei[y].size() - 1), rv[y].push_back(nei[x].size() - 1);
  id[x].push_back(i), id[y].push_back(i);
}
long long dep[N + 1];
bool bfs() {
  memset(dep, -1, sizeof(dep));
  dep[s] = 0;
  queue<long long> q;
  q.push(s);
  while (q.size()) {
    long long x = q.front();
    q.pop();
    for (long long i = 0; i < nei[x].size(); i++) {
      long long y = nei[x][i].first, c = nei[x][i].second;
      if (c && !~dep[y]) dep[y] = dep[x] + 1, q.push(y);
    }
  }
  return ~dep[t];
}
long long now[N + 1];
long long dfs(long long x = s, long long flw = inf) {
  if (x == t || !flw) return flw;
  long long res = 0, tmp;
  for (long long &i = now[x]; i < nei[x].size(); i++) {
    long long y = nei[x][i].first, &c = nei[x][i].second;
    if (dep[y] == dep[x] + 1 && (tmp = dfs(y, min(flw, c)))) {
      res += tmp, flw -= tmp;
      c -= tmp, nei[y][rv[x][i]].second += tmp;
      if (!flw) break;
    }
  }
  return res;
}
long long dinic() {
  long long res = 0;
  while (bfs()) {
    memset(now, 0, sizeof(now));
    res += dfs();
  }
  return res;
}
long long deg[N + 1];
signed main() {
  long long n0;
  cin >> n >> n0 >> m;
  s = n + n0 + 1, t = s + 1;
  for (long long i = 1; i <= m; i++) {
    long long x, y;
    cin >> x >> y;
    ae(x, y + n, 1, i);
    deg[x]++, deg[y + n]++;
  }
  for (long long i = 1; i <= n; i++) ae(s, i, 0, 0);
  for (long long i = 1; i <= n0; i++) ae(i + n, t, 0, 0);
  long long mndeg = inf;
  for (long long i = 1; i <= n + n0; i++) mndeg = min(mndeg, deg[i]);
  puts("0");
  long long now = 0;
  for (long long i = 1; i <= mndeg; i++) {
    for (long long j = 0; j < nei[s].size(); j++) nei[s][j].second++;
    for (long long j = 0; j < nei[t].size(); j++)
      nei[nei[t][j].first][rv[t][j]].second++;
    cout << i * (n + n0) - (now += dinic()) << " ";
    for (long long j = 1; j <= n; j++) {
      vector<pair<long long, long long> > v;
      for (long long k = 0; k < nei[j].size(); k++)
        if (n + 1 <= nei[j][k].first && nei[j][k].first <= n + n0)
          v.push_back(make_pair(nei[j][k].second, id[j][k]));
      sort(v.begin(), v.end());
      for (long long k = 0; k < i; k++) printf("%lld ", v[k].second);
    }
    for (long long j = n + 1; j <= n + n0; j++) {
      vector<pair<long long, long long> > v;
      for (long long k = 0; k < nei[j].size(); k++)
        if (1 <= nei[j][k].first && nei[j][k].first <= n)
          v.push_back(make_pair(1 - nei[j][k].second, id[j][k]));
      sort(v.begin(), v.end());
      for (long long k = 0; k < i; k++)
        if (v[k].first == 1) printf("%lld ", v[k].second);
    }
    puts("");
  }
  return 0;
}
