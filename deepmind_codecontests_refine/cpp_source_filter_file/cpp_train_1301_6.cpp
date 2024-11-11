#include <bits/stdc++.h>
using namespace std;
struct node {
  int a;
  int b;
};
node skill[100010];
int cmp(node n1, node n2) { return n1.b < n2.b; }
int main() {
  int n, k, i, t, sum;
  while (scanf("%d%d", &n, &k) != EOF) {
    for (i = 1; i <= n; i++) {
      scanf("%d", &t);
      skill[i].a = t;
      skill[i].b = (10 - (t % 10)) % 10;
    }
    sort(skill + 1, skill + n + 1, cmp);
    for (i = 1; i <= n; i++) {
      skill[i].a += min(skill[i].b, k);
      k -= skill[i].b;
      if (k <= 0) break;
    }
    sum = 0;
    for (i = 1; i <= n; i++) {
      sum += (skill[i].a / 10);
    }
    if (k > 0) {
      sum += k / 10;
    }
    printf("%d\n", min(sum, 100 * n));
  }
  return 0;
}
