#include <bits/stdc++.h>
using namespace std;
bool isprime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
int main() {
  int t;
  t = 1;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long ans = 0;
    ans += abs(a[0]);
    for (int i = 1; i < n; i++) {
      ans += abs(a[i] - a[i - 1]);
    }
    cout << ans;
  }
  return 0;
}
