#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const unsigned long long INFLL = 100000000000000000ll;
unsigned long long N, K, L, M;
unordered_map<unsigned long long, unsigned long long> F;
unsigned long long exp(unsigned long long n, unsigned long long e) {
  if (e == 0) return 1;
  if (e % 2) return (exp(n, e - 1) * n) % M;
  unsigned long long x = exp(n, e / 2);
  return (x * x) % M;
}
unsigned long long fib(unsigned long long n) {
  if (n < 2) return 1;
  if (F.find(n) != F.end()) return F[n];
  unsigned long long a = fib((n + 1) / 2);
  unsigned long long b = fib(n / 2);
  unsigned long long c = fib((n - 1) / 2);
  unsigned long long d = fib((n - 2) / 2);
  unsigned long long x = (a * b) % M;
  unsigned long long y = (c * d) % M;
  unsigned long long ans = (x + y) % M;
  F[n] = ans;
  return ans;
}
int main() {
  cin >> N >> K >> L >> M;
  if (L < 64 && K > (1ll << L) - 1) {
    cout << 0;
    return 0;
  }
  unsigned long long zero = fib(N + 1) % M;
  unsigned long long pot = exp(2, N) % M;
  unsigned long long one = (pot + M - zero) % M;
  unsigned long long ans = 1;
  if (L > 0)
    for (int i = (0); i <= (L - 1); i++)
      if (K & (1ll << i)) {
        ans *= one;
        ans %= M;
      } else {
        ans *= zero;
        ans %= M;
      }
  cout << ans << "\n";
}
