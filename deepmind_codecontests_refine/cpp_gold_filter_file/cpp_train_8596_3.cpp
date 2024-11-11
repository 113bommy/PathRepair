#include <bits/stdc++.h>
using namespace std;
struct node {
  int a, b, cha;
} q[200100];
int cmp(node a, node b) { return a.cha < b.cha; }
int main() {
  int n, k, ans;
  while (scanf("%d%d", &n, &k) != EOF) {
    int p = 0;
    ans = 0;
    for (int i = 0; i < n; i++) scanf("%d", &q[i].a);
    for (int i = 0; i < n; i++) scanf("%d", &q[i].b);
    for (int i = 0; i < n; i++) {
      if (q[i].a <= q[i].b) {
        p++;
        q[i].cha = 0;
        ans += q[i].a;
      } else
        q[i].cha = q[i].a - q[i].b;
    }
    sort(q, q + n, cmp);
    for (int i = p; i < n; i++) {
      if (i >= k)
        ans += q[i].b;
      else
        ans += q[i].a;
    }
    printf("%d\n", ans);
  }
  return 0;
}
