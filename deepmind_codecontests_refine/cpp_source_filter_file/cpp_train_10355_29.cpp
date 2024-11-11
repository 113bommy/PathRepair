#include <bits/stdc++.h>
using namespace std;
int hp, atk, def, hp_m, atk_m, def_m, x, y, z, ans = (int)1e9;
bool win(int q1, int q2, int q3) {
  int t1 = q2 - def_m;
  int t2 = atk_m - q3;
  if (t1 <= 0) return false;
  if (t2 <= 0)
    return true;
  else if (hp_m / t1 + (hp_m % t1 > 0) < q1 / t2 + (q1 % t2 > 0))
    return true;
  return false;
}
int main() {
  cin >> hp >> atk >> def >> hp_m >> atk_m >> def_m >> x >> y >> z;
  for (int i = 0; i <= 300; ++i)
    for (int j = 0; j <= 300; ++j)
      for (int l = 0; l <= 300; ++l)
        if (win(hp + i, atk + j, def + l))
          ans = min(ans, i * x + j * y + l * z);
  cout << ans;
}
