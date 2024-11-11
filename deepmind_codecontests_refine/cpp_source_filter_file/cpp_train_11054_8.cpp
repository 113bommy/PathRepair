#include <bits/stdc++.h>
using namespace std;
int a[400005];
vector<int> v[20];
int sum[20][20];
long long dp[1 << 20];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
    v[a[i]].push_back(i);
  }
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      if (i == j) continue;
      int p = 0;
      for (int k = 0; k < v[j].size(); k++) {
        while (p < v[i].size() && v[i][p] < v[j][k]) p++;
        sum[i][j] += p;
      }
    }
  }
  for (int i = 0; i < (1 << 20); i++) dp[i] = 1e18;
  dp[0] = 0;
  for (int i = 0; i < (1 << 20); i++) {
    vector<int> v;
    for (int j = 0; j < 20; j++) {
      if ((i >> j) & 1) continue;
      v.push_back(j);
    }
    for (int j = 0; j < 20; j++) {
      if ((i >> j) & 1) {
        long long res = 0;
        for (int k = 0; k < v.size(); k++) res += sum[v[k]][j];
        dp[i] = min(dp[i], dp[i ^ (1 << j)] + res);
      }
    }
  }
  printf("%lld\n", dp[(1 << 20) - 1]);
}
