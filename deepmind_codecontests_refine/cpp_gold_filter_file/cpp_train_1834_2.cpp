#include <bits/stdc++.h>
using namespace std;
const int Max_N = 1e5, Max_Q = 2e2;
int n, m, Askq, Num, Mx, lin[Max_N + 5], f[Max_N + 5];
long long dis[Max_N + 5];
queue<int> q[Max_N + 5];
struct kk {
  int u, v, w;
} E[Max_N + 5];
struct KK {
  int Id, Next, v;
} e[Max_N * 2 + 5];
priority_queue<pair<long long, int> > Q;
inline void Insert(int x, int y, int z) {
  e[++Num] = {y, lin[x], z};
  lin[x] = Num;
}
inline void Dijkstra() {
  memset(dis, 30, sizeof(dis));
  dis[1] = 0;
  Q.push(make_pair(0, 1));
  for (; Q.size();) {
    int x = Q.top().second;
    Q.pop();
    for (int i = lin[x]; i; i = e[i].Next)
      if (dis[x] + e[i].v < dis[e[i].Id]) {
        dis[e[i].Id] = dis[x] + e[i].v;
        Q.push(make_pair(-dis[e[i].Id], e[i].Id));
      }
  }
}
inline void Updata(int Max) {
  memset(f, 10, sizeof(f));
  Mx = 0;
  f[1] = 0;
  q[0].push(1);
  for (int i = 0; i <= Mx; i++) {
    for (; q[i].size();) {
      int x = q[i].front();
      q[i].pop();
      if (f[x] != i) continue;
      for (int j = lin[x]; j; j = e[j].Next)
        if (dis[x] + i + e[j].v - dis[e[j].Id] < f[e[j].Id]) {
          f[e[j].Id] = dis[x] + i + e[j].v - dis[e[j].Id];
          if (f[e[j].Id] > Max) continue;
          q[f[e[j].Id]].push(e[j].Id);
          Mx = max(Mx, f[e[j].Id]);
        }
    }
  }
  for (int i = 1; i <= n; i++) dis[i] = min(dis[0], dis[i] + f[i]);
}
int main() {
  scanf("%d%d%d", &n, &m, &Askq);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].w);
    Insert(E[i].u, E[i].v, E[i].w);
  }
  Dijkstra();
  for (int i = 1; i <= n; i++) q[0].push(i);
  for (; Askq--;) {
    int opt;
    scanf("%d", &opt);
    if (opt == 1) {
      int x;
      scanf("%d", &x);
      printf("%lld\n", dis[x] == dis[0] ? -1 : dis[x]);
    } else {
      int k;
      scanf("%d", &k);
      for (int i = 1; i <= k; i++) {
        int x;
        scanf("%d", &x);
        ++e[x].v;
      }
      Updata(min(n - 1, k));
    }
  }
  return 0;
}
