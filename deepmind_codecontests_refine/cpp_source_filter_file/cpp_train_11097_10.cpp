#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
long long int k;
inline long long int sum(long long int l, long long int r) {
  if (l > r)
    return 0;
  else
    return (l + r) * (r - l + 1) / 2;
}
long long int solve(long long int x, long long int y, long long int h) {
  if (x <= 0 || y <= 0) return 0;
  if (x < y) swap(x, y);
  long long int t = 1, ans = 0;
  while (t * 2 <= x) t <<= 1;
  if (t <= y) {
    ans = sum(h + 1, min(t + h, k)) * t % mod;
    ans = (ans + solve(x - t, y - t, h)) % mod;
    ans = (ans + solve(x - t, t, h + t)) % mod;
    ans = (ans + solve(t, y - t, h + t)) % mod;
  } else {
    ans = sum(h + 1, min(t + h, k)) * y % mod;
    ans = (ans + solve(x - t, y, h + t)) % mod;
  }
  return ans;
}
int main() {
  long long int x1, y1, x2, y2, q;
  scanf("%lld", &q);
  while (q--) {
    scanf("%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &k);
    long long int ans = solve(x2, y2, 0) + solve(x1 - 1, y1 - 1, 0) -
                        solve(x2, y1 - 1, 0) - solve(x1 - 1, y2, 0);
    ans = (ans % mod + mod) % mod;
    printf("%lld\n", ans);
  }
  return 0;
}
