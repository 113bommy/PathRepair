#include <bits/stdc++.h>
using namespace std;
int cal(int x1, int y1, int x2, int y2, int x3, int y3) {
  int d1 = x2 - x1, d2 = y2 - y1;
  int t1 = x3 - x1, t2 = y3 - y1;
  int ans = 0;
  if (d1 * t1 >= 0)
    ans += max(abs(d1), abs(t1));
  else
    ans += abs(d1) + abs(t1);
  if (d2 * t2 >= 0)
    ans += max(abs(d2), abs(t2));
  else
    ans += abs(d2) + abs(t2);
  return ans + 1;
}
void work(int x1, int y1, int x2, int y2) {
  while (x1 != x2) {
    int k = (x2 - x1) / abs(x2 - x1);
    x1 += k;
    printf("%d %d\n", x1, y1);
  }
  while (y1 != y2) {
    int k = (y2 - y1) / abs(y2 - y1);
    y1 += k;
    printf("%d %d\n", x1, y1);
  }
}
void print(int x1, int y1, int x2, int y2, int x3, int y3) {
  int d1 = x2 - x1, d2 = y2 - y1;
  int t1 = x3 - x1, t2 = y3 - y1;
  printf("%d %d\n", x1, y1);
  if (d1 * t1 >= 0) {
    work(x1, y1, x1 + (abs(d1) < abs(t1) ? d1 : t1), y1);
    x1 += abs(d1) < abs(t1) ? d1 : t1;
  }
  if (d2 * t2 >= 0) {
    work(x1, y1, x1, y1 + (abs(d2) < abs(t2) ? d2 : t2));
    y1 += abs(d2) < abs(t2) ? d2 : t2;
  }
  work(x1, y1, x2, y2);
  work(x1, y1, x3, y3);
}
int main() {
  int x1, y1, x2, y2, x3, y3;
  scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
  int ans[4];
  ans[1] = cal(x1, y1, x2, y2, x3, y3);
  ans[2] = cal(x2, y2, x1, y1, x3, y3);
  ans[3] = cal(x3, y3, x1, y1, x2, y2);
  printf("%d\n", max(ans[1], max(ans[2], ans[3])));
  if (ans[1] <= ans[2] && ans[1] <= ans[3])
    print(x1, y1, x2, y2, x3, y3);
  else if (ans[2] <= ans[1] && ans[2] <= ans[3])
    print(x2, y2, x1, y1, x3, y3);
  else
    print(x3, y3, x1, y1, x2, y2);
  return 0;
}
