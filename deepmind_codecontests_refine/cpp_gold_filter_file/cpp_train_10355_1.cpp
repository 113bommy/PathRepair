#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int hy, ay, dy, hm, am, dm, h, a, d, ans = INT_MAX;
  cin >> hy >> ay >> dy >> hm >> am >> dm >> h >> a >> d;
  for (int i = 0; i <= 200; ++i)
    for (int j = 0; j <= 100; ++j) {
      int dmg1 = ay + i - dm, dmg2 = am - (dy + j);
      if (dmg1 > 0) {
        int hp_need = (hm / dmg1 + (hm % dmg1 != 0)) * dmg2 + 1;
        int k = max(hp_need - hy, 0);
        ans = min(ans, a * i + d * j + h * k);
      }
    }
  cout << ans;
  return 0;
}
