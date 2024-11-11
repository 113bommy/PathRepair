#include <bits/stdc++.h>
using namespace std;
int a[100005], n, sum = 0, tp = 0, ans = -(1 << 30);
int main() {
  scanf("%d", &n);
  for (register int i = 1; i <= n; ++i) scanf("%d", &a[i]), sum += a[i];
  for (register int i = 1; i <= n; ++i)
    if (tp + a[i] < 0)
      tp = 0;
    else
      ans = max(ans, tp + a[i]), tp += a[i];
  ans = max(ans, tp);
  printf("%d\n", max(ans * 2 - sum, sum));
}
