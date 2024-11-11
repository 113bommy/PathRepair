#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
template <class T>
T gcd(T x, T y) {
  while (T t = x % y) x = y, y = t;
  return y;
}
const double eps = 1e-10;
const double PI = acos(-1.);
const int INF = 1000000000;
const int MOD = 1000000007;
const double E = 2.7182818284590452353602874713527;
bool isdig(char x) { return x >= '0' && x <= '9'; }
bool isup(char x) { return x >= 'A' && x <= 'Z'; }
bool isdown(char x) { return x >= 'a' && x <= 'z'; }
bool islet(char x) { return isup(x) || isdown(x); }
struct Edge {
  int u, v, w, next;
  bool mk;
};
Edge edge[400005];
int N, M, head[205], en;
void insert(int u, int v, int w) {
  edge[en].u = u;
  edge[en].v = v;
  edge[en].w = w;
  edge[en].mk = 0;
  edge[en].next = head[u];
  head[u] = en++;
}
int dis[205][205];
void get_data() {
  memset(head, -1, sizeof(head));
  ;
  en = 0;
  scanf("%d%d", &N, &M);
  int u, v, w;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) dis[i][j] = INF;
  for (int i = 0; i < M; i++) {
    scanf("%d%d%d", &u, &v, &w);
    u--;
    v--;
    insert(u, v, w);
    insert(v, u, w);
    dis[u][v] = dis[v][u] = min(w, dis[u][v]);
  }
}
void floyd() {
  for (int i = 0; i < N; i++) dis[i][i] = 0;
  for (int k = 0; k < N; k++)
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
int rright[205], lleft[205];
pair<double, double> vec[205];
int vn;
void _push(double s, double e) {
  if (s < e + eps) vec[vn++] = (make_pair(s, e));
}
bool vecAll(double len) {
  if (!vn) return 0;
  sort(vec, vec + vn);
  double s = vec[0].first, e = vec[0].second;
  if (s > eps) return 0;
  for (int i = 1; i <= vn - 1; i++) {
    if (vec[i].first > e + eps) {
      return 0;
    }
    e = max(e, vec[i].second);
  }
  return e + eps > len;
}
bool ok(double x, double len) {
  double l = len, r = 0, tl, tr;
  vn = 0;
  for (int i = 0; i < N; i++) {
    tl = max(0., x - lleft[i]);
    tr = min(len, len - (x - rright[i]));
    _push(tl, tr);
  }
  return !vecAll(len);
}
void run() {
  floyd();
  double res = 20000000;
  for (int i = 0; i < en; i++) {
    for (int j = 0; j < N; j++) {
      rright[j] = dis[edge[i].u][j];
      lleft[j] = dis[edge[i].v][j];
    }
    double h = res, l = 0, mid;
    int cnt = 0;
    if (!ok(h - 2 * eps, edge[i].w)) continue;
    while (cnt < 80 && h > l + eps) {
      cnt++;
      mid = (h + l) / 2;
      if (ok(mid, edge[i].w))
        h = mid;
      else
        l = mid;
    }
    res = min(res, h);
    i++;
  }
  printf("%.12lf\n", res);
}
int main() {
  get_data();
  run();
  return 0;
}
