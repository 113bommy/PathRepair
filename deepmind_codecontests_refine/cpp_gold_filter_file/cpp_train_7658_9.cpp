#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
struct Edge {
  int x, y, w, p, w2;
  Edge(int X = 0, int Y = 0, int W = 0, int P = 0) : x(X), y(Y), w(W), p(P) {
    w2 = W;
  }
} e[N];
int n, x, y, w, p;
vector<int> v[N];
long long mx[N], mi[N];
bool pd;
void dfs(int x) {
  int t;
  for (int i = 0; i < v[x].size(); i++) {
    dfs(t = e[v[x][i]].y);
    if (mi[t] > e[v[x][i]].p) pd = false;
    mi[x] += mi[t] + max(1ll, e[v[x][i]].w - (e[v[x][i]].p - mi[t]));
    mx[x] += e[v[x][i]].w + min((long long)e[v[x][i]].p, mx[t]);
  }
}
void dfs2(int x, long long W) {
  int t;
  long long tmp = W;
  for (int i = 0; i < v[x].size(); i++) {
    t = e[v[x][i]].y;
    tmp -= mi[t] + max(1ll, e[v[x][i]].w - (e[v[x][i]].p - mi[t]));
  }
  long long tmp3;
  for (int i = 0; i < v[x].size(); i++) {
    t = e[v[x][i]].y;
    tmp3 = e[v[x][i]].w + min((long long)e[v[x][i]].p, mx[t]) -
           (mi[t] + max(1ll, e[v[x][i]].w - (e[v[x][i]].p - mi[t])));
    if (tmp3 >= tmp) {
      tmp3 = tmp;
      tmp = 0;
    } else {
      tmp -= tmp3;
    }
    long long tmp4 =
        mi[t] + max(1ll, e[v[x][i]].w - (e[v[x][i]].p - mi[t])) + tmp3;
    if (tmp4 - e[v[x][i]].w < mi[t]) {
      e[v[x][i]].w2 = tmp4 - mi[t];
      dfs2(t, mi[t]);
    } else {
      dfs2(t, tmp4 - e[v[x][i]].w);
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d%d%d%d", &x, &y, &w, &p);
    e[i] = Edge(x, y, w, p);
    v[x].push_back(i);
  }
  pd = true;
  dfs(1);
  if (pd) {
    dfs2(1, mx[1]);
    printf("%d\n", n);
    for (int i = 0; i < n - 1; i++) {
      printf("%d %d %d %d\n", e[i].x, e[i].y, e[i].w2,
             e[i].p - e[i].w + e[i].w2);
    }
  } else
    puts("-1");
  return 0;
}
