#include <bits/stdc++.h>
using namespace std;
const int N = 55, M = N * N;
int n, m;
struct edge {
  int ed, v, c, ne;
} e[M << 1];
int he[N], en = 1;
queue<int> q;
vector<pair<long long, long long> > ss;
long long dis[N];
int path[N];
bool vis[N];
void ins(int a, int b, double c, double d) {
  e[++en].ed = b;
  e[en].v = d;
  e[en].c = c;
  e[en].ne = he[a];
  he[a] = en;
}
bool spfa() {
  int u, v, i;
  memset(dis, 0xff, sizeof dis);
  memset(vis, 0, sizeof vis);
  dis[1] = 0;
  q.push(1);
  while (!q.empty()) {
    u = q.front();
    q.pop();
    vis[u] = 0;
    for (i = he[u]; i; i = e[i].ne) {
      v = e[i].ed;
      if ((e[i].c > 0) && (dis[u] + e[i].v < dis[v] || dis[v] == -1)) {
        dis[v] = dis[u] + e[i].v;
        path[v] = i;
        if (!vis[v]) {
          vis[v] = 1;
          q.push(v);
        }
      }
    }
  }
  if (dis[n] > -1)
    return 1;
  else
    return 0;
}
int main() {
  int i, x, y, z, Q;
  long long totflow = 0, totcost = 0, ex;
  double ans;
  vector<pair<long long, long long> >::iterator t, p;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; ++i) {
    scanf("%d%d%d", &x, &y, &z);
    ins(x, y, 1, z);
    ins(y, x, 0, -z);
  }
  while (spfa()) {
    y = 100000;
    for (x = n; x != 1; x = e[path[x] ^ 1].ed) y = min(y, e[path[x]].c);
    for (x = n; x != 1; x = e[path[x] ^ 1].ed) {
      e[path[x]].c -= y;
      e[path[x] ^ 1].c += y;
    }
    ss.push_back(
        (pair<long long, long long>){1ll * totflow * dis[n] - totcost, dis[n]});
    totflow += y;
    totcost += (long long)y * dis[n];
  }
  scanf("%d", &Q);
  while (Q--) {
    scanf("%lld", &ex);
    t = lower_bound(ss.begin(), ss.end(),
                    (pair<long long, long long>){ex, 10000000000ll});
    t--;
    totcost = (*t).second * (t - ss.begin() + 1) - (*t).first;
    ans = (totcost + ex + 0.) / (t - ss.begin() + 1.);
    printf("%.8lf\n", ans);
  }
  return 0;
}
