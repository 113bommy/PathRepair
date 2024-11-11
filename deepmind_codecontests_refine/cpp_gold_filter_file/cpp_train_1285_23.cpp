#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long k, b, n, t, i, j, ans;
  cin >> k >> b >> n >> t;
  if (k == 1) {
    ans = (1 + n * b - t) / b;
    if ((1 + n * b - t) % b != 0) ans++;
  } else {
    double d1 = (k - 1), d2 = (double)b / d1;
    double num = (1 + d2), den = (t + d2);
    double d3 = (den) / num;
    long long l = 1;
    for (i = 0; i <= 1e5; i++) {
      if (l <= d3 && l * k > d3) break;
      l *= k;
    }
    ans = n - i;
  }
  if (ans < 0) ans = 0;
  cout << ans << "\n";
  return 0;
}
