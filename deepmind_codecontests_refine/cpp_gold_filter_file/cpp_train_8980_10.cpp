#include <bits/stdc++.h>
const int MOD = 1000000007;
int modpow(int a, int e) {
  int ret = 1;
  while (e > 0) {
    if (e & 1) ret = (1ll * ret * a) % MOD;
    a = (1ll * a * a) % MOD;
    e >>= 1;
  }
  return ret;
}
std::vector<int> fact, invfact;
int binco(int n, int k) {
  if (k < 0 || k > n) return 0;
  int xd = (1ll * fact[n] * invfact[k]) % MOD;
  return (1ll * xd * invfact[n - k]) % MOD;
}
int pref[2005][2005];
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  const int N = 100000;
  fact.resize(N);
  invfact.resize(N);
  fact[0] = invfact[0] = 1;
  for (int i = (1); i < (N); ++i)
    fact[i] = (1ll * fact[i - 1] * i) % MOD,
    invfact[i] = modpow(fact[i], MOD - 2);
  int n, m, r;
  std::cin >> n >> m >> r;
  std::vector<std::pair<std::pair<int, int>, int> > A;
  for (int i = 0; i < (n); ++i) {
    int x, y, b;
    std::cin >> x >> y >> b;
    A.push_back(std::make_pair(std::make_pair(x, y), b));
  }
  auto dist = [&](std::pair<int, int> a, std::pair<int, int> b) {
    return std::max(std::abs(a.first - b.first), std::abs(a.second - b.second));
  };
  for (auto& i : (A)) {
    pref[i.first.first][i.first.second]++;
  }
  for (int i = 0; i < (2005); ++i) {
    for (int j = 0; j < (2005); ++j) {
      if (i > 0) pref[i][j] += pref[i - 1][j];
      if (j > 0) pref[i][j] += pref[i][j - 1];
      if (i > 0 && j > 0) pref[i][j] -= pref[i - 1][j - 1];
    }
  }
  std::vector<int> cnt(n);
  int ans = 0;
  for (int i = 0; i < (n); ++i) {
    std::pair<int, int> xx = A[i].first;
    for (auto& pr : (A)) {
      if (dist(xx, pr.first) <= r) cnt[i]++;
    }
  }
  auto g1 = [&](int res, int a) {
    int xd = binco(res + a, m);
    xd -= binco(res, m);
    if (xd < 0) xd += MOD;
    return xd;
  };
  auto g2 = [&](int res, int a, int b) {
    int xd = binco(res + a + b, m);
    xd -= binco(res + a, m) + binco(res + b, m);
    xd %= MOD;
    xd += binco(res, m);
    xd %= MOD;
    if (xd < 0) xd += MOD;
    return xd;
  };
  auto przec = [&](std::pair<int, int> a, std::pair<int, int> b) {
    std::pair<int, int> x = std::make_pair(std::max(a.first - r, b.first - r),
                                           std::min(a.first + r, b.first + r));
    std::pair<int, int> y =
        std::make_pair(std::max(a.second - r, b.second - r),
                       std::min(a.second + r, b.second + r));
    if (x.first > x.second || y.first > y.second) return 0;
    if (x.second > 2000) x.second = 2000;
    if (y.second > 2000) y.second = 2000;
    if (x.first < 1) x.first = 1;
    if (y.first < 1) y.first = 1;
    return pref[x.second][y.second] - pref[x.first - 1][y.second] -
           pref[x.second][y.first - 1] + pref[x.first - 1][y.first - 1];
  };
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (n); ++j) {
      if (i == j) {
        int c = cnt[i];
        int rest = n - c;
        ans = (ans +
               1ll * (1ll * g1(rest, c) * A[i].second % MOD) * A[j].second) %
              MOD;
      } else {
        int p = przec(A[i].first, A[j].first);
        int a = cnt[i] - p;
        int b = cnt[j] - p;
        assert(a >= 0 && b >= 0);
        assert(p >= 0);
        int rest = n - a - b - p;
        assert(rest >= 0);
        ans = (ans +
               1ll * (1ll * g2(rest, a, b) * A[i].second % MOD) * A[j].second) %
              MOD;
        ans = (ans +
               1ll * (1ll * g1(n - p, p) * A[i].second % MOD) * A[j].second) %
              MOD;
      }
    }
  std::cout << ans << "\n";
  return 0;
}
