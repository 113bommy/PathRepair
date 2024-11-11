#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long gcd(long long a, long long b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}
int main() {
  long long n, second;
  cin >> n >> second;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  long long p = n / 2;
  long long ans = 0;
  if (second > a[p]) {
    while (second > a[p] && p < n) {
      ans += (second - a[p]);
      p++;
    }
  } else {
    while (second < a[p] && p >= 0) {
      ans += (a[p] - second);
      p--;
    }
  }
  cout << ans;
}
