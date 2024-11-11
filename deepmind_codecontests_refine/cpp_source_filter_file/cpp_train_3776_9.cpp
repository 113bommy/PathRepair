#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 9, M = 42, MOD = 998244353;
long long fact[N], inv[N];
pair<long long, long long> seg[N], con[N];
long long fen[N], ps[M][N], a[N];
void ADD(long long ind, long long val) {
  for (; ind < N; ind += ind & -ind) fen[ind] += val;
}
long long SUM(long long ind) {
  long long sum = 0;
  for (; ind > 0; ind -= ind & -ind) sum += fen[ind];
  return sum;
}
long long POW(long long a, long long b) {
  if (b == 0) return 1;
  long long ans = POW(a, b / 2);
  ans = (ans * ans) % MOD;
  if (b % 2) ans = (ans * a) % MOD;
  return ans;
}
long long C(long long a, long long b) {
  if (a < 0 || b < 0 || b > a) return 0;
  return (fact[a] * ((inv[b] * inv[a - b]) % MOD)) % MOD;
}
void PREP() {
  fact[0] = 1;
  for (long long i = 1; i < N; i++) fact[i] = (fact[i - 1] * i) % MOD;
  for (long long i = 0; i < N; i++) inv[i] = POW(fact[i], MOD - 2);
}
long long PSUM(long long l, long long r, long long k) {
  return (ps[k][r] - ps[k][l - 1] + MOD) % MOD;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  PREP();
  long long n, m;
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    long long l, r;
    cin >> l >> r;
    ADD(l, 1);
    ADD(r + 1, -1);
    seg[i] = {l, r};
  }
  for (long long i = 0; i < m; i++) {
    cin >> con[i].first >> con[i].second;
    con[i].first--;
    con[i].second--;
  }
  for (long long i = 1; i <= n; i++) a[i] = SUM(i);
  for (long long i = 0; i < 20; i++) {
    for (long long j = 1; j <= n; j++) {
      ps[i][j] = (ps[i][j - 1] + C(a[j] - i, j - i)) % MOD;
    }
  }
  long long ans = ps[0][n];
  for (long long mask = 1; mask < (1 << m); mask++) {
    long long mxl = 0, mnr = N;
    set<long long> s;
    for (long long i = 0; i < m; i++)
      if (mask & (1 << i)) {
        long long x = con[i].first, y = con[i].second;
        s.insert(x);
        s.insert(y);
        mxl = max(mxl, max(seg[x].first, seg[y].first));
        mnr = min(mnr, min(seg[x].second, seg[y].second));
      }
    if (mxl > mnr) continue;
    if (__builtin_popcount(mask) % 2)
      ans = (ans - PSUM(mxl, mnr, (long long)s.size()) + MOD) % MOD;
    else
      ans = (ans + PSUM(mxl, mnr, (long long)s.size()) + MOD) % MOD;
  }
  cout << ans << endl;
  return 0;
}
