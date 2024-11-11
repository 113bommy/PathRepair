#include <bits/stdc++.h>
using namespace std;
long long n, k, A, B;
long long ans;
signed main() {
  scanf("%lld%lld%lld%lld", &n, &k, &A, &B);
  if (k == 1) {
    cout << 1ll * A * (n - 1) << endl;
    return 0;
  }
  while (n != 1) {
    if (n % k != 0) {
      ans += 1ll * (n % k) * A;
      n = (n / k) * k;
      if (n == 0) n++, ans -= A;
    } else {
      if ((n - n / k) * A <= B)
        ans += 1ll * (n - n / k) * A;
      else
        ans += B;
      n /= k;
    }
  }
  cout << ans << endl;
  return 0;
}
