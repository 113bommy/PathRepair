#include <bits/stdc++.h>
using namespace std;
int x[10], y[10], at[10], bt[10], v;
bool lypa = 1;
inline int len(int a, int b) {
  return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
}
int rig(int a, int b, int c) {
  return (x[b] - x[a]) * (x[c] - x[b]) + (y[b] - y[a]) * (y[c] - y[b]);
}
inline int f(int x) {
  int y = 128, j = 0, ib = 0, ia = 0;
  while (y > 0) {
    if (y <= x)
      x -= y, bt[ib] = j, ib++;
    else
      at[ia] = j, ia++;
    y /= 2, j++;
  }
  return ib;
}
inline int sq(int a, int b, int c, int d) {
  if (len(a, b) == len(b, c)) {
    if (len(c, d) == len(d, a) && rig(a, b, c) == 0 && rig(c, d, a) == 0)
      return 1;
  }
  if (len(a, c) == len(b, c)) {
    if (len(b, d) == len(d, a) && rig(a, c, b) == 0 && rig(b, d, a) == 0)
      return 1;
  }
  if (len(a, b) == len(a, c)) {
    if (len(b, d) == len(d, c) && rig(b, a, c) == 0 && rig(c, d, b) == 0)
      return 1;
  }
  return 0;
}
inline int rect(int a, int b, int c, int d) {
  if (rig(a, b, c) == 0 && rig(c, d, a) == 0) return 1;
  if (rig(a, c, b) == 0 && rig(b, d, a) == 0) return 1;
  if (rig(b, a, c) == 0 && rig(c, d, b) == 0) return 1;
  return 0;
}
int main() {
  for (int z = 0; z < 8; z++) scanf("%d %d", &x[z], &y[z]);
  for (int z = 1; z < 256; z++) {
    if (f(z) == 4) {
      if (sq(bt[1], bt[2], bt[3], bt[0]) == 1 &&
          rect(at[1], at[2], at[3], at[0]) == 1) {
        lypa = 0, v = z;
        break;
      }
    }
  }
  if (lypa == 1)
    printf("NO\n");
  else {
    printf("YES\n");
    printf("%d %d %d %d\n", bt[0] + 1, bt[1] + 1, bt[2] + 1, bt[3] + 1);
    printf("%d %d %d %d\n", at[0] + 1, at[1] + 1, at[2] + 1, at[3] + 1);
  }
  return 0;
}
