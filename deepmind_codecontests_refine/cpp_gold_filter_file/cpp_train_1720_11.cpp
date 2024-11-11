#include <bits/stdc++.h>
using namespace std;
long long po(long long x, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * x;
    x *= x;
    n >>= 1;
  }
  return res;
}
long long bin(long long x, long long n) {
  long long res = 1;
  x %= 1000000007;
  while (n) {
    if (n & 1) res = (res * x) % 1000000007;
    x = (x * x) % 1000000007;
    n >>= 1;
  }
  return res;
}
bool prime(long long n) {
  if (n == 3) return 1;
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
void solve() {
  long long n, k;
  cin >> n;
  for (long long i = 1; i < 100000000; i++) {
    if (i * (i + 1) / 2 > n) {
      k = i;
      break;
    }
  }
  k--;
  if (n == k * (k + 1) / 2) {
    cout << k;
    return;
  }
  cout << n - (k * (k + 1)) / 2;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
}
