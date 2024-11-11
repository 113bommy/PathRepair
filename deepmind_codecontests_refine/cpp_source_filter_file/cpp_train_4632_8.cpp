#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, p, x, y;
  int a[1010];
  int cnt = 0;
  scanf("%d%d%d%d%d", &n, &k, &p, &x, &y);
  int sum = 0;
  for (int i = 0; i < k; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
    if (a[i] >= y) cnt++;
  }
  int t = n - k;
  if (sum + t > x) {
    printf("-1\n");
    return 0;
  }
  int mid = (n + 1) / 2;
  if (cnt >= mid) {
    for (int i = 0; i < t; i++) {
      if (i == 0)
        printf("1");
      else
        printf(" 1\n");
    }
  } else {
    int m = x - sum;
    int last = (mid - cnt) * y + t - mid + cnt;
    if (m < last && t < (mid - cnt)) {
      printf("-1\n");
      return 0;
    } else {
      for (int i = 0; i < mid - cnt; i++) {
        if (i == 0)
          printf("%d", y);
        else
          printf(" %d", y);
      }
      for (int i = 0; i < t - (mid - cnt); i++) {
        printf(" 1");
      }
    }
  }
  return 0;
}
