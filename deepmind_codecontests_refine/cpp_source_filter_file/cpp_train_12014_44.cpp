#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6, M = 1e6;
const long long x = 1e7;
bool primes[x + 1];
int n, m;
int mpow(int base, int exp);
void mmul(int &num, int num2);
void SieveOfEratosthenes(long long n);
void solve() {
  cin >> n;
  SieveOfEratosthenes(N);
  int i = 2;
  while (n) {
    if (primes[i]) {
      n--;
      cout << i << " ";
    }
    i++;
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  t = 1;
  while (t--) solve();
}
int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long)result * base) % mod;
    base = ((long long)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
void mmul(int &num, int num2) { num = ((num % mod) * (num2 % mod)) % mod; }
void SieveOfEratosthenes(long long n) {
  memset(primes, true, sizeof(primes));
  primes[0] = primes[1] = false;
  for (long long i = 2; i * i <= n; ++i) {
    if (primes[i]) {
      for (long long j = i * i; j <= n; j += i) {
        primes[j] = false;
      }
    }
  }
}
