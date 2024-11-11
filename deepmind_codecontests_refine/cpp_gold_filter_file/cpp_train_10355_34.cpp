#include <bits/stdc++.h>
using namespace std;
int main() {
  int hy, ay, dy, hm, am, dm, h, a, d;
  while (cin >> hy >> ay >> dy >> hm >> am >> dm >> h >> a >> d) {
    int ans = max(dm - ay + 1, 0) * a + max(am - dy, 0) * d;
    for (int i = 0; i * a <= ans; ++i)
      for (int j = 0; i * a + j * d <= ans; ++j) {
        int ay2 = ay + i;
        int dy2 = dy + j;
        if (ay2 <= dm) continue;
        int damage = ay2 - dm;
        int t = hm / damage;
        while (t * damage < hm) ++t;
        damage = max(am - dy2, 0);
        ans = min(ans, i * a + j * d + h * max(1 + damage * t - hy, 0));
      }
    cout << ans << endl;
  }
}
