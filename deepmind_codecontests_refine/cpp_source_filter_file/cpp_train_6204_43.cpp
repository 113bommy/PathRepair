#include <bits/stdc++.h>
int N, XL, XR, YL, YR, SX, SY, VX, VY;
long long LN, LD = 1, RN = 1000000000000LL, RD = 1;
inline bool cmp(long long a, long long b, long long c, long long d) {
  return a * d < b * c;
}
void LIM(int v, int s, int l, int r) {
  if (v == 0) {
    if (s < l || s > r) {
      puts("-1");
      exit(0);
    }
  } else {
    l -= s;
    r -= s;
    if (v < 0) {
      int tmp = l;
      l = r;
      r = tmp;
      l = -l;
      r = -r;
      v = -v;
    }
    if (cmp(LN, LD, l, v)) {
      LN = l;
      LD = v;
    }
    if (cmp(r, v, RN, RD)) {
      RN = r;
      RD = v;
    }
  }
}
int main() {
  for (scanf("%d%d%d%d%d", &N, &XL, &YL, &XR, &YR); N--;) {
    scanf("%d%d%d%d", &SX, &SY, &VX, &VY);
    LIM(VX, SX, XL, XR);
    LIM(VY, SY, YL, YR);
  }
  if (cmp(LN, LD, RN, RD))
    printf("%.12f\n", (double)LN / LD);
  else
    puts("-1");
  return 0;
}
