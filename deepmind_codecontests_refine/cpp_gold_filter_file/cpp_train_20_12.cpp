#include <bits/stdc++.h>
using namespace std;
const int M = 200005;
int n, m, w[M];
long long ans, c[M][2];
struct node {
  int x, v;
} p[M];
bool cmp(node a, node b) { return a.x < b.x; }
long long query(int x, int t) {
  long long r = 0;
  for (int i = x; i; i -= i & -i) r += c[i][t];
  return r;
}
void upd(int x, int y) {
  for (int i = x; i <= m; i += i & -i) c[i][0]++, c[i][1] += y;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i].x);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i].v);
    w[i] = p[i].v;
  }
  sort(p + 1, p + 1 + n, cmp);
  sort(w + 1, w + 1 + n);
  m = unique(w + 1, w + 1 + n) - (w + 1);
  for (int i = 1; i <= n; i++) {
    int a = lower_bound(w + 1, w + 1 + m, p[i].v) - w;
    ans += query(a, 0) * p[i].x - query(a, 1);
    upd(a, p[i].x);
  }
  printf("%lld", ans);
  return 0;
}
