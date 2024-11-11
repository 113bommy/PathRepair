#include <bits/stdc++.h>
using namespace std;
int hy, ay, dy, hm, am, dm, h, a, m, ans;
int cek(int x, int y) {
  int tmp1, tmp2;
  tmp1 = hy;
  tmp2 = hm;
  while (tmp2 > 0) {
    tmp2 -= (x - dm);
    if (x - dm <= 0) {
      cout << "a" << endl;
      cin.ignore();
    }
    tmp1 -= max(0, (am - y));
  }
  if (tmp1 <= 0) {
    return -tmp1 + 1;
  } else {
    return 0;
  }
}
int main() {
  scanf("%d %d %d", &hy, &ay, &dy);
  scanf("%d %d %d", &hm, &am, &dm);
  scanf("%d %d %d", &h, &a, &m);
  ans = 2000000000;
  for (int i = ay; i <= max(ay, dm + hm); i++) {
    if (i <= dm) continue;
    for (int j = dy; j <= max(dm, am); j++) {
      ans = min(ans, cek(i, j) * h + (i - ay) * a + (j - dy) * m);
    }
  }
  if (ans == 2000000000) ans = 0;
  cout << ans << endl;
}
