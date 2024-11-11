#include <bits/stdc++.h>
using namespace std;
struct road {
  int x, next;
  double dis;
} r[305 * 305 * 2];
int N, M;
int st[305], w;
int vis[305];
double P[305];
double l1 = -1, r1 = 0, mid;
double dis[305];
void add(int x, int y, double dis) {
  r[++w].x = y, r[w].next = st[x];
  r[w].dis = dis;
  st[x] = w;
}
bool work(int x) {
  int i, j, tmp;
  if (vis[x]) return true;
  vis[x] = 1;
  for (i = st[x]; i; i = r[i].next) {
    tmp = r[i].x;
    if (dis[tmp] > dis[x] + r[i].dis - mid) {
      dis[tmp] = dis[x] + r[i].dis - mid;
      if (work(tmp)) return true;
    }
  }
  vis[x] = 0;
  return false;
}
int main() {
  int i, j;
  int fr, to;
  scanf("%d", &N);
  for (i = 0; i <= N; i++) scanf("%lf", &P[i]);
  M = N * 3;
  for (i = 0; i <= M; i++)
    for (j = N, fr = i; j >= -N; j -= 2) {
      to = fr + j;
      if (to > M || to < 0) continue;
      add(fr, to, -P[(N - j) / 2]);
    }
  for (i = 1; i <= 21; i++) {
    mid = (l1 + r1) / 2;
    for (j = 1; j <= 20; j++) {
      memset(dis, 63, sizeof(dis));
      memset(vis, 0, sizeof(vis));
      fr = rand() % M + 1, dis[fr] = 0;
      if (work(fr)) break;
    }
    if (j <= 9)
      r1 = mid;
    else
      l1 = mid;
  }
  printf("%.8lf\n", -mid);
  return 0;
}
