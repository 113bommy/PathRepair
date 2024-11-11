#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5;
struct ppp {
  int x;
  int y;
  int id;
} p[3 * MaxN + 5];
bool cmp(ppp a, ppp b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
bool cmp1(ppp a, ppp b) {
  if (a.y == b.y) return a.x < b.x;
  return a.y < b.y;
}
int main() {
  int n, ans1, ans2, ans3, ans4, vis;
  while (~scanf("%d", &n)) {
    vis = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d %d", &p[i].x, &p[i].y);
      p[i].id = i;
    }
    sort(p + 1, p + 1 + n, cmp1);
    for (int i = 2; i <= n; i++) {
      if (p[i].y == p[i - 1].y) {
        ans1 = p[i].id;
        ans2 = p[i - 1].id;
        printf("%d %d\n", ans1, ans2);
        vis = 1;
        break;
      }
    }
    if (vis == 1) continue;
    sort(p + 1, p + 1 + n, cmp);
    for (int i = 2; i <= n; i++) {
      if (p[i].x == p[i - 1].x) {
        ans1 = p[i].id;
        ans2 = p[i - 1].id;
        printf("%d %d\n", ans2, ans1);
        vis = 1;
        break;
      }
    }
    if (vis == 1) continue;
    for (int i = 2; i <= n; i++) {
      if (p[i].y <= p[i - 1].y) {
        ans1 = p[i].id;
        ans2 = p[i - 1].id;
        printf("%d %d\n", ans1, ans2);
        vis = 1;
        break;
      }
    }
    if (vis == 1) continue;
    sort(p + 1, p + 1 + n, cmp1);
    for (int i = 2; i <= n; i++) {
      if (p[i].x <= p[i - 1].x) {
        ans1 = p[i].id;
        ans2 = p[i - 1].id;
        printf("%d %d\n", ans1, ans2);
        vis = 1;
        break;
      }
    }
    if (vis == 1) continue;
    printf("-1 -1\n");
  }
  return 0;
}
