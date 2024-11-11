#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
const int INF = int(1e9);
int n, w;
int len;
int c[maxn];
double p[maxn];
double val[maxn];
struct Node {
  double t1, t2;
  bool operator<(const Node &b) const {
    return t1 == b.t1 ? t2 > b.t2 : t1 < b.t1;
  }
} node[maxn];
int ask(int x) {
  int ret = 0;
  while (x) {
    ret += c[x];
    x -= x & -x;
  }
  return ret;
}
void add(int x) {
  while (x <= len) {
    c[x]++;
    x += x & -x;
  }
}
int main() {
  scanf("%d %d", &n, &w);
  int x, v;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &x, &v);
    node[i] = (Node){(double)(v - w) / x, (double)(v + w) / x};
  }
  sort(node + 1, node + n + 1);
  for (int i = 1; i <= n; i++) p[i] = node[i].t2;
  sort(p + 1, p + 1 + n);
  len = unique(p + 1, p + n + 1) - p - 1;
  for (int i = 1; i <= n; i++) {
    val[i] = lower_bound(p + 1, p + len + 1, node[i].t2) - p;
  }
  long long ans = 0;
  for (int i = n; i >= 1; i--) {
    ans += ask(val[i]);
    add(val[i]);
  }
  printf("%lld\n", ans);
  return 0;
}
