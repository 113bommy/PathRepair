#include <bits/stdc++.h>
int n, t;
long long cnt, sum;
int main() {
  scanf("%d", &n);
  for (register int i = 1; i <= n; ++i) {
    scanf("%d", &t);
    if (t)
      ++cnt;
    else
      sum += cnt;
  }
  printf("%d", sum);
  return 0;
}
