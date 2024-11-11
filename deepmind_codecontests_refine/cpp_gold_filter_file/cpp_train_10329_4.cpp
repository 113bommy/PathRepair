#include <bits/stdc++.h>
using namespace std;
const int MAXN = 250010;
const int inf = 1e9 + 1e8;
const long long INF = 1e18 + 1e17;
const int MOD1 = 998244353;
const int MOD2 = 1e9 + 7;
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
bool is_prime(int x) {
  if (x == 1 || (x % 2 == 0 && x > 2)) return false;
  for (int i = 3; i * i <= x; i += 2) {
    if (!(x % i)) {
      return false;
    }
  }
  return true;
}
long long N, M;
long long ans;
long long fact[MAXN];
int main() {
  cin >> N >> M;
  fact[0] = 1;
  for (long long i = 1; i <= N; i++) {
    fact[i] = (i * fact[i - 1]) % M;
  }
  for (long long i = 1; i <= N; i++) {
    ans += (N - i + 1) * ((fact[i] * fact[N - i + 1] % M));
    ans %= M;
  }
  cout << ans << endl;
  return 0;
}
