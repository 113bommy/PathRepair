#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long count(long long x) {
  long long cnt = 0ll;
  long long c = 0ll;
  if (x & 1) {
    c = 2ll;
    cnt = 1ll;
  } else if (x % 2 == 0) {
    c = 4ll;
    cnt = 2ll;
  }
  x *= 2;
  for (long long i = x; i <= n; i *= 2ll, c *= 2ll) {
    if (i + c - 1ll > n) {
      cnt += n - i + 1ll;
      break;
    } else {
      cnt += c;
    }
  }
  return cnt;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k;
  long long l = 1ll, r = n / 2ll;
  long long ans = 0;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (count(2ll * mid) >= k) {
      l = mid + 1ll;
      ans = max(ans, 2ll * mid);
    } else {
      r = mid - 1ll;
    }
  }
  l = 1ll, r = (n + 1ll) / 2ll;
  while (l <= r) {
    long long mid = (l + r) / 2ll;
    if (count(2ll * mid - 1ll) >= k) {
      l = mid + 1ll;
      ans = max(ans, 2ll * mid - 1ll);
    } else {
      r = mid - 1ll;
    }
  }
  cout << ans << "\n";
  cerr << clock() << "ms\n";
  return 0;
}
