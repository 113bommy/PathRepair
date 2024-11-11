#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5 + 5, MOD = 1e9 + 7;
long long N, R, K, a[MM], y[MM];
bool check(long long x) {
  long long k = K;
  long long b = 0;
  memset(y, 0, sizeof(y));
  for (int i = 1; i <= N; i++) {
    b += y[i];
    if (a[i] + b < x) {
      k -= (x - (a[i] + b));
      y[min(N + 1, i + R + R + 1)] -= (x - (a[i] + b));
      b += (x - (a[i] + b));
      if (k < 0) return false;
    }
  }
  return true;
}
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> N >> R >> K;
  for (int i = 1, x; i <= N; i++) {
    cin >> x;
    a[max(1ll, i - R)] += x;
    a[min(N + 1, i + R + 1)] -= x;
  }
  for (int i = 1; i <= N; i++) a[i] += a[i - 1];
  long long lo = 0, hi = 1e18 + 1e13, mid, ans;
  while (lo <= hi) {
    mid = (lo + hi) / 2ll;
    if (check(mid))
      ans = mid, lo = mid + 1;
    else
      hi = mid - 1;
  }
  cout << ans << "\n";
}
