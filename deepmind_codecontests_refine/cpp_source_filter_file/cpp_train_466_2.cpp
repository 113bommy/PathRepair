#include <bits/stdc++.h>
using namespace std;
int main() {
  double m[5], w[5], hs, hu, sc[5] = {500, 1000, 1500, 2000, 2500};
  for (int i = 0; i < 5; i++) cin >> m[i];
  for (int i = 0; i < 5; i++) cin >> w[i];
  cin >> hs >> hu;
  double ans = 0;
  for (int i = 0; i < 5; i++)
    ans += max(0.3 * sc[i], (1 - 1.0 * m[i] / 250) * sc[i] - 50 * w[i]);
  ans += -50 * hu + 100 * hs;
  cout << (int)ans << endl;
  return 0;
}
