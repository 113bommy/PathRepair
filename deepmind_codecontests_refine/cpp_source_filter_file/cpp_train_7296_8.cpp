#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
using namespace std;
long long n, m;
int p[40];
int main() {
  scanf("%lld %lld", &m, &n);
  int i, a;
  int cnt = 1;
  for (i = 0; i < n; i++) {
    printf("1\n");
    fflush(stdout);
    scanf("%d", &a);
    if (a == 1)
      p[cnt++] = 1;
    else if (a == -1)
      p[cnt++] = 0;
    else if (a == 0)
      return 0;
  }
  long long l = 1, r = m + 1;
  cnt = 1;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    printf("%lld\n", mid);
    fflush(stdout);
    scanf("%d", &a);
    if (a == 0)
      return 0;
    else if (a == 1) {
      if (p[cnt++])
        l = mid + 1;
      else
        r = mid - 1;
    } else if (a == -1) {
      if (p[cnt++])
        r = mid - 1;
      else
        l = mid + 1;
    }
    if (cnt == n) cnt = 1;
  }
  return 0;
}
