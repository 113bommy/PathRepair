#include <bits/stdc++.h>
using namespace std;
struct guardpost {
  int cost1, cost2;
};
int n, a, b, c, d, num, mini = INT_MAX;
guardpost p[4];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 4; i++) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    p[i].cost1 = min(a, b);
    p[i].cost2 = min(c, d);
    if (min(a, b) + min(c, d) < mini) {
      mini = min(a, b) + min(c, d);
      num = i;
    }
  }
  if (n < p[num].cost1 + p[num].cost2)
    printf("-1");
  else {
    printf("%d %d %d ", num + 1, p[num].cost1, n - p[num].cost1);
  }
  return 0;
}
