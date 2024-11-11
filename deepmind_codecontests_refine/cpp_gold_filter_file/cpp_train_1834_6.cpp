#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 55;
struct he {
  long long id, val;
  friend bool operator<(const he x, const he y) { return x.val > y.val; }
};
struct node {
  long long next, to, dis;
} a[N * 2];
long long head[N], cnt, qq;
void add(long long e, long long r, long long t) {
  a[++cnt].next = head[e];
  a[cnt].to = r;
  a[cnt].dis = t;
  head[e] = cnt;
}
long long n, m, x, y, z, dis[N], pd[N];
priority_queue<he> q;
void init() {
  memset(dis, 10, sizeof(dis));
  q.push((he){1, 0});
  dis[1] = 0;
  while (q.size()) {
    he u = q.top();
    q.pop();
    if (pd[u.id]) continue;
    pd[u.id] = 1;
    for (long long i = head[u.id]; i; i = a[i].next) {
      if (dis[a[i].to] > dis[u.id] + a[i].dis) {
        dis[a[i].to] = dis[u.id] + a[i].dis;
        q.push((he){a[i].to, dis[a[i].to]});
      }
    }
  }
}
vector<long long> v[N];
long long g[N];
void calc() {
  memset(g, 10, sizeof(g));
  v[0].push_back(1);
  g[1] = 0;
  for (long long i = 0; i <= y; i++) {
    for (long long k = 0; k < v[i].size(); k++) {
      if (g[v[i][k]] < i) continue;
      for (long long j = head[v[i][k]]; j; j = a[j].next) {
        if (g[a[j].to] > g[v[i][k]] + dis[v[i][k]] + a[j].dis - dis[a[j].to]) {
          g[a[j].to] = g[v[i][k]] + dis[v[i][k]] + a[j].dis - dis[a[j].to];
          if (g[a[j].to] <= y) {
            v[g[a[j].to]].push_back(a[j].to);
          }
        }
      }
    }
    vector<long long>().swap(v[i]);
  }
  for (long long i = 1; i <= n; i++)
    dis[i] = min((long long)1e15, g[i] + dis[i]);
}
signed main() {
  scanf("%lld%lld%lld", &n, &m, &qq);
  for (long long i = 1; i <= m; i++) {
    scanf("%lld%lld%lld", &x, &y, &z);
    add(x, y, z);
  }
  init();
  for (long long i = 1; i <= qq; i++) {
    scanf("%lld", &x);
    if (x == 1) {
      scanf("%lld", &y);
      if (dis[y] >= 1e15)
        puts("-1");
      else
        printf("%lld\n", dis[y]);
    }
    if (x == 2) {
      scanf("%lld", &y);
      for (long long k = 1; k <= y; k++) {
        scanf("%lld", &z);
        a[z].dis++;
      }
      calc();
    }
  }
  init();
  return 0;
}
