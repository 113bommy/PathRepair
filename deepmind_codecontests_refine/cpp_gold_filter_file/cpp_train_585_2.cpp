#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, maxn = 1e5 + 100;
int main() {
  long long k, d, t;
  cin >> k >> d >> t;
  if (k % d == 0)
    d = k;
  else
    d = k - (k % d) + d;
  long long timezone = d + k;
  t *= 2;
  long double ans = d * (t / timezone);
  t %= timezone;
  if (t <= 2 * k)
    return cout << fixed << setprecision(4) << 1.0 * t / 2 + ans << endl, 0;
  ans += k;
  t -= 2 * k;
  ans += t;
  cout << fixed << setprecision(4) << 1.0 * ans << endl;
}
