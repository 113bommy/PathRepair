#include <bits/stdc++.h>
using namespace std;
long long C, hr, hb, wr, wb;
long long cnt(int mid) {
  if (mid * wr > C) return -1;
  return mid * hr + ((C - mid * wr) / wb) * hb;
}
int main() {
  cin >> C >> hr >> hb >> wr >> wb;
  long long ans = 0;
  if (wr < wb && hr > hb) {
    ans = (C / wr) * hr;
  } else if (wr > wb && hr < hb) {
    ans = (C / wb) * hb;
  } else {
    long long b1 = C / wr, b2 = C / wb;
    for (long long c1 = b1; c1 >= 0 && c1 >= b1 - 1000; c1--) {
      long long rem = C - c1 * wr;
      ans = max(ans, c1 * hr + hb * (rem / wb));
    }
    for (long long c1 = b2; c1 >= 0 && c1 >= b2 - 1000; c1--) {
      long long rem = C - c1 * wb;
      ans = max(ans, c1 * hb + hr * (rem / wr));
    }
  }
  cout << ans;
  return 0;
}
