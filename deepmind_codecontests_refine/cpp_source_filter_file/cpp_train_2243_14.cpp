#include <bits/stdc++.h>
using namespace std;
long long fact[(int)1e6], revFac[(int)1e6];
long long power(long long b, long long p) {
  if (p == 0) return 1;
  long long sq = power(b, p / 2);
  sq = sq * sq;
  sq %= 1000003;
  if (p & 1) sq = sq * b;
  sq %= 1000003;
  return sq;
}
long long combinations(int n, int k) {
  if (n == k || k == 0) return 1;
  return (fact[n] * revFac[n - k] % 1000003 * revFac[k] % 1000003) % 1000003;
}
int main(int argc, const char* argv[]) {
  int n, C;
  cin >> n >> C;
  fact[0] = fact[1] = 1;
  for (int i = 1; i * i <= 1e9; ++i)
    fact[i] = (fact[i - 1] % 1000003 * i % 1000003),
    revFac[i] = power(fact[i], 1000003 - 2);
  long long ans = 0;
  for (int i = 1; i <= (int)n; i++) {
    ans += combinations(i + C - 1, i), ans %= 1000003;
  }
  cout << ans << endl;
  return 0;
}
