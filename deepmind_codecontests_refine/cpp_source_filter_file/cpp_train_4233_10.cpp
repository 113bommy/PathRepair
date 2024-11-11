#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")
const long long maxn = 5e5 + 20, maxm = 5e4 + 10, lg = 21, mod = 1e9 + 7,
                inf = 1e18;
struct fem {
  long long bit[maxn], mem[maxn];
  fem() { memset(bit, 0, sizeof(bit)); }
  void ok(long long x) {
    if (x >= mod) x -= mod;
    if (x < 0) x += mod;
  }
  void add(long long i, long long x) {
    for (ok(mem[i++] += x); i < maxn; i += (-i & i)) ok(bit[i] += x);
  }
  long long get(long long i = maxn - 50) {
    long long ret = 0;
    for (i++; i; i -= (-i & i)) ok(ret += bit[i]);
    return ret;
  }
} f[2];
long long pwm(long long b) {
  long long ret = 1, a = 2;
  for (; b; b /= 2, (a *= a) %= mod)
    if (b % 2) (ret *= a) %= mod;
  return ret;
}
void maxi(long long &x, long long y) { x = max(x, y); }
long long k, n, m, L[maxn], R[maxn], rq[2][maxn], las[maxn];
vector<long long> cum;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> k >> n >> m;
  cum.push_back(0), cum.push_back(1), cum.push_back(k);
  for (int i = 0; i < n + m; i++)
    cin >> L[i] >> R[i], cum.push_back(L[i]), cum.push_back(R[i]);
  sort(cum.begin(), cum.end()),
      cum.resize(unique(cum.begin(), cum.end()) - cum.begin());
  for (int i = 0; i < n + m; i++)
    maxi(rq[i < n]
           [R[i] = lower_bound(cum.begin(), cum.end(), R[i]) - cum.begin()],
         (L[i] = lower_bound(cum.begin(), cum.end(), L[i]) - cum.begin()));
  f[0].add(0, 1), f[1].add(0, 1);
  for (int i = 1; i < (long long)(cum.size()); i++) {
    for (int b : {0, 1})
      for (; las[b] < rq[!b][i]; las[b]++) f[b].add(las[b], -f[b].mem[las[b]]);
    if (i < (long long)(cum.size()) - 1)
      for (int b : {0, 1})
        f[b].add(i, ((f[b].get(i - 1) *
                      ((pwm(cum[i + 1] - cum[i] - 1) - 1 + mod) % mod) % mod) +
                     (f[!b].get(i - 1) * pwm(cum[i + 1] - cum[i] - 1) % mod)) %
                        mod);
  }
  cout << (f[0].get() + f[1].get()) % mod;
  return 0;
}
