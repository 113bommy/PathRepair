#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b, long long mod) {
  long long aInPow = a, ans = 1;
  while (b != 0) {
    if (b % 2) ans = (ans * aInPow) % mod;
    aInPow = (aInPow * aInPow) % mod;
    b >>= 1;
  }
  return ans;
}
void qs(vector<long long>& a, vector<long long>& b, long long l, long long r) {
  if (r - l <= 1) return;
  long long mid = a[l + rand() % (r - l - 1)], x = l, y = l;
  for (long long i = l; i < r; i++) {
    if (a[i] < mid) {
      swap(a[i], a[x]);
      swap(b[i], b[x]);
      if (x != y) {
        swap(a[i], a[y]);
        swap(b[i], b[y]);
      }
      x++;
      y++;
    } else if (a[i] == mid) {
      swap(a[i], a[y]);
      swap(b[i], b[y]);
      y++;
    }
  }
  qs(a, b, l, x);
  qs(a, b, y, r);
}
long long gcd(long long a, long long b) {
  while (b ^= a ^= b ^= a %= b)
    ;
  return a;
}
long long f(long long n) {
  long long i, ans = n;
  for (i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      ans -= ans / i;
    }
  }
  if (n > 1) ans -= ans / n;
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long p = 1e9 + 7;
    long long n, k;
    cin >> n >> k;
    long long c2 = power(2, n - 1, p), c = (2 * c2) % p;
    if (n & 1)
      cout << pow((c2 + 1) % p, k) << "\n";
    else
      cout << ((power(c, k, p) * 2 + c * power(c2 - 1, k, p)) % p *
               power(c + 2, p - 2, p)) %
                  p
           << "\n";
  }
}
