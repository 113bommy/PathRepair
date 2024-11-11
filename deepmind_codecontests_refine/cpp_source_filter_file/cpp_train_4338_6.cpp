#include <bits/stdc++.h>
using namespace std;
const int INF = 2 * 1e8 + 10;
int li[100005], ei[100005];
int main() {
  int n, m, cl, ce, v, q, x1, y1, x2, y2, tim = INF;
  scanf("%d%d%d%d%d", &n, &m, &cl, &ce, &v);
  for (int i = 0; i < cl; i++) scanf("%d", &li[i]);
  for (int i = 0; i < ce; i++) scanf("%d", &ei[i]);
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    tim = INF;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if (x1 == x2)
      printf("%d\n", abs(y1 - y2));
    else {
      int posl = lower_bound(li, li + cl, y1) - li;
      if (posl != cl)
        tim = min(tim, abs(y1 - li[posl]) + abs(x1 - x2) + abs(y2 - li[posl]));
      if (posl != 0)
        tim = min(tim, abs(y1 - li[posl - 1]) + abs(x1 - x2) +
                           abs(y2 - li[posl - 1]));
      int pose = lower_bound(ei, ei + ce, y2) - ei;
      if (pose != ce) {
        if (abs(x1 - x2) < v)
          tim = min(tim, abs(y1 - ei[pose]) + 1 + abs(y2 - ei[pose]));
        else if (abs(x1 - x2) % v == 0)
          tim = min(tim,
                    abs(y1 - ei[pose]) + abs(x1 - x2) / v + abs(y2 - ei[pose]));
        else
          tim = min(tim, abs(y1 - ei[pose]) + abs(x1 - x2) / v + 1 +
                             abs(y2 - ei[pose]));
      }
      if (pose != 0) {
        if (abs(x1 - x2) < v)
          tim = min(tim, abs(y1 - ei[pose - 1]) + 1 + abs(y2 - ei[pose - 1]));
        else if (abs(x1 - x2) % v == 0)
          tim = min(tim, abs(y1 - ei[pose - 1]) + abs(x1 - x2) / v +
                             abs(y2 - ei[pose - 1]));
        else
          tim = min(tim, abs(y1 - ei[pose - 1]) + abs(x1 - x2) / v + 1 +
                             abs(y2 - ei[pose - 1]));
      }
      printf("%d\n", tim);
    }
  }
  return 0;
}
