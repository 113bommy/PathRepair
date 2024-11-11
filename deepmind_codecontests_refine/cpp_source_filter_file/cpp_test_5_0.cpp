#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
const long long Mod = 1000000007LL;
const int N = 1e5 + 10;
const long long Inf = 2242545357980376863LL;
const int Log = 20;
long long mul(long long a, long long b) { return (a * b) % Mod; }
long long bin_pow(long long b, long long p) {
  long long res = 1;
  for (long long j = 1, pw = b; j <= p; j <<= 1, pw = mul(pw, pw))
    if (p & j) res = mul(res, pw);
  return res;
}
long long inv(long long x) { return bin_pow(x, Mod - 2); }
long long f[N];
long long fc[N];
long long E[N], cz[N];
long long poly[N], E2[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fc[0] = 1;
  for (int i = 1; i < N; i++) fc[i] = mul(fc[i - 1], i);
  long long n, k;
  cin >> n >> k;
  long long ik = inv(k);
  long long ia = inv(mul(n, k));
  long long C = 0;
  for (int i = 0; i < n; i++) {
    long long no = mul((i + (n - i) * (k - 1)) % Mod, ia);
    long long dec = mul(mul(i, (k - 1)), ia);
    long long con = 1;
    long long z = no + dec;
    if (i) con += mul(dec, f[i - 1]);
    f[i] = mul(con, inv(1 - z));
    (C += f[i]) %= Mod;
  }
  E[n] = 0;
  for (int i = n - 1; i >= 0; i--) E[i] = f[i] + E[i + 1];
  map<int, long long> mp;
  int v;
  cz[0] = k;
  for (int i = 0; i < n; i++) {
    cin >> v;
    mp[v]++;
  }
  long long c = mp[-1];
  long long den = inv(bin_pow(k, c));
  for (int i = 0; i <= c; i++)
    poly[i] =
        mul(mul(bin_pow(k - 1, c - i), mul(fc[c], inv(mul(fc[i], fc[c - i])))),
            den);
  for (auto [val, cnt] : mp) {
    if (val == -1) continue;
    cz[0]--;
    cz[cnt]++;
  }
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    if (cz[i] == 0) continue;
    for (int j = 0; j <= c; j++) (E2[i + j] += mul(cz[i], poly[j])) %= Mod;
  }
  for (int i = 0; i <= n; i++) (ans += mul(E[i], E2[i])) %= Mod;
  ans -= mul(k - 1, C);
  ans %= Mod;
  ans = mul(ans, ik);
  ans += Mod;
  cout << ans % Mod << '\n';
  return 0;
}
