#include <bits/stdc++.h>
using namespace std;
long long a[100010];
int main() {
  long long tc, n, i, ans = 0;
  scanf("%lld", &tc);
  while (tc--) {
    ans = 0;
    scanf("%lld", &n);
    for (i = 0; i < n; i++) {
      scanf("%lld", a + i);
      ans += a[i];
    }
    sort(a, a + n);
    if (a[n - 1] >= ans - a[n - 1])
      printf("T\n");
    else if (ans % 2 == 0)
      printf("HL\n");
    else
      printf("T\n");
  }
  return 0;
}
