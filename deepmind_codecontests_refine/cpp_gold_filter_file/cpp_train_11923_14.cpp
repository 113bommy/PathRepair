#include <bits/stdc++.h>
bool debug = 1;
const double PI = acos(-1.0);
const double eps = 1e-9;
using namespace std;
int dp[1001000];
int cnt[1001000];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int v[1001000];
  int x;
  int res = 0;
  int mmc = 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    v[i] = x;
    if (x > 1000000) continue;
    cnt[x]++;
  }
  for (int i = 1; i <= m; i++) {
    if (cnt[i] == 0) continue;
    for (int k = 1; i * k <= m; k++) {
      dp[k * i] += cnt[i];
    }
  }
  for (int i = 1; i <= m; i++) {
    if (dp[i] > res) {
      res = dp[i];
      mmc = i;
    }
  }
  printf("%d %d\n", mmc, res);
  for (int i = 0; i < n; i++) {
    if (mmc % v[i] == 0) {
      printf("%d ", i + 1);
    }
  }
  return 0;
}
