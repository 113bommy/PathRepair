#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000009;
long long mod_pow(long long b, long long e) {
  long long ans = 1LL;
  while (e > 0) {
    if (e % 2 == 1) {
      ans *= b;
      ans %= M;
    }
    e /= 2;
    b *= b;
    b %= M;
  }
  return ans;
}
long long n, m, k;
long long score = 0;
int main() {
  cin >> n >> m >> k;
  long long good_spaces = (n / k) * (k - 1) + (n % k);
  long long n_doubles = max(0LL, m - good_spaces);
  long long score = k * (mod_pow(2, n_doubles + 1) - 2);
  score %= M;
  score += (m - n_doubles * k);
  score %= M;
  cout << score;
  return 0;
}
