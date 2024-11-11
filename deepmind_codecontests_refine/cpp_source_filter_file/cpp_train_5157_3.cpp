#include <bits/stdc++.h>
struct node {
  long long int x, y;
} ar[1005];
int main() {
  long long int n, ind, i, ind1, cnt;
  scanf("%lld", &n);
  cnt = 0;
  for (i = 1; i <= n + 1; i++) {
    scanf("%lld%lld", &ar[i].x, &ar[i].y);
  }
  ind = 1;
  ind1 = 1;
  for (i = 3; i < n; i++) {
    if ((ar[i].x > ar[i - 1].x && ar[i].y < ar[i + 1].y) ||
        (ar[i].x > ar[i + 1].x && ar[i].y > ar[i - 1].y)) {
      cnt++;
    } else if ((ar[i].x < ar[i - 1].x && ar[i].y > ar[i + 1].y) ||
               (ar[i].x < ar[i + 1].x && ar[i].y < ar[i - 1].y)) {
      cnt++;
    }
  }
  printf("%lld\n", cnt);
  return 0;
}
