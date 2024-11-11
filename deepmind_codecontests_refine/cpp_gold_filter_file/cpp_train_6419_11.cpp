#include <bits/stdc++.h>
using namespace std;
long long n, m, s, t, md[2000], c[2000], d[1100][1100];
long long vi[1100][1100], ad[2000], v1[2000];
vector<pair<long long, long long> > e[2000], E[2000];
void spfa(long long x) {
  d[x][x] = 0;
  vi[x][x] = 1;
  queue<long long> q;
  q.push(x);
  while (!q.empty()) {
    long long u;
    u = q.front();
    q.pop();
    vi[x][u] = 0;
    for (long long i = 0; i < e[u].size(); i++) {
      long long v, w;
      v = e[u][i].first;
      w = e[u][i].second;
      if (d[x][v] > d[x][u] + w) {
        d[x][v] = d[x][u] + w;
        if (!vi[x][v]) {
          vi[x][v] = 1;
          q.push(v);
        }
      }
    }
  }
}
int main() {
  scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
  for (long long i = 1; i <= m; i++) {
    long long u, v, w;
    scanf("%lld%lld%lld", &u, &v, &w);
    e[u].push_back(make_pair(v, w));
    e[v].push_back(make_pair(u, w));
  }
  for (long long i = 1; i <= n; i++) scanf("%lld%lld", &md[i], &c[i]);
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= n; j++) d[i][j] = 1e18;
  for (long long i = 1; i <= n; i++) spfa(i);
  for (long long i = 1; i < n; i++) {
    for (long long j = i + 1; j <= n; j++) {
      if (md[i] >= d[i][j]) E[i].push_back(make_pair(j, c[i]));
      if (md[j] >= d[i][j]) E[j].push_back(make_pair(i, c[j]));
    }
  }
  queue<long long> q;
  v1[s] = 1;
  for (long long i = 1; i <= n; i++) ad[i] = 1e18;
  ad[s] = 0;
  q.push(s);
  while (!q.empty()) {
    long long u;
    u = q.front();
    q.pop();
    v1[u] = 0;
    for (long long i = 0; i < E[u].size(); i++) {
      long long v, w;
      v = E[u][i].first;
      w = E[u][i].second;
      if (ad[v] > ad[u] + w) {
        ad[v] = ad[u] + w;
        if (!v1[v]) {
          v1[v] = 1;
          q.push(v);
        }
      }
    }
  }
  if (ad[t] == 1e18)
    printf("-1\n");
  else
    printf("%lld\n", ad[t]);
}
