#include <bits/stdc++.h>
using namespace std;
bool isprime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
long long modexp(long long a, long long b, long long m) {
  long long r = 1;
  a = a % m;
  while (b > 0) {
    if (b & 1) r = (r * a) % m;
    b = b >> 1;
    a = (a * a) % m;
  }
  return r % m;
}
struct CustomCompare {
  bool operator()(const int& lhs, const int& rhs) { return lhs < rhs; }
};
long long builtin_popcount(long long x) {
  long long cnt = 0;
  for (long long i = 60; i >= 0; i--) {
    if ((1LL << i) & x) cnt++;
  }
  return cnt;
}
long long addmod(long long a, long long b, long long r) {
  a %= r;
  b %= r;
  return (a + b) % r;
}
long long mulmod(long long a, long long b, long long r) {
  a %= r;
  b %= r;
  return (a * b) % r;
}
int main() {
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      if (i % 2)
        cout << 0 << " ";
      else
        cout << (1LL << (i + j)) << " ";
    }
    cout << endl;
  }
  fflush(stdout);
  long long q;
  cin >> q;
  while (q--) {
    long long k;
    cin >> k;
    long long x = 1, y = 1;
    cout << x << " " << y << endl;
    fflush(stdout);
    long long res = 2 * n - 2;
    while (res--) {
      long long j = x + y + 1;
      if (x % 2) {
        if (k & (1LL << j))
          cout << x + 1 << " " << y << endl, x++;
        else
          cout << x << " " << y + 1 << endl, y++;
      } else {
        if (k & (1LL << j))
          cout << x << " " << y << endl, y++;
        else
          cout << x + 1 << " " << y << endl, x++;
      }
      fflush(stdout);
    }
  }
  return 0;
}
