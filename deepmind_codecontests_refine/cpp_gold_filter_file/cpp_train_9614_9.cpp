#include <bits/stdc++.h>
using namespace std;
int main() {
  int prizes[5], n, a[50], points = 0, num;
  long long cnt[5];
  memset(cnt, 0, sizeof cnt);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < 5; i++) scanf("%d", &prizes[i]);
  for (int i = 0; i < n; i++) {
    points += a[i];
    for (int i = 4; i > -1; i--) {
      num = points / prizes[i];
      cnt[i] += num;
      points -= num * prizes[i];
    }
  }
  for (int i = 0; i < 5; i++) printf("%lld ", cnt[i]);
  printf("\n%d", points);
}
