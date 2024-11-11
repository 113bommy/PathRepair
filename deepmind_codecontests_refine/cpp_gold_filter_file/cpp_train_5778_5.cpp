#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long i, j, k, n, m, d, t, ans = 0, z, l, mid, r, sum = 0, flag,
                               b[200005] = {0}, a[200005], maxx = -99999999, x,
                               y, xx;
int bool1[200005] = {0}, bool2[200005] = {0};
int main() {
  for (i = 1; i <= 6; i++) cin >> a[i];
  if (a[2] < a[6]) swap(a[2], a[6]), swap(a[3], a[5]);
  ans += (a[1] * 2 + 1 + a[1] * 2 + 1 + 2 * (a[6] - 1)) * a[6] / 2,
      ans += (a[1] * 2 + 1 + 2 * (a[6] - 1) + 1) * (a[5] - a[3]) +
             (a[4] * 2 + 1 + a[4] * 2 + 1 + 2 * (a[3] - 1)) * a[3] / 2;
  cout << ans;
  return 0;
}
