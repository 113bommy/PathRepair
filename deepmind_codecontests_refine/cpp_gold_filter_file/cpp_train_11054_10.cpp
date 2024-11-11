#include <bits/stdc++.h>
using namespace std;
long long n, x, k, z, m, pos, q;
long long b[100500];
vector<long long> g, f;
long long a[400500];
long long pa[400500][22], sum[22], pr[22][22];
long long dp[1048576 + 15];
long long get_sum(long long num, long long l, long long r) {
  return pa[r + 1][num] - pa[l][num];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 1; j <= 20; j++) {
      pa[i + 1][j] = pa[i][j];
    }
    pa[i + 1][a[i]]++;
    for (int j = 1; j <= 20; j++) {
      pr[a[i]][j] += get_sum(j, 0, i);
    }
    sum[a[i]]++;
  }
  dp[0] = 0;
  for (int i = 1; i < 1048576; i++) {
    dp[i] = 1LL * 1000000007 * 1000000007;
  }
  for (int i = 0; i < 1048576; i++) {
    long long sm = 0;
    for (int j = 0; j < 20; j++) {
      if ((i >> j) & 1) {
        sm += sum[j + 1];
      }
    }
    for (int j = 0; j < 20; j++) {
      if (!((i >> j) & 1)) {
        long long need = 0;
        for (int k = 0; k < 20; k++) {
          if (k != j && !((i >> k) & 1)) {
            need += pr[j + 1][k + 1];
          }
        }
        dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + need);
      }
    }
  }
  cout << dp[1048576 - 1] << endl;
  return 0;
}
