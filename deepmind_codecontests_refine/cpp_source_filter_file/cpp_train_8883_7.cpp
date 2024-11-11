#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void chkmax(T& x, U y) {
  if (x < y) x = y;
}
template <typename T, typename U>
inline void chkmin(T& x, U y) {
  if (y < x) x = y;
}
int x[11];
void out(int l, int b) {
  char p = 'a';
  if (b == 0) p = 'b';
  for (int i = 0; i < l; i++) printf("%c", p);
}
void out(int p1, int p2, int p3, int p4, int p5, int p6, int p7) {
  out(x[1], p1);
  out(x[2], p2);
  out(x[3], p3);
  out(x[4], p4);
  out(x[5], p5);
  out(x[6], p6);
  out(x[7], p7);
  printf("\n");
}
int main() {
  int Tc, n;
  int h12, h13, h14, h23, h24, h34;
  scanf("%d%d%d", &h12, &h13, &h14);
  scanf("%d%d", &h23, &h24);
  scanf("%d", &h34);
  int s[11] = {0};
  s[1] = h13 + h12 - h24 - h34;
  s[3] = h14 + h34 - h13;
  s[2] = h24 + h34 - h23;
  s[5] = h14 + h24 - h12;
  s[6] = h13 + h23 - h14 - h24;
  s[4] = h12 + h23 - h14 - h34;
  int i;
  for (i = 1; i <= 6; i++)
    if (s[i] & 1) break;
  if (i <= 6) {
    printf("-1\n");
    return 0;
  }
  for (i = 1; i <= 6; i++) s[i] >>= 1;
  int mn = max(max(-s[1], -s[4]), -s[6]);
  int mx = min(min(s[2], s[3]), s[5]);
  if (mn > mx or mx < 0) {
    printf("-1\n");
    return 0;
  }
  x[7] = 0;
  if (mn <= 0)
    x[7] = 0;
  else
    x[7] = mn;
  int len = 0;
  for (i = 1; i < 7; i++) len += s[i];
  len += x[7];
  printf("%d\n", len);
  x[1] = s[1] + x[7];
  x[2] = s[2] - x[7];
  x[3] = s[3] - x[7];
  x[4] = s[4] - x[7];
  x[5] = s[5] + x[7];
  x[6] = s[6] + x[7];
  out(1, 1, 1, 1, 1, 1, 1);
  out(0, 0, 0, 0, 1, 1, 1);
  out(0, 0, 1, 1, 0, 0, 1);
  out(0, 1, 0, 1, 0, 1, 0);
  return 0;
}
