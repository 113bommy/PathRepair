#include <bits/stdc++.h>
using namespace std;
long long a[999999];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  {
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    sort(a, a + n);
    long long tmp = 0;
    int t = 0;
    while (k--) {
      if (t > n) {
        printf("0\n");
        continue;
      }
      tmp += a[t];
      printf("%lld\n", a[t++]);
      while (a[t] - tmp <= 0) {
        t++;
      }
      a[t] -= tmp;
    }
  }
  return 0;
}
