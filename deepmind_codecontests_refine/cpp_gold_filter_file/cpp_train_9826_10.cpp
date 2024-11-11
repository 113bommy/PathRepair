#include <bits/stdc++.h>
using namespace std;
const long long N = 10000050;
long long a[N], n;
long long ans;
bool used[N];
int main() {
  scanf("%I64d", &n);
  ans = 0;
  memset(a, -1, sizeof(a));
  long long up = (long long)(log(n * 1.0) / log(2.0) + 0.01) - 1;
  for (long long i = n; i >= 0; i--) {
    if (a[i] != -1) continue;
    bool found = false;
    for (long long times = 0; times <= up && !found; times++) {
      long long val = 0;
      for (long long mask = up - times; mask >= 0 && !found; mask--) {
        if ((i & (1LL << mask)) == 0) {
          val |= (1LL << mask);
        }
      }
      if (val > n) printf("val:%d\n", val);
      if (!used[val]) {
        a[i] = val, used[val] = found = true;
        a[val] = i;
      }
    }
    if (!found) a[i] = 0, a[0] = i;
  }
  for (long long i = 0; i <= n; i++) {
    ans += (a[i] ^ i);
  }
  printf("%I64d\n", ans);
  for (long long i = 0; i <= n; i++)
    printf("%I64d%c", a[i], i == n ? '\n' : ' ');
  return 0;
}
