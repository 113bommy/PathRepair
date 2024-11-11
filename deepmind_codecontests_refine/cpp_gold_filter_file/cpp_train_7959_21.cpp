#include <bits/stdc++.h>
using namespace std;
long long int kona1[4], kona2[4];
long long int abb(long long int n) {
  long long int hh = n > 0 ? n : -n;
  return hh;
}
int main() {
  long long int n, m, c;
  cin >> n >> m >> c;
  long long int aa[c], bb[c];
  cin >> aa[0] >> bb[0];
  for (int i = 0; i < 4; i++) kona1[i] = aa[0], kona2[i] = bb[0];
  for (int i = 1; i < c; i++) {
    scanf("%I64d %I64d ", &aa[i], &bb[i]);
    if (abb(aa[i] - 1) + abb(bb[i] - 1) < abb(kona1[0] - 1) + abb(kona2[0] - 1))
      kona1[0] = aa[i], kona2[0] = bb[i];
    if (abb(aa[i] - 1) + abb(bb[i] - m) < abb(kona1[1] - 1) + abb(kona2[1] - m))
      kona1[1] = aa[i], kona2[1] = bb[i];
    if (abb(aa[i] - n) + abb(bb[i] - 1) < abb(kona1[2] - n) + abb(kona2[2] - 1))
      kona1[2] = aa[i], kona2[2] = bb[i];
    if (abb(aa[i] - n) + abb(bb[i] - m) < abb(kona1[3] - n) + abb(kona2[3] - m))
      kona1[3] = aa[i], kona2[3] = bb[i];
  }
  long long int h, maxi = -1, x, y, mini = 1e11, pos = 0, diff;
  cin >> h;
  for (int i = 0; i < h; i++) {
    scanf("%I64d  %I64d ", &x, &y);
    for (int j = 0; j < 4; j++) {
      diff = abb(x - kona1[j]) + abb(y - kona2[j]);
      maxi = max(maxi, diff);
    }
    if (maxi < mini) mini = maxi, pos = i;
    maxi = -1;
  }
  cout << mini << endl << pos + 1;
  return 0;
}
