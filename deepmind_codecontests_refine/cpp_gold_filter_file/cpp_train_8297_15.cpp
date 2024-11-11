#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:167772160000")
using namespace std;
void redirectIO() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
const long long mod = 998244353;
long long power(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b % 2) {
      ans = (ans * a) % mod;
    }
    a = (a * a) % mod;
    b /= 2;
  }
  return ans;
}
long long rev(long long a) { return power(a, mod - 2); }
long long fact[1100000];
long long revfact[1100000];
long long C(long long a, long long b) {
  return fact[a] * revfact[b] % mod * revfact[a - b] % mod;
}
int main() {
  redirectIO();
  long long n;
  cin >> n;
  long long prob = 0;
  fact[0] = 1;
  for (int i = 1; i <= (1000100); i++) fact[i] = i * fact[i - 1] % mod;
  for (int i = 0; i < (1000100); i++) revfact[i] = rev(fact[i]);
  for (long long a = 1; a <= n; a++) {
    long long base = rev(power(3, a * n)) * C(n, a) % mod;
    if ((a + 1) % 2) base = (mod - base) % mod;
    long long mult = rev(power(3, n - a));
    mult = (1 + mod - mult) % mod;
    mult = (power(mult, n) + mod - 1) % mod;
    prob = (prob + mult * base) % mod;
  }
  prob = (prob * 3) % mod;
  long long answer = prob * power(3, n * n) % mod;
  for (long long a = 1; a <= n; a++) {
    long long curWays = C(n, a) * power(3, (n - a) * n + a) % mod;
    if (a % 2 == 0) curWays = (mod - curWays) % mod;
    answer = (answer + curWays * 2) % mod;
  }
  cout << answer << endl;
  return 0;
}
