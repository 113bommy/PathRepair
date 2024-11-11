#include <bits/stdc++.h>
using namespace std;
long long a[200010];
int main() {
  int n, i;
  long long d, ans, k, ms;
  d = 0;
  ms = 0;
  scanf("%d %I64d", &n, &k);
  for (i = 0; i < n; i++) scanf("%I64d", &a[i]);
  for (i = 0; i < n; i++) {
    ans = d - (n - 1 - i) * a[i] * (i - ms);
    if (ans < k) {
      ms++;
      printf("%d \n", i + 1);
    } else
      d += a[i] * (i - ms);
  }
  return 0;
}
