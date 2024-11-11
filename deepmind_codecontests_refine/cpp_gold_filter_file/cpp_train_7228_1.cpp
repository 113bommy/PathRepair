#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int NAX = 2e5 + 5, MOD = 1000000007;
int n;
int c[30];
int second[1 << 13];
char dp[13][1 << 13][25];
class Solution {
 private:
  char first(int pos, int mask, int leaves) {
    if (c[pos] == 1) return leaves == 0;
    if ((mask >> pos) & 1) return 0;
    char &res = dp[pos][mask][leaves];
    if (res != -1) return res;
    res = 0;
    for (int nmask = mask;; nmask = (nmask - 1) & mask) {
      int tmp = __builtin_popcount(nmask);
      if (second[nmask] <= c[pos] - 1) {
        int take = c[pos] - 1 - second[nmask];
        if (take <= leaves && take + tmp > 1) {
          char cres = first(pos + 1, mask ^ nmask, leaves - take);
          res |= cres;
        }
      }
      if (nmask == 0) break;
    }
    return res;
  }

 public:
  Solution() {}
  ~Solution() {}
  void solveCase() {
    int n;
    cin >> n;
    int leaves = 0;
    bool bad = false;
    for (size_t i = 0; i < n; i++) {
      cin >> c[i];
      leaves += c[i] == 1;
      bad |= c[i] == 2;
    }
    if (n == 1) {
      if (c[0] == 1)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else {
      int inner = n - leaves;
      if (2 * leaves <= n || bad) {
        cout << "NO\n";
      } else {
        sort(c, c + n);
        reverse(c, c + n);
        memset(dp, -1, sizeof dp);
        for (size_t mask = 0; mask < (1 << inner); mask++) {
          second[mask] = 0;
          for (size_t i = 0; i < inner; i++)
            if ((mask >> i) & 1) second[mask] += c[i];
        }
        if (first(0, ((1 << inner) - 1) ^ 1, leaves))
          cout << "YES\n";
        else
          cout << "NO\n";
      }
    }
  }
};
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  Solution mySolver;
  for (int i = 1; i <= t; ++i) {
    mySolver.solveCase();
  }
  return 0;
}
