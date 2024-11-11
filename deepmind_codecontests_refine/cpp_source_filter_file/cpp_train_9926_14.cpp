#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
struct node {
  int to;
  long long val;
};
struct no {
  int x, y;
  long long val;
} bi[maxn];
struct cmp1 {
  bool operator()(const node &a, const node &b) { return a.val > b.val; }
};
bool cmp(const no &a, const no &b) { return a.val < b.val; }
int n, m, k, p[maxn], bcj[maxn], cnt, ne[maxn];
long long dist[maxn], inf;
bool cs[maxn], us[maxn];
vector<node> q[maxn];
priority_queue<node, vector<node>, cmp1> p1;
int find(int x) { return x == bcj[x] ? x : bcj[x] = find(bcj[x]); }
void dijkstra() {
  while (!p1.empty()) {
    node t = p1.top();
    p1.pop();
    int u = t.to;
    int len = q[u].size();
    for (int j = 0; j < len; j++) {
      int to = q[u][j].to;
      long long val = q[u][j].val;
      if (dist[to] > dist[u] + val) {
        dist[to] = dist[u] + val;
        ne[to] = ne[u];
        p1.push((node){to, dist[to]});
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y;
    long long v;
    scanf("%d%d%lld", &x, &y, &v);
    q[x].push_back((node){y, v});
    q[y].push_back((node){x, v});
    bi[i] = (no){x, y, v};
  }
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) {
    int x;
    scanf("%d", &x);
    p[i] = x;
    cs[x] = 1;
  }
  memset(dist, 0x3f, sizeof(dist));
  inf = dist[0];
  memset(us, 0, sizeof(us));
  memset(ne, 0, sizeof(ne));
  dist[1] = 0;
  p1.push((node){1, 0});
  dijkstra();
  while (!p1.empty()) p1.pop();
  long long ans = inf;
  for (int i = 1; i <= k; i++) ans = min(ans, dist[p[i]]);
  memset(dist, 0x3f, sizeof(dist));
  for (int i = 1; i <= k; i++) {
    p1.push((node){p[i], 0});
    dist[p[i]] = 0;
    ne[p[i]] = p[i];
  }
  dijkstra();
  for (int i = 1; i <= n; i++) bcj[i] = i;
  for (int i = 1; i <= m; i++) {
    bi[i].val += dist[bi[i].x] + dist[bi[i].y];
    bi[i].x = ne[bi[i].x], bi[i].y = ne[bi[i].y];
  }
  sort(bi + 1, bi + cnt + 1, cmp);
  int co = 0;
  for (int i = 1; i <= m; i++) {
    int x = find(bi[i].x), y = find(bi[i].y);
    if (x == y) continue;
    co++;
    ans += bi[i].val;
    bcj[x] = y;
    if (co == n - 1) break;
  }
  printf("%lld\n", ans);
  return 0;
}
