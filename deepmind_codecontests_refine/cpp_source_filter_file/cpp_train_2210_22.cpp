#include <bits/stdc++.h>
using namespace std;
long long a[30];
int main() {
  memset(a, 0, sizeof(a));
  int i, n;
  scanf("%d", &n);
  while (n-- > 0) {
    int tmp;
    scanf("%d", &tmp);
    tmp += 10;
    a[tmp]++;
  }
  long long ans = 0;
  for (i = 0; i < 9; i++) {
    ans += a[i] * a[20 - i];
  }
  ans += a[10] * (a[10] - 1) / 2;
  printf("%lld\n", ans);
  return 0;
}
