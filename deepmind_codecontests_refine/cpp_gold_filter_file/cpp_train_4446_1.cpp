#include <bits/stdc++.h>
using namespace std;
long long n, H;
long long sum(long long L, long long R) {
  if (R < L) return 0;
  return (L + R) * (R - L + 1) / 2ll;
}
bool check(long long mx) {
  if (mx - 1 >= H) {
    if ((double)(H + mx - 1.0) * (mx - H) / 2.0 + mx * (mx - 1.0) / 2.0 >=
        (double)n)
      return 0;
    long long rem = n - sum(H, mx - 1) - sum(1, mx - 1);
    return rem / mx;
  } else {
    if ((double)mx * (mx - 1.0) / 2.0 >= (double)n) return 0;
    long long rem = n - sum(1, mx - 1);
    return rem / mx;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> H;
  long long L = 1, R = n;
  while (L <= R) {
    long long mid = (L + R) >> 1;
    if (check(mid)) {
      L = mid + 1;
    } else
      R = mid - 1;
  }
  L--;
  long long ans = 0;
  if (L > H) {
    ans += (L - H);
    ans += L - 1;
    n -= sum(H, L - 1);
    n -= sum(1, L - 1);
    ans += n / L;
    if (n % L != 0) ans++;
    cout << ans << endl;
    return 0;
  } else {
    ans += L - 1;
    n -= sum(1, L - 1);
    ans += n / L;
    if (n % L != 0) ans++;
    cout << ans << endl;
    return 0;
  }
  return 0;
}
