#include <bits/stdc++.h>
using namespace std;
const int nmax = 4e5 + 10;
const int cmax = 20;
int marbles[nmax];
long long cost[cmax][cmax];
int fv[cmax];
long long dp[1 << cmax];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> marbles[i];
  for (int i = n; i >= 1; --i) {
    int curentColor = --marbles[i];
    for (int anyColor = 0; anyColor < 20; ++anyColor)
      cost[curentColor][anyColor] += fv[anyColor];
    ++fv[curentColor];
  }
  for (int mask = 1; mask < (1 << 20); ++mask) dp[mask] = (1LL << 60);
  for (int mask = 1; mask < (1 << 20); ++mask)
    for (int putLast = 0; putLast < 20; ++putLast)
      if (mask & (1 << putLast)) {
        int prevMask = mask ^ (1 << putLast);
        long long addCost = 0;
        for (int color = 0; color < 20; ++color)
          if (prevMask & (1 << color)) addCost += cost[putLast][color];
        long long newCost = dp[prevMask] + addCost;
        dp[mask] = min(dp[mask], newCost);
      }
  cout << dp[(1 << 20) - 1];
}
