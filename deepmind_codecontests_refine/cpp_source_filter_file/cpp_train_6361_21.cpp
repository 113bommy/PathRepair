#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const long long mod = 1e9 + 7;
long long n, k;
bool cal(long long l, long long r) {
  printf("%lld %lld\n", l, r);
  fflush(stdout);
  char h[10];
  scanf("%s", h);
  if (h[0] == 'Y')
    return 1;
  else
    return 0;
}
int main() {
  scanf("%lld%lld", &n, &k);
  srand(time(NULL));
  int i, j;
  long long l = 1, r = n, len, x, mid;
  for (i = 1; i <= 4500; i++) {
    len = r - l + 1;
    if (len <= 30) {
      x = l + rand() % len;
      if (cal(x, x))
        break;
      else {
        l = max(1ll, l - k);
        r = min(r + k, n);
      }
      continue;
    }
    mid = l + r >> 1;
    if (cal(l, mid)) {
      r = mid;
    } else
      l = mid + 1;
    l = max(1ll, l - k);
    r = min(r + k, n);
  }
}
