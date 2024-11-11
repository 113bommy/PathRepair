#include <bits/stdc++.h>
const double pi = acos(-1.0);
using namespace std;
const int maxn = 110;
struct data {
  int v, index;
};
vector<data> e[maxn];
bool vis[maxn];
void dfs(int u, double pretime) {
  int d = e[u].size();
  double delta = 2 / (d * 1.0);
  double nowtime = pretime + delta;
  vis[u] = 1;
  for (int i = 0; i < d; i++) {
    if (vis[e[u][i].v]) continue;
    while (nowtime >= 2) nowtime -= 2;
    if (nowtime < 1) {
      printf("1 %d %d %d %f\n", e[u][i].index, e[u][i].v, u, nowtime);
    } else {
      printf("1 %d %d %d %f\n", e[u][i].index, u, e[u][i].v, nowtime - 1);
    }
    dfs(e[u][i].v, nowtime);
    nowtime += delta;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back({v, i});
    e[v].push_back({u, i});
  }
  printf("%d\n", n - 1);
  dfs(1, 0.0);
  return 0;
}
