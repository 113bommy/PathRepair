#include <bits/stdc++.h>
using namespace std;
const double pi = 3.141592653589793238;
const long long int inf = (long long int)10e16;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int h, k = 0, an = 0, temp, mi = 10000000000000000, an1, h1;
  int n;
  cin >> h >> n;
  long long int q[n + 1], dp[n + 1];
  for (int i = 1; i <= n; i += 1) cin >> q[i];
  for (int i = 1; i <= n; i += 1) {
    k += q[i];
    dp[i] = k;
    if (h + dp[i] <= 0) {
      cout << i;
      return 0;
    }
  }
  if (k >= 0) {
    cout << -1;
    return 0;
  }
  k *= -1;
  for (int i = 1; i <= n; i += 1) {
    h1 = h;
    h1 += dp[i];
    if (h1 % k == 0) {
      an = ((h1 / k) * n);
    } else {
      an = ((h1 / k) + 1) * n;
    }
    mi = min(mi, an + i);
  }
  cout << mi;
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
