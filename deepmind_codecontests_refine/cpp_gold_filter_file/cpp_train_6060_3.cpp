#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int l1[N], l2[N], d[N];
void solve() {
  for (int i = (int)(1); i <= (int)(3); i++) scanf("%d", &l1[i]);
  for (int i = (int)(1); i <= (int)(3); i++) scanf("%d", &l2[i]);
  for (int i = (int)(1); i <= (int)(7); i++) scanf("%d", &d[i]);
  if (d[1] + d[2] + d[3] + d[4] > l1[1] + l2[1]) return puts("-1"), void(0);
  if (d[1] + d[2] + d[5] + d[6] > l1[2] + l2[2]) return puts("-1"), void(0);
  if (d[1] + d[3] + d[5] + d[7] > l1[3] + l2[3]) return puts("-1"), void(0);
  for (int v2 = (int)(0); v2 <= (int)(d[2]); v2++)
    for (int v3 = (int)(0); v3 <= (int)(d[3]); v3++) {
      int r11 = l1[1] - v2 - v3, r21 = l2[1] - (d[2] - v2) - (d[3] - v3);
      int r12 = l1[2] - v2, r22 = l2[2] - (d[2] - v2);
      int r13 = l1[3] - v3, r23 = l2[3] - (d[3] - v3);
      int v5, vv5 = 0, r5 = d[5];
      v5 = max(0, min(r5, min(r12 - r11, r13 - r11)));
      r12 -= v5;
      r13 -= v5;
      r5 -= v5;
      vv5 += v5;
      v5 = max(0, min(r5, min(r22 - r21, r23 - r21)));
      r22 -= v5;
      r23 -= v5;
      r5 -= v5;
      v5 = max(0, min(r5, min(r12, r13)));
      r12 -= v5;
      r13 -= v5;
      r5 -= v5;
      vv5 += v5;
      v5 = max(0, min(r5, min(r22, r23)));
      r22 -= v5;
      r23 -= v5;
      r5 -= v5;
      if (r11 < 0 || r12 < 0 || r13 < 0 || r21 < 0 || r22 < 0 || r23 < 0 || r5)
        continue;
      int l1 = min(r11, min(r12, r13)), l2 = min(r21, min(r22, r23));
      if (l1 + l2 >= d[1]) {
        int v1 = min(d[1], l1);
        int v4 = min(d[4], r11 - v1);
        int v6 = min(d[6], r12 - v1);
        int v7 = min(d[7], r13 - v1);
        printf("%d %d %d %d %d %d %d\n", v1, v2, v3, v4, vv5, v6, v7);
        return;
      }
    }
  puts("-1");
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
