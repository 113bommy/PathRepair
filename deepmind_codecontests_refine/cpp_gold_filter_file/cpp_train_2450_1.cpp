#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;
using vs = vector<string>;
using vpi = vector<pi>;
using ll = long long int;
template <typename T>
string tostr(T x) {
  ostringstream oss;
  oss << x;
  return oss.str();
}
template <typename T1, typename T2, typename T3>
T1 modpow(T1 a, T2 p, T3 mod) {
  T1 ret = 1;
  a %= mod;
  for (; p > 0; p /= 2) {
    if (p & 1) ret = 1ll * ret * a % mod;
    a = 1ll * a * a % mod;
  }
  return ret;
}
int dx[]{-1, 0, 1, 0, 1, 1, -1, -1};
int dy[]{0, -1, 0, 1, 1, -1, 1, -1};
constexpr auto PI = 3.14159265358979323846L;
constexpr auto oo = numeric_limits<int>::max() / 2 - 10;
constexpr auto eps = 1e-6;
constexpr auto mod = 1000000007;
constexpr int mx = 300005, mx_c = 20;
int n, num[mx], powers[mx];
int fact[mx], ifact[mx];
int mul[mx], csum[mx];
int primes[mx / 10], pcnt;
int cnt[mx / 10][mx_c];
int idx[mx];
vpi divs[mx];
void seive() {
  for (int i = 2; i < mx; ++i)
    if ((int)(divs[i].size()) == 0) {
      for (int j = i; j < mx; j += i) {
        int c = 1;
        for (int t = j / i; t % i == 0; t /= i) ++c;
        divs[j].push_back(make_pair(pcnt, c));
      }
      primes[pcnt++] = i;
    }
}
int comb(int n, int k) {
  if (k > n) return 0;
  return 1ll * fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}
void init() {
  seive();
  fact[0] = 1;
  for (auto i = 1, _i = (mx); i < _i; ++i)
    fact[i] = 1ll * fact[i - 1] * i % mod;
  for (auto i = 0, _i = (mx); i < _i; ++i)
    ifact[i] = modpow(fact[i], mod - 2, mod);
  int cur = (modpow(2, n - 1, mod) + mod - 1) % mod;
  for (auto i = 0, _i = (n / 2); i < _i; ++i) {
    mul[i] = (mod - cur) % mod;
    mul[n - 1 - i] = cur;
    cur = (cur - comb(n, i + 1) + mod) % mod;
  }
  csum[0] = mul[0];
  for (auto i = 1, _i = (mx); i < _i; ++i) {
    csum[i] = (csum[i - 1] + mul[i]);
    if (csum[i] >= mod) csum[i] -= mod;
  }
}
void analyze(int n) {
  vi cnt(n);
  for (auto mask = 1, _mask = ((1 << n)); mask < _mask; ++mask) {
    int a = 0, b = __builtin_popcount(mask);
    --b;
    for (auto i = 0, _i = (n); i < _i; ++i)
      if (((mask >> i) & 1)) {
        if (a > b)
          --cnt[i];
        else if (a < b)
          ++cnt[i];
        ++a;
        --b;
      }
  };
}
int get(int a, int b) {
  assert(a <= b);
  int ret = csum[b];
  if (a > 0) ret = (ret - csum[a - 1] + mod) % mod;
  return ret;
}
int main() {
  scanf("%d", &n);
  init();
  for (auto j = 0, _j = (pcnt); j < _j; ++j) cnt[j][0] = n;
  for (auto i = 0, _i = (n); i < _i; ++i) {
    scanf("%d", num + i);
    for (auto entry : divs[num[i]]) {
      ++cnt[entry.first][entry.second];
      --cnt[entry.first][0];
    }
  }
  int ans = 0;
  for (auto j = 0, _j = (pcnt); j < _j; ++j) {
    int sofar = 0;
    for (auto i = 0, _i = (mx_c); i < _i; ++i)
      if (cnt[j][i]) {
        ans = (ans + 1ll * i * get(sofar, sofar + cnt[j][i] - 1)) % mod;
        sofar += cnt[j][i];
      }
  }
  printf("%d\n", ans);
  return 0;
}
