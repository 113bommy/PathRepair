#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
long long dp1[35][maxn], dp2[35][maxn], fa[35][maxn];
long long n, k;
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> fa[0][i];
  for (int i = 0; i < n; i++) {
    cin >> dp1[0][i];
    dp2[0][i] = dp1[0][i];
  }
  for (int i = 1; (1LL << i) <= k; i++) {
    for (int j = 0; j < n; j++) {
      dp1[i][j] = dp1[i - 1][j] + dp1[i - 1][fa[i - 1][j]];
      dp2[i][j] = min(dp2[i - 1][j], dp2[i - 1][fa[i - 1][j]]);
      fa[i][j] = fa[i - 1][fa[i - 1][j]];
    }
  }
  for (int i = 0; i < n; i++) {
    int u = i;
    long long sum = 0, Min = 0x7f7f7f7f7f;
    for (int j = 0; j < 35; j++) {
      if (k >> j & 1) {
        sum += dp1[j][u];
        Min = min(Min, dp2[j][u]);
        u = fa[j][u];
      }
    }
    cout << sum << " " << Min << endl;
  }
}
