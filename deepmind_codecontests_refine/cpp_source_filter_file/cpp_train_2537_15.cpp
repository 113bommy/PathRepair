#include <bits/stdc++.h>
using namespace std;
int i, j, k, l, n, m, s, an, sum;
const int N = 200;
class arr {
 public:
  int x, y, num;
} a[N];
bool com(const arr &o, const arr &p) { return o.x < p.x; }
int main() {
  scanf("%d%d", &n, &m);
  if (m <= 0) {
    printf("No");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].x);
    sum += a[i].x;
    a[i].num = i;
  }
  if (m > sum) {
    printf("No");
    return 0;
  }
  sort(&a[1], &a[n + 1], com);
  int y = 0;
  bool ok = false;
  if (a[1].x > m) {
    if ((n == 1) || (m == 1)) {
      printf("No");
      return 0;
    }
    printf("Yes\n");
    ok = true;
    printf("%d ", a[2].num);
    for (int i = 1; i < a[1].x; i++) printf("%d %d ", a[1].num, a[1].num);
    a[1].x = 1;
    printf("%d ", a[2].num);
    a[2].x--;
    y = 1;
  }
  if (!ok) printf("Yes\n");
  for (int i = 1; i < a[1].x; i++) {
    a[i].y = y;
    y = a[i].y + 1;
    printf("%d %d ", a[1].num, a[1].num);
  }
  for (int i = 2; i <= n; i++) {
    while (a[i].x > 0) {
      if (y == m - 1) printf("%d ", a[1].num);
      a[i].y = y;
      y = a[i].y + 1;
      a[i].x--;
      printf("%d %d ", a[i].num, a[i].num);
    }
  }
  if (y == m - 1) printf("%d ", a[1].num);
  printf("%d\n", a[1].num);
  return 0;
}
