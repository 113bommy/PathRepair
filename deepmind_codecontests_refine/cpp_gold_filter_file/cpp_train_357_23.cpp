#include <bits/stdc++.h>
using namespace std;
int main() {
  int hy, ay, dy, hm, am, dm, h, a, d;
  cin >> hy >> ay >> dy >> hm >> am >> dm >> h >> a >> d;
  int p = max(ay, dm + 1);
  int res = 10000000;
  do {
    int k = hm / (p - dm);
    if (hm % (p - dm) != 0) k++;
    for (int q = dy; am - q > 0; q++) {
      int r = hy;
      while (1) {
        int k2 = r / (am - q);
        if (r % (am - q) != 0) k2++;
        if (k2 > k) break;
        r++;
      }
      res = min(res, (r - hy) * h + (q - dy) * d + (p - ay) * a);
    }
    p++;
  } while (p - dm <= hm);
  res = min(res, max(am - dy, 0) * d + max(dm - ay + 1, 0) * a);
  cout << res;
}
