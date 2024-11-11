#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 107;
struct eT {
  void setd(int _u, int _v, int _l) { u = _u, v = _v, last = _l; }
  int u, v, last;
} edge[MAXN * 2];
int n;
int ke, la[MAXN];
void init();
void input();
void work();
void dfs(int now, int fa, double px);
int main() {
  init();
  input();
  work();
}
void init() { ios::sync_with_stdio(false); }
void input() {
  scanf("%d", &n);
  ke = 0;
  memset(la, -1, sizeof(la));
  int u, v;
  for (int i = 1; i < n; ++i) {
    scanf("%d%d", &u, &v);
    edge[ke].setd(u, v, la[u]);
    la[u] = ke++;
    edge[ke].setd(v, u, la[v]);
    la[v] = ke++;
  }
}
void work() {
  printf("%d\n", n - 1);
  dfs(1, -1, 0);
}
void dfs(int now, int fa, double px) {
  int nd = 0;
  for (int i = la[now]; ~i; i = edge[i].last) ++nd;
  int nc = 0;
  double tmp;
  for (int i = la[now]; ~i; i = edge[i].last) {
    if (edge[i].v ^ fa) {
      ++nc;
      printf("1 %d ", (i >> 1) + 1);
      tmp = 2 * (static_cast<double>(nc) / nd) + px;
      if (tmp >= 2) tmp -= 2;
      if (tmp <= 1)
        printf("%d %d %.9lf\n", now, edge[i].v, tmp);
      else
        printf("%d %d %.9lf\n", edge[i].v, now, tmp - 1);
      dfs(edge[i].v, now, tmp + 1);
    }
  }
}
