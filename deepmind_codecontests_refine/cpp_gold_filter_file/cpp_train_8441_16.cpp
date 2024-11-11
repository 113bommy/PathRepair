#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x, y;
} a[20010];
double v[20010];
int main() {
  int n;
  long long ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", &a[i].x, &a[i].y);
  for (int i = 0; i < n; i++) {
    int cnt = 0, k = 0;
    for (int j = 0; j < n; j++)
      if (i != j) v[cnt++] = (atan2(a[j].y - a[i].y, a[j].x - a[i].x));
    sort(v, v + cnt);
    for (int j = 0; j < cnt && v[j] <= 1e-10; j++) {
      while (k < cnt && v[k] < v[j] + 3.141592653589793) k++;
      ans += (long long)(k - j - 1) * (k - j - 2) * (cnt - k + j) *
             (cnt - k + j - 1) / 2;
    }
  }
  printf("%lld\n", ans / 2);
}
