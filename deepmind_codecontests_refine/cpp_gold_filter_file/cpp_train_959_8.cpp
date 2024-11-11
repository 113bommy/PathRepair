#include <bits/stdc++.h>
using namespace std;
const long long maxn = 400050;
long long a[maxn], b[maxn], n;
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  long long ans = 0;
  for (long long k = 0; k <= 24; k++) {
    for (long long i = 1; i <= n; i++) b[i] = a[i] % (1 << (k + 1));
    long long cnt = 0;
    sort(b + 1, b + n + 1);
    for (long long i = 1; i <= n; i++) {
      long long l = lower_bound(b + i + 1, b + n + 1, (1 << k) - b[i]) - b;
      long long r =
          lower_bound(b + i + 1, b + n + 1, (1 << (k + 1)) - b[i]) - b - 1;
      if (l > r) continue;
      long long st = l;
      while (l < r) {
        long long mid = (l + r + 1) >> 1;
        if (b[i] + b[mid] < (1 << (k + 1)))
          l = mid;
        else
          r = mid - 1;
      }
      cnt += l - st + 1;
    }
    for (long long i = 1; i <= n; i++) {
      long long l =
          lower_bound(b + i + 1, b + n + 1, (1 << (k + 1)) + (1 << k) - b[i]) -
          b;
      long long r =
          lower_bound(b + i + 1, b + n + 1, (1 << (k + 2)) - b[i]) - b - 1;
      if (l > r) continue;
      long long st = l;
      while (l < r) {
        long long mid = (l + r + 1) >> 1;
        if (b[i] + b[mid] < (1 << (k + 2)))
          l = mid;
        else
          r = mid - 1;
      }
      cnt += l - st + 1;
    }
    cnt %= 2;
    ans ^= (cnt << k);
  }
  cout << ans;
}
