#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i += 6) {
    if ((n % i == 0) || (n % (i + 2) == 0)) return false;
  }
  return true;
}
int32_t main() {
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  sort(a, a + n);
  long long ans = 0, j = 0;
  for (long long i = 0; i < n; i++) {
    while (j < n && a[j] <= 2 * a[i]) {
      j++;
    }
    ans += (j - i);
  }
  cout << ans;
}
