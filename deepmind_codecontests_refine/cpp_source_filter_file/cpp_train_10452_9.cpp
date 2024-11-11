#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const int MAXN = 100005;
struct Node {
  int a, b, id;
} node[MAXN], nd;
bool cmp1(const Node& x, const Node& y) {
  if (x.b == y.b) return x.a < y.a;
  return x.b > y.b;
}
bool cmp2(const Node& x, const Node& y) {
  if (x.a == y.a) return x.b > y.b;
  return x.a > y.a;
}
int main() {
  int n, p, k;
  while (scanf("%d%d%d", &n, &p, &k) != EOF) {
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &node[i].a, &node[i].b);
      node[i].id = i + 1;
    }
    sort(node, node + n, cmp1);
    sort(node, node + n - p + k, cmp2);
    sort(node + k, node + n, cmp1);
    int mb, ma, t;
    for (int i = 0; i < k; i++)
      if (mb > node[i].b || i == 0) mb = node[i].b, ma = node[i].a;
    for (t = k; t < n; t++)
      if (mb > node[t].b || (mb == node[t].b && node[t].a > ma)) break;
    for (int i = 0; i < k; i++) printf("%d ", node[i].id);
    for (int i = 0; i < p - k; i++) printf("%d ", node[i + t].id);
    printf("\n");
  }
  return 0;
}
