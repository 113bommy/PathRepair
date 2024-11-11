#include <bits/stdc++.h>
const int mod = 1000000007;
using namespace std;
int C, hr, hb, wr, wb;
long long ret;
int main() {
  scanf("%d %d %d %d %d", &C, &hr, &hb, &wr, &wb);
  int c = sqrt(C);
  if (wr >= c) {
    for (int red = 0; red <= c; ++red) {
      if (red * wr > C) break;
      ret = max(ret, red * 1LL * hr + ((C - red * wr) / wb) * 1LL * hb);
    }
  } else if (wb >= c) {
    for (int blue = 0; blue <= c; ++blue) {
      if (blue * wb > C) break;
      ret = max(ret, blue * 1LL * hb + ((C - blue * wb) / wr) * 1LL * hr);
    }
  } else {
    if (hb * 1LL * wr <= hr * 1LL * wb) {
      for (int blue = 0; blue <= c; ++blue) {
        ret = max(ret, blue * 1LL * hb + ((C - blue * wb) / wr) * 1LL * hr);
      }
    } else {
      for (int red = 0; red <= c; ++red) {
        ret = max(ret, red * 1LL * hr + ((C - red * wr) / wb) * 1LL * hb);
      }
    }
  }
  printf("%I64d\n", ret);
  return 0;
}
