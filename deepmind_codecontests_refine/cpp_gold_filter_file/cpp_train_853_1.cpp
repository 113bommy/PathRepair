#include <bits/stdc++.h>
using namespace std;
const int MXN = (int)5e5 + 3;
int BitZ[MXN], N, MXY;
int x[MXN], y[MXN], z[MXN];
int dy[MXN], ar[MXN];
int compXr(int a, int b) { return x[a] > x[b]; }
int getMaxZ(int y) {
  int r = -1;
  for (; y > 0; y -= y & -y) r = max(r, BitZ[y]);
  return r;
}
void updateMaxZ(int y, int v) {
  for (; y <= MXY; y += y & -y) BitZ[y] = max(v, BitZ[y]);
}
int main() {
  int i, j, k, a, b, c, r = 0;
  scanf("%d", &N);
  for (i = 0; i < N; i++) scanf("%d", &x[i]);
  for (i = 0; i < N; i++) scanf("%d", &y[i]);
  for (i = 0; i < N; i++) scanf("%d", &z[i]);
  for (i = 0; i < N; i++) dy[i] = y[i], ar[i] = i;
  sort(dy, dy + N);
  MXY = unique(dy, dy + N) - dy;
  for (i = 0; i < N; i++) y[i] = MXY - (lower_bound(dy, dy + MXY, y[i]) - dy);
  sort(ar, ar + N, compXr);
  fill(BitZ, BitZ + MXY + 1, -1);
  for (i = 0; i < N;) {
    for (j = i; j < N; j++) {
      if (x[ar[j]] != x[ar[i]]) break;
      if (z[ar[j]] < getMaxZ(y[ar[j]] - 1)) r++;
    }
    for (; i < j; i++) {
      updateMaxZ(y[ar[i]], z[ar[i]]);
    }
  }
  printf("%d\n", r);
  return 0;
}
