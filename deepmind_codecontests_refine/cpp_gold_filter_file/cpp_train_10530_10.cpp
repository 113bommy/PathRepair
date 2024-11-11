#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 1e9 + 7;
constexpr int kMaxN = 1e5 + 3;
constexpr int kMaxM = 4;
constexpr int kMaxK = 14;
int bits[1 << kMaxM];
int dp[kMaxN][kMaxK][1 << kMaxM];
void add_self(int& a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}
int mul(int a, int b) { return (ll)a * b % mod; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k, m;
  cin >> n >> k >> m;
  for (int i = 1; i < (1 << kMaxM); ++i) {
    bits[i] = __builtin_popcount(i);
  }
  dp[n][0][0] = 1;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j <= k; ++j) {
      for (int mask = 0; mask < (1 << m); ++mask) {
        add_self(dp[i][j][mask >> 1], dp[i + 1][j][mask]);
        if (j < k) {
          add_self(dp[i][j + 1][(mask | (1 << m)) >> 1],
                   mul(dp[i + 1][j][mask], 1 + bits[mask]));
        }
      }
    }
  }
  int total = 0;
  for (int i = 0; i < (1 << m); ++i) {
    add_self(total, dp[0][k][i]);
  }
  cout << total << '\n';
  return 0;
}
