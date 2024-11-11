#include <bits/stdc++.h>
using namespace std;
const int N = 8;
const int M = 100010;
const int INF = 1 << 30;
int n, q;
double tot;
map<int, int> sum, val;
void init() {
  sum.clear();
  val.clear();
}
void add(int p, int v) {
  if (val.find(p) == val.end()) val[p] = 0;
  val[p] += v;
  while (p) {
    if (sum.find(p) == sum.end()) sum[p] = 0;
    sum[p] += v;
    p /= 2;
  }
}
void dfs(int h, int u, double Max) {
  if (h == n) {
    if (val.find(u) == val.end())
      tot += Max;
    else
      tot += max(Max, (double)val[u]);
    return;
  }
  int l = u * 2, r = u * 2 + 1;
  double L = sum[u] - sum[r];
  double R = sum[u] - sum[l];
  if (R >= sum[l]) {
    double tmp = max(Max, R);
    tot += tmp * (1 << (n - h - 1));
    if (L < sum[r]) dfs(h + 1, r, max(Max, L));
  }
  if (L >= sum[r]) {
    double tmp = max(Max, L);
    tot += tmp * (1 << (n - h - 1));
    if (R < sum[l]) dfs(h + 1, l, max(Max, R));
  }
}
void solve() {
  char qry[3];
  while (q--) {
    scanf("%s", &qry);
    if (qry[0] == 'a') {
      int p, v;
      scanf("%d %d", &p, &v);
      add(p, v);
    } else {
      tot = 0;
      dfs(0, 1, 0);
      double res = (double)tot / (1 << n);
      printf("%.10lf\n", res);
    }
  }
}
int main() {
  while (cin >> n >> q) {
    init();
    solve();
  }
}
