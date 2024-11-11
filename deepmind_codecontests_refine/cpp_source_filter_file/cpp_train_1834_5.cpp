#include <bits/stdc++.h>
using namespace std;
int n, m;
struct EDGE {
  int to, w;
  EDGE *las;
} e[100005];
int ne;
EDGE *last[100005];
void link(int u, int v, int w) {
  e[ne] = {v, w, last[u]};
  last[u] = e + ne++;
}
long long dis[100005], f[100005];
void adjust() {
  for (int i = 1; i <= n; ++i)
    for (EDGE *ei = last[i]; ei; ei = ei->las) ei->w += dis[i] - dis[ei->to];
  for (int i = 1; i <= n; ++i) f[i] += dis[i];
}
void SP0() {
  static priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                        greater<pair<long long, int> > >
      q;
  memset(dis, 127, sizeof(long long) * (n + 1));
  dis[1] = 0;
  q.push(make_pair(0, 1));
  while (!q.empty()) {
    int x = q.top().second;
    long long s = q.top().first;
    q.pop();
    if (s != dis[x]) continue;
    for (EDGE *ei = last[x]; ei; ei = ei->las)
      if (s + ei->w < dis[ei->to]) {
        dis[ei->to] = s + ei->w;
        q.push(make_pair(dis[ei->to], ei->to));
      }
  }
  adjust();
}
void SP1() {
  static vector<int> b[100005];
  memset(dis, 127, sizeof(long long) * (n + 1));
  dis[1] = 0;
  b[0].push_back(1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < b[i].size(); ++j) {
      int x = b[i][j];
      if (dis[x] < i) continue;
      for (EDGE *ei = last[x]; ei; ei = ei->las)
        if (i + ei->w < n && i + ei->w < dis[ei->to]) {
          dis[ei->to] = i + ei->w;
          b[dis[ei->to]].push_back(ei->to);
        }
    }
    b[i].clear();
  }
  adjust();
}
int main() {
  int Q;
  scanf("%d%d%d", &n, &m, &Q);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    link(u, v, w);
  }
  SP0();
  while (Q--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int v;
      scanf("%d", &v);
      printf("%lld\n", f[v] > 100000000000000 ? -1 : f[v]);
    } else {
      int c;
      scanf("%d", &c);
      for (int i = 0; i < c; ++i) {
        int id;
        scanf("%d", &id), --id;
        e[id].w++;
      }
      SP1();
    }
  }
  return 0;
}
