#include <bits/stdc++.h>
using namespace std;
template <typename P, typename Q>
P CeilDiv(P _dividend, Q _divider) {
  return static_cast<P>((_dividend - 1LL + _divider) / _divider);
}
template <typename Tp>
inline void outarr(Tp _begin, Tp _end, const char* _delim = " ") {
  for (Tp current = _begin; current != _end; ++current) {
    std::cout << *current << _delim;
  }
  std::cout << '\n';
}
using ll = long long;
using pii = std::pair<int, int>;
constexpr int INF = 0x3f3f3f3f;
constexpr int MOD = static_cast<int>(1e9 + 7);
int Add(int x, int y) {
  x += y;
  return x < MOD ? x : x - MOD;
}
int Sub(int x, int y) {
  x -= y;
  return x >= 0 ? x : x + MOD;
}
int Mul(int x, int y) { return int(1LL * x * y % MOD); }
int FastPow(int x, int p) {
  int res = 1;
  while (p > 0) {
    if (p & 1) {
      res = Mul(res, x);
    }
    p >>= 1;
    x = Mul(x, x);
  }
  return res;
}
int Inv(int x) { return FastPow(x, MOD - 2); }
bool HasBit(int x, int b) { return (x >> b) & 1; }
void SolveTask() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  vector<vector<int>> prob(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      prob[i][j] = Mul(arr[i], Inv(arr[i] + arr[j]));
    }
  }
  const int full_mask = 1 << n;
  vector<int> dp(full_mask, 1);
  for (int mask = 1; mask < full_mask; ++mask) {
    for (int sub = mask - 1; sub > 0; --sub) {
      sub &= mask;
      int p = 1;
      for (int a = 0; a < n; ++a) {
        if (HasBit(sub, a)) {
          for (int b = 0; b < n; ++b) {
            if (HasBit(mask ^ sub, b)) {
              p = Mul(p, prob[a][b]);
            }
          }
        }
      }
      dp[mask] = Sub(dp[mask], Mul(dp[sub], p));
    }
  }
  vector<int> kbit(full_mask, 0);
  int ans = 0;
  for (int mask = 1; mask < full_mask; ++mask) {
    kbit[mask] = kbit[mask >> 1] + (mask & 1);
    for (int a = 0; a < n; ++a) {
      if (HasBit(mask, a)) {
        for (int b = 0; b < n; ++b) {
          if (!HasBit(mask, b)) {
            dp[mask] = Mul(dp[mask], prob[a][b]);
          }
        }
      }
    }
    ans = Add(ans, Mul(dp[mask], kbit[mask]));
  }
  cout << ans << "\n";
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int test_cases = 1;
  for (int yt = 1; yt <= test_cases; ++yt) {
    SolveTask();
  }
  return 0;
}
