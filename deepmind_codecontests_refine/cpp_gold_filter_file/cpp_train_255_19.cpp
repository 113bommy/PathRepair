#include <bits/stdc++.h>
using namespace std;
int A[20 + 5][20 + 5];
bool used[1 << 20];
long long memo[1 << 20];
int lower_bit[1 << 20];
int n, m;
int groups[20 + 5][20 + 5];
int ones(int mask) { return __builtin_popcount(mask); }
long long SUM[20 + 5][20 + 5], MAXI[20 + 5][20 + 5];
long long dp(int mask) {
  if (mask == 0) return 0;
  if (used[mask]) return memo[mask];
  used[mask] = 1;
  long long &dev = memo[mask] = (1LL << 40);
  int i = lower_bit[mask];
  for (int j = 0; j < m; ++j) {
    dev = min(dev, A[i][j] + dp(mask ^ (1 << i)));
    int inter = (mask & groups[i][j]);
    dev = min(dev, SUM[i][j] - MAXI[i][j] + dp(mask ^ inter));
  }
  return dev;
}
char S[20 + 5][20 + 5];
int main() {
  for (int i = 0; i < (1 << 20); ++i) lower_bit[i] = 31 - __builtin_clz(i);
  while (scanf("%d", &n) == 1) {
    scanf("%d", &m);
    for (int i = 0; i < n; ++i) scanf("%s", S[i]);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) scanf("%d", &A[i][j]);
    memset(SUM, 0, sizeof(SUM));
    memset(MAXI, 0, sizeof(MAXI));
    memset(groups, 0, sizeof(groups));
    for (int j = 0; j < m; ++j) {
      for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k)
          if (S[i][j] == S[k][j]) {
            SUM[i][j] += A[k][j];
            MAXI[i][j] = max(MAXI[i][j], (long long)A[k][j]);
            groups[i][j] ^= (1 << k);
          }
      }
    }
    memset(used, 0, sizeof(used));
    printf("%d\n", (int)dp((1 << n) - 1));
  }
}
