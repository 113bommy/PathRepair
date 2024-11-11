#include <bits/stdc++.h>
using namespace std;
const int S = (int)sqrt(1e11);
int main() {
  long long n, l, r, k;
  scanf("%lld %lld %lld %lld", &n, &l, &r, &k);
  long long x = (r - l + n) % n + 1;
  long long ans = -1;
  if (n <= S) {
    for (long long i = 0; i <= n; ++i) {
      long long one_turn = n + i;
      long long res = k % one_turn;
      if (res == 0) res += one_turn;
      long long mini = max(0ll, i - (n - x)) + x;
      long long maxs = min(i * 1ll, x) + x;
      if (i > n - x) mini--;
      if (res >= mini && res <= maxs) ans = i;
    }
  } else {
    if (k <= x * 2) {
      if (k == x * 2 || k == x * 2 - 1) {
        ans = n;
      } else if (k >= x) {
        ans = k + 1 - x + n - x;
      }
    } else {
      for (long long i = 1; i <= k / n; ++i) {
        long long res = k - n * i - x;
        if (res < i || res > x + n * i) continue;
        if ((n - x) * i >= res) {
          ans = max(ans, res / i);
        } else {
          res -= (n - x) * i;
          ans = max(ans, n - x + (res + 1) / (i + 1));
        }
      }
    }
  }
  printf("%lld\n", ans);
}
