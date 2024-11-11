#include <bits/stdc++.h>
using namespace std;
long long ax, ay, bx, by;
typedef struct {
  long long x, y;
} node;
long long dis(node a1, node a2) {
  return fabs(a1.x - a2.x) + fabs(a1.y - a2.y);
}
node a[64], as;
int pos = 0;
long long sum[64] = {0}, t;
long long d[64] = {0};
int ans = 0;
long long tem, anst;
int main() {
  scanf("%lld %lld %lld %lld %lld %lld", &a[0].x, &a[0].y, &ax, &ay, &bx, &by);
  scanf("%lld %lld %lld", &as.x, &as.y, &t);
  a[1].x = ax * a[0].x + bx, a[1].y = ay * a[0].y + by;
  sum[1] = sum[0] + dis(a[1], a[0]);
  for (pos = 2; a[pos - 1].x <= 10e15 && a[pos - 1].y <= 10e15; pos++) {
    a[pos].x = a[pos - 1].x * ax + bx;
    a[pos].y = a[pos - 1].y * ay + by;
    sum[pos] = sum[pos - 1] + dis(a[pos], a[pos - 1]);
  }
  for (int i = 0; i < pos; i++) d[i] = dis(as, a[i]);
  for (int i = 0; i < pos; i++) {
    if (d[i] > t) continue;
    tem = d[i];
    anst = 1;
    int j = i;
    while (j - 1 >= 0 && tem + dis(a[j], a[j - 1]) <= t) {
      anst++;
      tem += dis(a[j], a[j - 1]);
      j--;
      if (anst > ans) ans = anst;
    }
    if (j == 0 && i != 0) anst = 1;
    while (j + 1 < pos && tem + dis(a[j + 1], a[j]) <= t) {
      anst++;
      tem += dis(a[j + 1], a[j]);
      j++;
    }
    if (anst > ans) ans = anst;
  }
  cout << ans << "\n";
}
