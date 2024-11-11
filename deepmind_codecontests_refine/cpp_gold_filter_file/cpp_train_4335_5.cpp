#include <bits/stdc++.h>
using namespace std;
long long expo(long long base, long long exponent, long long mod) {
  long long ans = 1;
  while (exponent != 0) {
    if (exponent & 1) ans = (1LL * ans * base) % mod;
    base = (1LL * base * base) % mod;
    exponent >>= 1;
  }
  return ans % mod;
}
long long euclid(long long a, long long b, long long &first,
                 long long &second) {
  if (b) {
    long long d = euclid(b, a % b, second, first);
    return second -= a / b * first, d;
  }
  return first = 1, second = 0, a;
}
long long chinese(long long a, long long m, long long b, long long n) {
  long long first, second;
  euclid(m, n, first, second);
  long long ret = a * (second + m) % m * n + b * (first + n) % n * m;
  if (ret >= m * n) ret -= m * n;
  return ret;
}
vector<pair<long long, long long> > fac;
long long f[20][200005];
long long powers[20][200005];
long long inv[20][200005];
long long mod[20];
long long modpows[20][50];
long long C(long long n, long long r) {
  if (n < 0 or r < 0 or n < r) return 0;
  long long ans = 0, currem = 1;
  for (long long i = 0; i < (long long)fac.size(); i++) {
    long long s = powers[i][n] - powers[i][r] - powers[i][n - r];
    long long rem = f[i][n] * inv[i][r] % mod[i];
    rem = rem * inv[i][n - r] % mod[i];
    if (s >= fac[i].second)
      rem = 0;
    else
      rem = rem * modpows[i][s] % mod[i];
    ans = chinese(ans, currem, rem, mod[i]);
    currem *= mod[i];
  }
  return ans;
}
long long n, p, l, r;
void pre() {
  for (long long i = 2; i * i <= p; i++) {
    if (p % i == 0) {
      long long cnt = 0;
      while (p % i == 0) {
        cnt++;
        p /= i;
      }
      fac.push_back({i, cnt});
    }
  }
  if (p > 1) fac.push_back({p, 1});
  for (long long i = 0; i < (long long)fac.size(); i++) {
    modpows[i][0] = 1;
    for (long long j = 1; j < fac[i].second + 1; j++)
      modpows[i][j] = modpows[i][j - 1] * fac[i].first;
  }
  for (long long i = 0; i < (long long)fac.size(); i++) {
    mod[i] = modpows[i][fac[i].second];
    f[i][0] = 1;
    for (long long j = 1; j < 2 * n + 1; j++) {
      long long d = j;
      powers[i][j] = powers[i][j - 1];
      while (d % fac[i].first == 0) d /= fac[i].first, powers[i][j]++;
      f[i][j] = f[i][j - 1] * d % mod[i];
    }
    inv[i][2 * n] = expo(
        f[i][2 * n], (mod[i] / fac[i].first) * (fac[i].first - 1) - 1, mod[i]);
    for (long long j = 2 * n - 1; j >= 0; j--) {
      long long d = (j + 1);
      while (d % fac[i].first == 0) d /= fac[i].first;
      inv[i][j] = inv[i][j + 1] * d % mod[i];
    }
  }
}
void solve() {
  cin >> n >> p >> l >> r;
  long long P = p, ans = 0;
  pre();
  for (long long i = l; i < n + 1; i++)
    ans =
        (ans + C(n, i) * (C(i, (i - l) / 2) - C(i, (i - r + 1) / 2 - 1) + P)) %
        P;
  cout << ans << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
