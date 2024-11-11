#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const int M = 1e5 + 5;
const double INF = 1e9;
int n, m, k, f[N];
vector<int> ans;
struct Edge {
  int x, y, o;
  double w;
  void init(int i) {
    scanf("%d%d%lf", &x, &y, &w);
    o = i;
    x--, y--;
    if (x > y) swap(x, y);
  }
  bool operator<(const Edge& b) const { return w < b.w; }
} a[M], b[M];
bool cmp(Edge a, Edge b) { return a.o < b.o; }
int gf(int x) { return x == f[x] ? x : f[x] = gf(f[x]); }
int getK(double val) {
  int fx, fy, ret = 0;
  for (int i = 0; i < m; i++) {
    b[i] = a[i];
    if (!b[i].x) b[i].w += val;
  }
  sort(b, b + m);
  ans.clear();
  for (int i = 0; i < n; i++) f[i] = i;
  for (int i = 0; i < m; i++) {
    fx = gf(b[i].x);
    fy = gf(b[i].y);
    if (fx == fy) continue;
    if (!b[i].x) ret++;
    ans.push_back(b[i].o);
    f[fx] = fy;
  }
  return ret;
}
bool check(double l, double r) {
  double mid;
  for (int i = 0; i < 100; i++) {
    mid = (l + r) / 2;
    int tmp = getK(mid);
    if (tmp < k) r = mid;
    if (tmp == k) {
      if (ans.size() != n - 1) return 0;
      printf("%d\n", ans.size());
      for (int i = 0; i < ans.size(); i++) {
        if (i) printf(" ");
        printf("%d", ans[i] + 1);
      }
      puts("");
      return 1;
    }
    if (tmp > k) l = mid;
  }
  return 1;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; i++) a[i].init(i);
  if (!check(-INF, INF) || ans.size() != n - 1) puts("-1");
  return 0;
}
