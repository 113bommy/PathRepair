#include <bits/stdc++.h>
using namespace std;
template <typename T, typename S>
ostream& operator<<(ostream& os, pair<T, S> input) {
  os << "(" << input.first << ", " << input.second << ")";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> input) {
  for (auto t : input) os << t << "\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, set<T> input) {
  for (auto t : input) os << t << "\n";
  return os;
}
long long fact[1000002];
long long invFact[1000002];
long long MOD = 1e9 + 7;
long long powMod(long long a, long long b) {
  if (b == 0) return 1;
  long long c = powMod(a, b / 2);
  c *= c;
  c %= MOD;
  if (b % 2 == 1) c *= a, c %= MOD;
  return c;
}
void init(int n) {
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= MOD;
  }
  for (int i = 1; i <= n; i++) invFact[i] = powMod(fact[i], MOD - 2);
}
long long C(int n, int r) {
  return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}
bool valid(long long x, int a, int b) {
  while (x > 0) {
    if (x % 10 == a || x % 10 == b) {
      x /= 10;
    } else {
      return false;
    }
  }
  return true;
}
int main() {
  int n;
  int a, b;
  cin >> a >> b;
  cin >> n;
  init(n);
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    long long x = i * a + (n - i) * b;
    if (valid(x, a, b)) {
      ans += C(n, i);
      ans %= MOD;
    }
  }
  cout << ans << "\n";
  return 0;
}
