#include <bits/stdc++.h>
using namespace std;
struct aaa {
  long long x, y;
} d[1000010];
long long n, i, j, hh, s1, s2, t2, t1, cnt[1000010], a[1000010], b[1000010],
    flag;
int main() {
  scanf("%lld", &n);
  for (i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    a[i] += a[i - 1];
  }
  for (i = 1; i <= n; i++) {
    scanf("%lld", &b[i]);
    b[i] += b[i - 1];
  }
  if (a[n] > b[n]) flag = 1, swap(a, b);
  j = 0;
  for (i = 0; i <= n; i++) {
    while (b[j] < a[i]) j++;
    hh = b[j] - a[i];
    if (cnt[hh]) {
      s1 = d[hh].x;
      s2 = d[hh].y;
      t1 = i;
      t2 = j;
      break;
    }
    cnt[hh]++;
    d[hh].x = i;
    d[hh].y = j;
  }
  if (flag) swap(a, b), swap(s1, s2), swap(t1, t2);
  printf("%lld\n", t1 - s1);
  for (i = s1 + 1; i <= t1; i++) printf("%lld ", i);
  printf("\n%lld\n", t2 - s2);
  for (i = s2 + 1; i <= t2; i++) printf("%lld ", i);
}
