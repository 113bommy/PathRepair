#include <bits/stdc++.h>
using namespace std;
int h[105];
int n, m, k;
int solve(int x) {
  if (m - x >= 1 && h[m - x] != 0 && h[m - x] <= k) return x;
  if (m + x <= n && h[m + x] != 0 && h[m + x] <= k) return x;
  return solve(x + 1);
}
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) cin >> h[i];
  printf("%d\n", solve(1) * 10);
  return 0;
}
