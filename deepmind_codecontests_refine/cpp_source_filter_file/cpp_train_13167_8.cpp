#include <bits/stdc++.h>
using namespace std;
const int maxn = 300005;
long long dist[300005];
struct edge {
  int y;
  int weight;
  int id;
  edge* next;
};
edge* li[300005];
edge* new_edge() {
  static edge a[1000005];
  static int top = 0;
  return &a[top++];
}
void inserts(int x, int y, int z, int w) {
  edge* t = new_edge();
  t->y = y;
  t->weight = z;
  t->id = w;
  t->next = li[x];
  li[x] = t;
}
void insert_edge(int x, int y, int z, int w) {
  inserts(x, y, z, w);
  inserts(y, x, z, w);
}
int pre[maxn];
int pre_weight[maxn];
bool visit[maxn];
void dijkstra(int s) {
  memset(visit, false, sizeof(visit));
  priority_queue<pair<long long, int> > q;
  dist[s] = 0;
  pre[s] = -1;
  q.push(make_pair(0, s));
  for (; !q.empty();) {
    int now = q.top().second;
    q.pop();
    if (visit[now]) continue;
    visit[now] = true;
    edge* t;
    for (t = li[now]; t != 0; t = t->next) {
      if (dist[t->y] > dist[now] + t->weight) {
        dist[t->y] = dist[now] + t->weight;
        pre[t->y] = t->id;
        pre_weight[t->y] = t->weight;
        q.push(make_pair(-dist[now], t->y));
      } else if (dist[t->y] == dist[now] + t->weight) {
        if (pre_weight[t->y] > t->weight) {
          pre[t->y] = t->id;
          pre_weight[t->y] = t->weight;
        }
      }
    }
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int i;
  for (i = 0; i < m; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    x--;
    y--;
    insert_edge(x, y, z, i + 1);
  }
  int t;
  scanf("%d", &t);
  t--;
  for (i = 0; i < n; i++) {
    dist[i] = 99999999999999999ll;
  }
  dijkstra(t);
  long long maxans = 0;
  for (i = 0; i < n; i++) {
    if (i != t) {
      maxans = maxans + pre_weight[i];
    }
  }
  printf("%I64d\n", maxans);
  for (i = 0; i < n; i++) {
    if (i != t) {
      printf("%d ", pre[i]);
    }
  }
  return 0;
}
