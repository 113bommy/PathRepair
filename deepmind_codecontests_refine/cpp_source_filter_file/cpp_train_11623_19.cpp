#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int f, m, s, ma;
int main() {
  scanf("%d %d %d %d", &f, &m, &s, &ma);
  int fm, fmi, mm, sm, smi, mam, mmi;
  fm = 2 * f;
  mm = 2 * m;
  sm = 2 * s;
  mam = m * 2;
  if (ma > fm || ma > mm || ma > sm || 2 * s < ma || 2 * ma < s ||
      (m <= 2 * ma)) {
    printf("-1");
    return 0;
  }
  int fc, mc, sc;
  fc = 2 * f;
  mc = 2 * m;
  if (ma <= s)
    sc = s;
  else
    sc = ma;
  if (sc >= mc) {
    printf("-1");
    return 0;
  }
  printf("%d\n%d\n%d", fc, mc, sc);
  return 0;
}
