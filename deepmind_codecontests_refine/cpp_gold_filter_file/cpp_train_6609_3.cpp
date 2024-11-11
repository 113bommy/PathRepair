#include <bits/stdc++.h>
using namespace std;
int n;
double p[1010], memo[1010][1010];
bool vis[1010][1010];
double solve(int idx, int r) {
  if (idx == n) {
    if (r == 0) return 1;
    return 0;
  }
  if (r < 0) return 0;
  if (vis[idx][r]) return memo[idx][r];
  vis[idx][r] = 1;
  memo[idx][r] =
      (p[idx] * solve(idx + 1, r - 1)) + ((1.0 - p[idx]) * solve(idx + 1, r));
  return memo[idx][r];
}
long long ones(long long x) {
  long long p = 1, c = 0;
  while (x >= p) {
    if (x >= 2 * p)
      c += p;
    else {
      c += x - p + 1;
      break;
    }
    p *= 10;
  }
  return c;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    p[i] = (ones(y) - (ones(x - 1))) / double(y - x + 1);
  }
  int x;
  cin >> x;
  x = ceil(n * (1.0 * x / 100.0));
  double ans = 0;
  for (int i = x; i <= n; i++) ans += solve(0, i);
  cout << fixed << setprecision(15) << ans;
  return 0;
}
