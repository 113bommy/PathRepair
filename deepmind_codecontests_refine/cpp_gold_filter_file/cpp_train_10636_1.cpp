#include <bits/stdc++.h>
using namespace std;
long long max(long long A, long long b) {
  if (A > b) return A;
  return b;
}
long long min(long long A, long long b) {
  if (A < b) return A;
  return b;
}
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  long long mod = 998244353;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long temp = 0;
    long long k = 0;
    while (arr[i] > 0) {
      long long rem = arr[i] % 10;
      arr[i] /= 10;
      temp = rem * 10 + rem;
      long long x = pow(10, k);
      temp = ((temp % mod) * (x % mod)) % mod;
      temp = ((temp % mod) * (n % mod)) % mod;
      ans = (ans % mod + temp % mod) % mod;
      k += 2;
    }
  }
  cout << ans << endl;
}
