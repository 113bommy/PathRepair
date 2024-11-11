#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 55;
const int mod = 1e9 + 7;
ll dp[55][55][2];
ll C[55][55];
int n, k;
ll fast(ll b, ll e) {
  if (!e) return 1;
  if (e & 1) return b * fast(b, e - 1) % mod;
  return fast(b * b % mod, e >> 1);
}
bool mrg(bool l, bool r) { return !(l | r); }
ll inv2 = fast(2, mod - 2);
ll solve(int sz, int matching, bool isLeaf) {
  if (sz <= 0 || matching < 0) return 0;
  if (sz == 1) return matching == 0 && isLeaf;
  ll &ret = dp[sz][matching][isLeaf];
  if (~ret) return ret;
  ret = 0;
  ret += solve(sz - 1, matching - (!isLeaf), (!isLeaf));
  for (int szLeft = 1; szLeft <= sz - 1 - szLeft; szLeft++) {
    int szRight = sz - szLeft - 1;
    for (int matchingLeft = 0;
         matchingLeft <= matching - (!isLeaf) &&
         (szLeft != sz - 1 - szLeft ||
          matchingLeft <= (matching - matchingLeft - (!isLeaf)));
         matchingLeft++) {
      int matchingRight = matching - (!isLeaf) - matchingLeft;
      for (int isLeafLeft = 0; isLeafLeft < 2; isLeafLeft++) {
        for (int isLeafRight = 0; isLeafRight < 2; isLeafRight++) {
          if (mrg(isLeafLeft, isLeafRight) != isLeaf) continue;
          ll add = solve(szLeft, matchingLeft, isLeafLeft) *
                   solve(szRight, matchingRight, isLeafRight) % mod;
          add = add * C[sz - 1][szLeft] % mod;
          if (szLeft == szRight && matchingLeft == matchingRight) {
            add = (add * inv2) % mod;
          }
          ret += add;
          while (ret >= mod) ret -= mod;
        }
      }
    }
  }
  ret *= sz;
  ret %= mod;
  return ret;
}
void init() {
  for (int i = 0; i < N; i++)
    for (int j = 0; j <= i; j++) {
      if (i == j || j == 0)
        C[i][j] = 1;
      else
        C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
}
int main() {
  init();
  memset(dp, -1, sizeof dp);
  cin >> n >> k;
  ll out = (solve(n, k, 0) + solve(n, k, 1)) % mod;
  out = out * fast(n, mod - 2) % mod;
  cout << out << '\n';
  return 0;
}
