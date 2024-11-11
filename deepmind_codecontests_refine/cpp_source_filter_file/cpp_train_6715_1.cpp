#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000 * 1000 * 1000 + 7;
int n, k;
vector<int> a;
vector<pair<int, int> > b;
long long len;
vector<vector<long long> > dp;
vector<vector<long long> > tp;
int main() {
  cin >> n >> len >> k;
  a = vector<int>(n);
  for (int i = 0; i < (int)(n); i++) scanf("%d", &a[i]);
  for (int i = 0; i < (int)(n); i++) b.push_back(make_pair(a[i], i));
  sort(b.begin(), b.end());
  dp = vector<vector<long long> >(k + 1, vector<long long>(n, 0));
  for (int i = 0; i < (int)(n); i++) dp[1][i] = 1;
  for (int j = 1; j < k; j++) {
    vector<long long> sum(n + 1, 0);
    for (int i = 0; i < (int)(n); i++) {
      sum[i + 1] = (sum[i] + dp[j][i]) % MOD;
    }
    int l = 0;
    while (l < n) {
      int r = l;
      while (r < n && b[l].first == b[r].first) r++;
      for (int i = l; i < r; i++) {
        dp[j + 1][i] = sum[r];
      }
      l = r;
    }
  }
  tp = dp;
  for (int j = 0; j < (int)(k + 1); j++) {
    for (int i = 0; i < (int)(n); i++) {
      tp[j][b[i].second] = dp[j][i];
    }
  }
  long long ans = 0;
  for (int x = 1; x <= k; x++) {
    long long blocks = len / n;
    if (x <= blocks) {
      long long ways = 0;
      for (int i = 0; i < (int)(n); i++) {
        ways = (ways + tp[x][i]) % MOD;
      }
      ways *= (blocks - x + 1);
      ans = (ans + ways) % MOD;
    }
    if (x - 1 <= blocks) {
      int r = int(len % n);
      if (r > 0) {
        long long ways = 0;
        for (int i = 0; i < (int)(r); i++) {
          ways = (ways + tp[x][i]) % MOD;
        }
        ans = (ans + ways) % MOD;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
