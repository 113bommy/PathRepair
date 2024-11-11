#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000;
long long n, m, p;
long long top, head[60], to[7000], nxt[7000], c[7000], l[7000];
void addedge(long long u, long long v, long long cap, long long len) {
  to[top] = v, nxt[top] = head[u], c[top] = cap, l[top] = len, head[u] = top++;
}
vector<pair<long long, long long>> paths;
long long dis[60], fa[60];
bool inque[60];
bool go() {
  long long source = 0, target = n - 1;
  for (long long i = 0; i < n; ++i) {
    dis[i] = INF;
  }
  dis[source] = 0;
  inque[source] = true;
  queue<long long> q;
  q.push(source);
  while (q.size()) {
    long long u = q.front();
    inque[u] = false;
    q.pop();
    for (long long i = head[u]; ~i; i = nxt[i]) {
      if (c[i]) {
        long long v = to[i];
        long long nd = dis[u] + l[i];
        if (dis[v] > nd) {
          dis[v] = nd;
          fa[v] = i;
          if (!inque[v]) {
            inque[v] = true;
            q.push(v);
          }
        }
      }
    }
  }
  if (dis[target] == INF) {
    return false;
  }
  long long f = INF;
  long long u = target;
  while (u != source) {
    long long e = fa[u];
    f = min(f, c[e]);
    u = to[e ^ 1];
  }
  paths.push_back(make_pair(f, dis[target]));
  u = target;
  while (u != source) {
    long long e = fa[u];
    c[e] -= f, c[e ^ 1] += f;
    u = to[e ^ 1];
  }
  return true;
}
long long C[1000000];
long long F[1000000];
pair<long long, long long> Q[1000000];
double ret[1000000];
int main() {
  scanf("%lld%lld", &n, &m);
  top = 0;
  memset(head, -1, sizeof(head));
  for (long long i = 0; i < m; ++i) {
    long long u, v, d;
    scanf("%lld%lld%lld", &u, &v, &d);
    addedge(u - 1, v - 1, 1, d);
    addedge(v - 1, u - 1, 0, -d);
  }
  while (1) {
    if (!go()) break;
  }
  long long q;
  scanf("%d", &q);
  for (long long i = 0; i < (long long)paths.size(); ++i) {
    C[i] = paths[i].first * paths[i].second;
    if (i) C[i] += C[i - 1];
    F[i] = paths[i].first;
    if (i) F[i] += F[i - 1];
  }
  long long cur = 0;
  for (long long i = 0; i < q; ++i) {
    scanf("%lld", &Q[i].first);
    Q[i].second = i;
  }
  sort(Q, Q + q);
  for (long long i = 0; i < q; ++i) {
    while (cur < paths.size()) {
      double ans = (double)(Q[i].first + C[cur]) / (double)F[cur];
      if (cur + 1 == paths.size() || ans < paths[cur + 1].second) {
        ret[Q[i].second] = ans;
        break;
      }
      cur++;
    }
  }
  for (long long i = 0; i < q; ++i) {
    printf("%.8f", ret[i]);
  }
  return 0;
}
