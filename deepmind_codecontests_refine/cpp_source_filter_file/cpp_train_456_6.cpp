#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int a, b, L, R;
} E[3010];
struct edge {
  int v, L, R;
  edge() {}
  edge(int v, int L, int R) : v(v), L(L), R(R) {}
};
vector<edge> adj[1010];
int n, m, ans;
void read() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d %d %d", &E[i].a, &E[i].b, &E[i].L, &E[i].R);
    adj[E[i].a].push_back(edge(E[i].b, E[i].L, E[i].R));
    adj[E[i].b].push_back(edge(E[i].a, E[i].L, E[i].R));
  }
}
void work(int lim) {
  static int queue[1010], maxv[1010];
  static bool use[1010];
  memset(maxv, 0, sizeof(maxv));
  memset(use, false, sizeof(use));
  int front = 0, rear = 1;
  queue[rear] = 1, maxv[1] = 1 << 30;
  while (front < rear) {
    int p = queue[front = front % n + 1];
    use[p] = false;
    for (vector<edge>::iterator e = adj[p].begin(); e != adj[p].end(); ++e)
      if (e->R >= lim && e->L <= lim && maxv[e->v] < min(maxv[p], e->R)) {
        maxv[e->v] = min(maxv[p], e->R);
        if (use[e->v] == false) use[queue[rear = rear % n + 1] = e->v] = true;
      }
  }
  ans = max(ans, maxv[n] - lim + 1);
}
void work() {
  for (int i = 1; i <= m; ++i) work(E[i].L);
  if (ans == 0)
    printf("Nice work, Dima!\n");
  else
    printf("%d\n", ans);
}
int main() {
  read();
  work();
  return 0;
}
