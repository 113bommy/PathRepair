#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long a[400002], I, n, K;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> I;
  I *= 8;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long ans = n;
  if (I / n > 50) {
    cout << 0 << endl;
    return 0;
  }
  K = (1ll << (I / n));
  long long p = 0, br1 = 1;
  for (long long i = 0; i < n; i++) {
    if (i != 0 && a[i] != a[i - 1]) br1--;
    if (br1 <= 0) br1 = 1;
    if (p < i) p = i;
    for (;; p++) {
      if (p == n - 1 || (a[p + 1] != a[p] && br1 == K)) {
        break;
      }
      if (a[p + 1] != a[p]) br1++;
    }
    ans = min(ans, n - (p - i + 1));
  }
  cout << ans << endl;
  return 0;
}
