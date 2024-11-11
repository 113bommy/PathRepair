#include <bits/stdc++.h>
using namespace std;
bool cc(long long now) {
  if (now < 0) return false;
  long long l = 1, r = (long long)sqrt(now + 1);
  while (l <= r) {
    long long mid = (l + r) / 2;
    long long tmp = (mid + 1) * mid / 2;
    if (tmp == now)
      return true;
    else if (tmp > now)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return false;
}
int main() {
  long long n;
  while (cin >> n) {
    long long len = (long long)sqrt(n * 2);
    bool ok = false;
    for (long long i = 1; i <= len; i++) {
      if (cc(n - i * (i + 1) / 2)) {
        ok = true;
        break;
      }
    }
    ok ? puts("YES") : puts("NO");
  }
  return 0;
}
