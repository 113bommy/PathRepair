#include <bits/stdc++.h>
using namespace std;
long long h, n;
long long solve(long long n, long long w, long long lev) {
  if (lev == 0) return 1;
  int m = n - (1LL << lev) + 1;
  if (w == 0) {
    if (m <= 1LL << (lev - 1))
      return 1 + solve(n - (1LL << (lev - 1)), 1, lev - 1);
    else
      return (1LL << lev) + solve(n - (1LL << lev), 0, lev - 1);
  } else {
    if (m > 1LL << (lev - 1))
      return 1 + solve(n - (1LL << lev), 0, lev - 1);
    else
      return (1LL << lev) + solve(n - (1LL << (lev - 1)), 1, lev - 1);
  }
}
int main() {
  cin.sync_with_stdio(false);
  cin >> h >> n;
  n = (1LL << h) - 1 + n;
  cout << solve(n, 0, h) - 1;
  return 0;
}
