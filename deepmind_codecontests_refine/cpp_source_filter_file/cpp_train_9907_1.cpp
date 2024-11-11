#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> v;
  vector<int> minpos(n, m), maxpos(n, 0);
  int last = -1;
  vector<int> stack;
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    --x;
    if (x == last) continue;
    last = x;
    v.push_back(x);
    minpos[x] = min(minpos[x], int(v.size()) - 1);
    maxpos[x] = max(maxpos[x], int(v.size()) - 1);
  }
  int k = v.size();
  cerr << "K: " << k << endl;
  for (int i = 0; i < k; ++i) {
    for (int p = minpos[i]; p <= maxpos[i]; ++p)
      if (v[p] < i) {
        cout << 0 << endl;
        return 0;
      }
  }
  vector<vector<long long>> dp(k + 1, vector<long long>(k + 1, 1));
  for (int l = k - 1; l >= 0; --l) {
    int c = n;
    for (int r = l + 1; r <= k; ++r) {
      c = min(c, v[r - 1]);
      int minp = minpos[c];
      int maxp = maxpos[c];
      if (minp < l or maxp >= r) {
        dp[l][r] = 0;
        continue;
      }
      long long leftways = 0, rightways = 0;
      for (int l2 = l; l2 <= minp; ++l2)
        leftways = (leftways + dp[l][l2] * dp[l2][minp] % mod) % mod;
      for (int r2 = maxp + 1; r2 <= r; ++r2)
        rightways = (rightways + dp[maxp + 1][r2] * dp[r2][r] % mod) % mod;
      leftways %= mod;
      rightways %= mod;
      dp[l][r] = leftways * rightways % mod;
      int left = -1, right = -1;
      assert(v[minp] == c);
      assert(v[maxp] == c);
      for (int i = minp; i <= maxp; ++i) {
        if (v[i] != c)
          right = i + 1;
        else {
          if (right > left) {
            assert(left != -1);
            dp[l][r] = dp[l][r] * dp[left][right] % mod;
          }
          left = i + 1;
          right = i + 1;
        }
      }
    }
  }
  cout << dp[0][k] << endl;
}
