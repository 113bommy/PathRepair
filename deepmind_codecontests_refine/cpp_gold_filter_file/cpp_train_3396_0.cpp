#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000009;
const int MX = 100005;
const double EPS = 1e-9;
const int MOD = 1000000007;
int main() {
  std::ios_base::sync_with_stdio(false);
  long long a, b, f, k;
  cin >> a >> b >> f >> k;
  long long d1 = f;
  long long d2 = a - f;
  long long fuel = b;
  int ans = 0;
  if (d1 > b || d2 > b) ans = -1;
  if (k == 2 && (d1 > b || 2 * d2 > b)) ans = -1;
  if (k > 2 && (2 * d1 > b || 2 * d2 > b)) ans = -1;
  if (ans == -1) {
    cout << ans << "\n";
    return 0;
  }
  for (long long i = 1; i <= k; i++) {
    if (i % 2 == 1) {
      if (i < k) {
        fuel -= d1;
        if (i != 1) fuel -= d1;
        if (fuel < 2 * d2) fuel = b, ans++;
      } else {
        fuel -= d1;
        if (i != 1) fuel -= d1;
        if (fuel < d2) fuel = b, ans++;
      }
    } else {
      if (i < k) {
        fuel -= 2 * d2;
        if (fuel < 2 * d1) fuel = b, ans++;
      } else {
        fuel -= 2 * d2;
        if (fuel < d1) fuel = b, ans++;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
