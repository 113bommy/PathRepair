#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const int MOD = 998244353;
long long pow(long long x, long long y, long long m) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = (ret * x) % m;
    y >>= 1;
    x = (x * x) % m;
  }
  return ret;
}
long long inv(long long a) { return pow(a, MOD - 2, MOD); }
long long fat[200200];
void fato() {
  fat[0] = 1;
  fat[1] = 1;
  for (long long i = 2; i < 200020; i++) {
    fat[i] = i * fat[i - 1] % MOD;
  }
}
long long comb(long long a, long long b) {
  if (a < b) return 1;
  if (b == 0 or a == 0) return 1;
  long long ret = fat[a];
  ret = ret * inv(fat[b]) % MOD * inv(fat[a - b]) % MOD;
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  fato();
  cin >> n >> m;
  if (n == 2) return cout << m << '\n', 0;
  long long ans = 0;
  long long g = n - 1;
  for (g; g <= m; g++) {
    long long mul = g - 1;
    long long com = comb(g - 2, n - 3);
    long long n_caras = n - 3;
    ans = ans + mul * com % MOD * pow(2, n_caras, MOD) % MOD;
    ans %= MOD;
  }
  cout << ans << '\n';
  exit(0);
}
