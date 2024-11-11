#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
const long double PI = acos(0.0) * 2.0;
mt19937_64 rng((unsigned long long)new char);
const int mod = 1e9 + 7;
const long long INF = 9e18;
const int maxn = 1e5 + 10;
const int maxl = 110;
int n;
int a[maxn];
vector<int> yz[maxn];
long long ksm(long long a, long long x = mod - 2) {
  long long w = 1;
  while (x) {
    if (x & 1) w = w * a % mod;
    x >>= 1, a = a * a % mod;
  }
  return w;
}
int lb[maxn];
long long inv[maxn];
struct miu {
  bool check[maxn + 10];
  int prime[maxn + 10];
  int mu[maxn + 10];
  void run() {
    memset(check, false, sizeof(check));
    mu[1] = 1;
    int tot = 0;
    for (int i = 2; i <= maxn; i++) {
      if (!check[i]) {
        prime[tot++] = i;
        mu[i] = -1;
      }
      for (int j = 0; j < tot; j++) {
        if (i * prime[j] > maxn) break;
        check[i * prime[j]] = true;
        if (i % prime[j] == 0) {
          mu[i * prime[j]] = 0;
          break;
        } else {
          mu[i * prime[j]] = -mu[i];
        }
      }
    }
  }
} so;
long long f[maxn];
long long f1(int x) {
  if (x == 1) return 1;
  long long o = 1;
  for (int t = (0); t < (yz[x].size()); ++t) {
    auto& cur = yz[x][t];
    int nx = t == yz[x].size() - 1 ? maxn - 1 : yz[x][t + 1];
    int cnt = lb[nx] - lb[cur];
    o = o * ksm(t + 1, cnt) % mod;
  }
  return o;
}
long long F(int x) {
  long long ans = 1;
  auto& e = yz[x];
  if (x == 1) return 1;
  for (int i = (0); i < (e.size() - 1); ++i) {
    ans = ans * ksm(i + 1, lb[e[i + 1]] - lb[e[i]]) % mod;
  }
  int le = lb[maxn - 1] - lb[x];
  ans *= (ksm(e.size(), le) - ksm(e.size() - 1, le));
  return ans % mod;
}
int main() {
  for (int i = 1; i < maxn; ++i)
    for (int j = i; j < maxn; j += i) yz[j].push_back(i);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = (0); i < (n); ++i) cin >> a[i];
  sort(a, a + n);
  for (int i = (1); i < (maxn); ++i) lb[i] = lower_bound(a, a + n, i) - a;
  long long ans = 0;
  for (int i = (1); i < (maxn); ++i) ans = (ans + F(i)) % mod;
  ans += mod, ans %= mod;
  cout << ans;
}
