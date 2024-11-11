#include <bits/stdc++.h>
using namespace std;
const int N = 101;
const int INF = 1e9;
int n;
int a[N], ans[N];
vector<int> p;
int mask[N];
int parent[N][(1 << 17)];
int dp[N][(1 << 17)];
bool prime(int x) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) return false;
  }
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 2; i < 60; ++i) {
    if (prime(i) == true) p.push_back(i);
  }
  for (int i = 1; i < 60; ++i) {
    mask[i] = 0;
    int x = i;
    for (int j = 0; j < p.size(); ++j) {
      if (x % p[j] == 0) mask[i] |= (1 << j);
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int mask1 = 0; mask1 < (1 << 17); ++mask1) {
      dp[i][mask1] = INF;
      for (int k = 1; k < 60; ++k) {
        if ((mask1 & mask[k]) != mask[k]) continue;
        if (dp[i - 1][mask1 ^ mask[k]] != INF &&
            dp[i][mask1] > dp[i - 1][mask1 ^ mask[k]] + abs(a[i - 1] - k)) {
          dp[i][mask1] = dp[i - 1][mask1 ^ mask[k]] + abs(a[i - 1] - k);
          parent[i][mask1] = k;
        }
      }
    }
  }
  int ansMask = 0;
  for (int mask1 = 1; mask1 < (1 << 17); ++mask1) {
    if (dp[n][ansMask] > dp[n][mask1]) ansMask = mask1;
  }
  for (int i = n; i > 0; --i) {
    ans[i - 1] = parent[i][ansMask];
    ansMask = ansMask ^ mask[ans[i - 1]];
  }
  for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
  return 0;
}
