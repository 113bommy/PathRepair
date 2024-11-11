#include <bits/stdc++.h>
using namespace std;
int main() {
  short precalc[] = {60,  90,  108, 120, 135, 140, 144, 150, 156, 160, 162,
                     165, 168, 170, 171, 172, 174, 175, 176, 177, 178, 179};
  short t, r;
  string ans = "";
  cin >> t;
  do {
    cin >> r;
    if (binary_search(&precalc[0], &precalc[21], r))
      ans += "YES\n";
    else
      ans += "NO\n";
    t--;
  } while (t > 0);
  cout << ans;
  return 0;
}
