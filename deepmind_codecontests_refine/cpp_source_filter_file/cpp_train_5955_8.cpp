#include <bits/stdc++.h>
using namespace std;
long long K;
long long sum(long long a, long long k) {
  if (a == 0) return k * (k + 1) / 2;
  long long cur = a / k;
  long long p = sum(cur, k) % K;
  long long l = a % k * k + 1, r = (a % k + 1) * k;
  if (l >= p) l++;
  if (r >= p) r++;
  long long ls = cur * K;
  if (r - l + 1 == k)
    return ((2 * ls + l + r) * k / 2) % K;
  else
    return ((2 * ls + l + r) * (k + 1) / 2 - ls - cur) % K;
}
long long func(long long n, long long k) {
  K = k * k + 1;
  long long a = (n - 1) / K;
  long long b = sum(a, k);
  if (n % K == b)
    return (a + 1) * (k + 1);
  else {
    long long r = (n - 1) % K;
    if (r >= b) r--;
    return a * k * (k + 1) + r / k * (k + 1) + r % k + 1;
  }
}
int main() {
  int t;
  long long n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    cout << func(n, k) << endl;
  }
  return 0;
}
