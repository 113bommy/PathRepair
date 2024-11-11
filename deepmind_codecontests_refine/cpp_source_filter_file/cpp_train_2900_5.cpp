#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, e, f, g;
int main() {
  cin >> a >> b >> c >> d >> e >> f;
  long long res = 0;
  for (int i = 0; i <= min({a, d, e}); ++i)
    res = max(res, 3 * i + 2 * ((a - i) / 2 + (d - i) / 2 + (e - i) / 2) + b);
  cout << res << endl;
  return 0;
}
