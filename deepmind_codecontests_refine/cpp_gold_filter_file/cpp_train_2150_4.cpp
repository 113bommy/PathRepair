#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
const int kX = 100000;
const int kN = kX * 4 + 5;
int pmin[kN], pmax[kN], smin[kN], smax[kN], vmin[kN], vmax[kN];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < kN; ++i) vmin[i] = INF, vmax[i] = -INF;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    vmin[x + y + 2 * kX] = std::min(vmin[x + y + 2 * kX], x - y);
    vmax[x + y + 2 * kX] = std::max(vmax[x + y + 2 * kX], x - y);
  }
  for (int i = 0; i < kN; ++i) {
    pmin[i] = vmin[i];
    pmax[i] = vmax[i];
    if (i >= 2) {
      pmin[i] = std::min(pmin[i], pmin[i - 2]);
      pmax[i] = std::max(pmax[i], pmax[i - 2]);
    }
  }
  for (int i = kN - 1; i >= 0; --i) {
    smin[i] = vmin[i];
    smax[i] = vmax[i];
    if (i + 2 < kN) {
      smin[i] = std::min(smin[i], smin[i + 2]);
      smax[i] = std::max(smax[i], smax[i + 2]);
    }
  }
  long long result = 0;
  for (int i = 2; i < kN; ++i) {
    int low = std::max(pmin[i - 2], smin[i]);
    int high = std::min(pmax[i - 2], smax[i]);
    if (low < high) result += high - low >> 1;
  }
  printf("%lld\n", result);
}
