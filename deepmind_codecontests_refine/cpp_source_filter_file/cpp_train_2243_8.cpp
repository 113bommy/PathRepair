#include <bits/stdc++.h>
using namespace std;
template <typename S, typename T>
ostream& operator<<(ostream& out, pair<S, T> const& p) {
  out << '(' << p.first << ", " << p.second << ')';
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> const& v) {
  long long l = v.size();
  for (long long i = 0; i < l - 1; i++) out << v[i] << ' ';
  if (l > 0) out << v[l - 1];
  return out;
}
template <typename T>
void trace(const char* name, T&& arg1) {
  cout << name << " : " << arg1 << "\n";
}
template <typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  trace(comma + 1, args...);
}
const long long N = 5e6 + 10;
const long long MOD = 1e6 + 3;
long long fac[N + 10], ifac[N + 10];
long long power(long long x, long long t) {
  long long ans = 1;
  while (t > 0) {
    if (t & 1) ans = 1LL * ans * x % MOD;
    x = 1LL * x * x % MOD;
    t >>= 1;
  }
  return ans;
}
void init_fac() {
  fac[0] = 1;
  for (long long i = 1; i < N; i++) {
    fac[i] = (fac[i - 1] * i) % MOD;
  }
  ifac[N - 1] = power(fac[N - 1], MOD - 2);
  for (long long i = N - 1; i >= 1; i--) {
    ifac[i - 1] = (ifac[i] * i) % MOD;
  }
}
long long C(long long n, long long m) {
  if (n < m) return 0;
  return fac[n] * (1LL * ifac[m] * ifac[n - m] % MOD) % MOD;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init_fac();
  long long n, c;
  cin >> n >> c;
  long long ans = 0;
  for (long long i = 1; i <= c; i++) {
    ans = (ans + C(n + i - 1, n - 1)) % MOD;
  }
  cout << ans << "\n";
}
