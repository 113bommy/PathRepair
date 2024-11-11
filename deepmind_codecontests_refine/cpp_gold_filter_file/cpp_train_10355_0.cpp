#include <bits/stdc++.h>
using namespace std;
int main() {
  int hy, hm, ay, am, dy, dm, h, a, d, i, j;
  int time1, hp, yangdec, monsdec, t1, min1;
  min1 = 100000000;
  scanf("%d %d %d", &hy, &ay, &dy);
  scanf("%d %d %d", &hm, &am, &dm);
  scanf("%d %d %d", &h, &a, &d);
  for (i = ay; i <= 205; i++) {
    for (j = dy; j <= 205; j++) {
      monsdec = max(0, i - dm);
      yangdec = max(0, am - j);
      if (monsdec <= 0) continue;
      time1 = hm / monsdec;
      if (hm % monsdec != 0) time1 += 1;
      hp = max(hy, time1 * yangdec + 1);
      t1 = (hp - hy) * h + (i - ay) * a + (j - dy) * d;
      if (t1 < min1) min1 = t1;
    }
  }
  cout << min1 << "\n";
  return 0;
}
