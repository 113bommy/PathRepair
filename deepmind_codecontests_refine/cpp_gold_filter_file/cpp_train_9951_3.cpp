#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long LIM = 2e5;
long long inv[MAXN], fac[MAXN], N, L[MAXN], R[MAXN], invfac[MAXN], ans = 0, now;
char s[MAXN];
namespace solution {
long long C(long long a, long long b) {
  if (b > a) return 0;
  return fac[a] * invfac[a - b] % mod * invfac[b] % mod;
}
void Prepare() {
  fac[0] = 1;
  for (long long i = 1; i <= LIM; i++) fac[i] = i * fac[i - 1] % mod;
  inv[1] = 1;
  invfac[0] = 1;
  for (long long i = 2; i <= LIM; i++)
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  for (long long i = 1; i <= LIM; i++) invfac[i] = invfac[i - 1] * inv[i] % mod;
  scanf("%s", s + 1);
  N = strlen(s + 1);
  for (long long i = 1; i <= N; i++) L[i] = L[i - 1] + (s[i] == '(');
  for (long long i = N; i >= 1; i--) R[i] = R[i + 1] + (s[i] == ')');
}
void Solve() {
  for (long long i = 1; i <= N - 1; i++)
    if (s[i] == '(') {
      (ans += C(L[i] + R[i] - 1, R[i] - 1)) %= mod;
    }
  cout << ans << endl;
}
}  // namespace solution
int main() {
  using namespace solution;
  Prepare();
  Solve();
  return 0;
}
