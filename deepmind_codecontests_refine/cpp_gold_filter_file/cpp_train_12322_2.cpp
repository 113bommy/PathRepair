#include <bits/stdc++.h>
using namespace std;
long long bsearch(long long n) {
  long long lo = 1, hi = 4000000000, mid;
  for (int i = 0; i < 500; i++) {
    mid = (lo + hi) / 2;
    if (mid * mid == n)
      return mid;
    else {
      if (mid * mid < n)
        lo = mid;
      else
        hi = mid;
    }
  }
  return -1;
}
long long sumdig(long long n) {
  long long sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
int main() {
  long long n, ans = 1000000000, a;
  cin >> n;
  for (long long s = 1; s <= 100; s++) {
    a = bsearch(s * s + 4 * n);
    if (a == -1) continue;
    if ((a - s) % 2 != 0) continue;
    if (sumdig((a - s) / 2) != s) continue;
    if ((a - s) / 2 <= 0) continue;
    ans = min(ans, (a - s) / 2);
  }
  if (ans == 1000000000)
    cout << "-1\n";
  else
    cout << ans << "\n";
  return 0;
}
