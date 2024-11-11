#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
};
point p[2530];
bool cmp(point a, point b) { return a.x + a.y < b.x + b.y; }
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  int num = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < m; j++) {
      p[num].x = i;
      p[num].y = j;
      num++;
    }
  sort(p, p + num, cmp);
  int ans = 0;
  for (int i = k - 1; i >= 0; i--) {
    ans += p[i].x + p[i].y - 1;
  }
  printf("%d\n", ans);
  for (int i = k - 1; i >= 0; i--) {
    for (int a = 1; a <= p[i].x; a++) printf("(%d,1) ", a);
    for (int a = 2; a <= p[i].y; a++) printf("(%d,%d) ", p[i].x, a);
    printf("\n");
  }
  return 0;
}
