#include <bits/stdc++.h>
using namespace std;
long long modexp(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b % 2) {
      ans *= a;
      ans %= 1000000009;
    }
    b /= 2;
    a *= a;
    a %= 1000000009;
  }
  return ans;
}
void precompute(void) {}
int main() {
  long long n, m, k, alpha, diff, first, ans;
  precompute();
  cin >> n >> m >> k;
  diff = (n / k) * (k - 1) + (n % k);
  alpha = max(0LL, m - diff);
  first = (modexp(2, alpha + 1) - 2 + 1000000009) % 1000000009;
  first = (first * k) % 1000000009;
  ans = (first + m - k * alpha) % 1000000009;
  cout << ans << endl;
  return 0;
}
