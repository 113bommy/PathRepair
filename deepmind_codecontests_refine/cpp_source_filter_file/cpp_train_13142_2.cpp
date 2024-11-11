#include <bits/stdc++.h>
using namespace std;
long long read() {
  int x = 0, f = 1, ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
  return x * f;
}
int n;
long long a1, k;
long long get_min(long long x) {
  register long long ans = 9;
  while (x) {
    ans = min(ans, x % 10);
    x /= 10;
  }
  return ans;
}
long long get_max(long long x) {
  register long long ans = 0;
  while (x) {
    ans = max(ans, x % 10);
    x /= 10;
  }
  return ans;
}
signed main() {
  n = read();
  while (n--) {
    a1 = read(), k = read() - 1;
    while (k--) {
      register long long mn = get_min(a1), mx = get_max(a1);
      if (!mn || !mx) break;
      a1 = 1ll * a1 + 1ll * mn * mx;
    }
    printf("%lld\n", a1);
  }
  return 0;
}
