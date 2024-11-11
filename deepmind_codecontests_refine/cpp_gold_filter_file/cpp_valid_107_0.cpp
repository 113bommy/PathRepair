#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const long long mod = 1e9 + 7;
inline long long gcd(long long a, long long b) {
  return !b ? a : gcd(b, a % b);
}
inline long long q_pow(long long a, long long x = mod - 2) {
  long long ans = 1, tmp = a;
  while (x) {
    if (x & 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    x >>= 1;
  }
  return ans;
}
template <typename T>
inline void re(T &N) {
  int f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') f = -1;
  N = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') N = N * 10 + c - '0';
  N *= f;
}
template <class T, class... T_>
inline void re(T &x, T_ &...y) {
  re(x), re(y...);
}
int m, n, t = 1, st, en;
pair<long long, long long> a[N];
pair<long long, long long> dp[210][210];
pair<long long, long long> dfs(int l, int r, long long mid) {
  if (l + 1 == r) return {0, 0};
  if (~dp[l][r].first) return dp[l][r];
  auto &ans = dp[l][r] = {0, 0};
  for (int i = l + 1; i < r; i++) {
    auto dl = dfs(l, i, mid);
    auto dr = dfs(i, r, mid);
    auto area = [&](int i, int j, int k) {
      auto det = [&](int i, int j) {
        return a[i].first * a[j].second - a[i].second * a[j].first;
      };
      return det(i, j) + det(j, k) + det(k, i);
    };
    pair<long long, long long> tmp = {dl.first + dr.first,
                                      dl.second + dr.second + area(l, i, r)};
    if (tmp.second >= mid) tmp.first++, tmp.second = 0;
    ans = max(ans, tmp);
  }
  return ans;
}
int main() {
  re(n, m);
  for (int i = 1; i <= n; i++) re(a[i].first, a[i].second);
  long long l = 0, r = 2e17, ans = l;
  while (l <= r) {
    auto check = [&](long long mid) {
      memset(dp, -1, sizeof(dp));
      pair<long long, long long> ans = dfs(1, n, mid);
      return ans.first > m;
    };
    long long mid = (l + r) >> 1;
    if (check(mid))
      l = mid + 1, ans = mid;
    else
      r = mid - 1;
  }
  printf("%lld\n", ans);
}
