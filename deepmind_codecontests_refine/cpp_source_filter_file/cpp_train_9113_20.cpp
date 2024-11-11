#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long d, son, mot;
long long const mod = 1000003;
long long powMod(long long x, long long p, long long mod) {
  long long temp = 1, k = x;
  while (p) {
    if (p & 1) temp = temp * k % mod;
    k = k * k % mod;
    p >>= 1;
  }
  return temp;
}
long long invMod1(long long a, long long mod) {
  return powMod(a, mod - 2, mod);
}
long long compute2(long long n, long long x) {
  long long sum = 0;
  x--;
  while (x) {
    x >>= 1;
    sum += x;
  }
  sum += n;
  return sum;
}
long long computeson(long long A) {
  long long sum = 1;
  if (k > A) return 0;
  for (long long i = A; i >= A - k + 1; i--) sum = sum * i % mod;
  return sum;
}
int main() {
  long long A, inv;
  cin >> n >> k;
  if (n < 64 && (1LL << n) < k) {
    cout << "1 1" << endl;
    return 0;
  }
  A = powMod(2, n, mod);
  son = computeson(A);
  d = compute2(n, k);
  inv = invMod1(2, mod);
  inv = powMod(inv, d, mod);
  A = powMod(A, k, mod);
  son = son * inv % mod;
  A = A * inv % mod;
  son = A - son;
  if (son < mod) son += mod;
  cout << son << ' ' << A << endl;
  return 0;
}
