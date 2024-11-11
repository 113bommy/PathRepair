#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int n, pos, l, r;
  scanf("%lld", &n);
  scanf("%lld", &pos);
  scanf("%lld", &l);
  scanf("%lld", &r);
  long long int ans = 0;
  if (l == 1 && r == n) {
    printf("0");
    return 0;
  }
  if (pos <= l) {
    ans = l - pos;
    if (l != 1) {
      ans++;
    }
    if (r < n) {
      ans += r - l;
      ans++;
    }
  } else if (pos >= r) {
    ans = pos - r;
    if (r != n) {
      ans++;
    }
    if (l > 1) {
      ans += r - l;
      ans++;
    }
  } else {
    long long int x = 0, x1 = 0;
    if (l != 1) {
      x = pos - l;
    }
    if (r != n) {
      x1 = r - pos;
    }
    if (x == 0 && x1 == 0) {
      ans = 0;
    } else if (x == 0) {
      ans = x1 + 1;
    } else if (x1 == 0) {
      ans = x + 1;
    } else {
      ans = min(x + 2 * x1, x1 + 2 * x);
      ans += 2;
    }
  }
  printf("%lld", ans);
  return 0;
}
