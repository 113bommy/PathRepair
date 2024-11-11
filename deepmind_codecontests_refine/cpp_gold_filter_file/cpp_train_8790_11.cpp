#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1.0);
const long double EPSILON = 2.7182818284590452353602874713527;
long long n, m, k;
long long ans;
int main() {
  cin >> n >> m >> k;
  if (n + m - 2 < k) {
    ans = -1;
  } else {
    if (n < m) swap(n, m);
    for (long long i = 0; i <= 10; i++) {
      long long x;
      if (k > m - 1)
        x = k - (m - 1) + i;
      else
        x = i;
      if (!(x >= 0 && x <= n - 1 && k - x >= 0 && k - x <= m - 1)) continue;
      ans = max(ans, (n / (x + 1)) * (m / (k - x + 1)));
    }
    for (long long i = 0; i <= 10; i++) {
      long long xpi;
      if (k > n - 1)
        xpi = k - (n - 1) + i;
      else
        xpi = i;
      if (!(k - xpi >= 0 && k - xpi <= n - 1 && xpi >= 0 && xpi <= m - 1))
        continue;
      ans = max(ans, (n / (k - xpi + 1)) * (m / (xpi + 1)));
    }
  }
  cout << ans << endl;
  return 0;
}
