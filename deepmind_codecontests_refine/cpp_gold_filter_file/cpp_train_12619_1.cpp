#include <bits/stdc++.h>
using namespace std;
int ROW[] = {+1, -1, +0, +0};
int COL[] = {+0, +0, +1, -1};
int X[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int Y[] = {-1, +1, +0, +0, +1, +1, -1, -1};
int KX[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int KY[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int basePrime[] = {1009, 1013, 1019, 1021, 1031, 1223, 1229, 1231, 1237, 1249,
                   1289, 1291, 1297, 1301, 1303, 353,  359,  367,  373,  379,
                   859,  863,  877,  881,  883,  1931, 1933, 1949, 1951, 1973,
                   401,  409,  419,  421,  431,  1709, 1721, 1723, 1733, 1741,
                   3499, 3511, 3517, 3527, 3529, 929,  937,  941,  947,  953};
template <class XXX>
XXX GCD(XXX a, XXX b) {
  return b == 0 ? a : GCD(b, a % b);
}
template <class XXX>
XXX LCM(XXX a, XXX b) {
  return a * (b / GCD(a, b));
}
template <class XXX, class YYY>
bool CMP(XXX a, YYY b) {
  return a > b;
}
template <class T>
inline bool fastread(T &x) {
  int c = getchar();
  int sgn = 1;
  while (~c && c < '0' || c > '9') {
    if (c == '-') sgn = -1;
    c = getchar();
  }
  for (x = 0; ~c && '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  x *= sgn;
  return ~c;
}
int grid[4][100005];
int main() {
  int n;
  cin >> n;
  int b = 0;
  int q;
  cin >> q;
  while (q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    grid[x][y] = !grid[x][y];
    if (grid[x][y]) {
      if (x == 1) {
        if (grid[2][y]) b++;
        if (grid[2][y + 1]) b++;
        if (grid[2][y - 1]) b++;
      } else {
        if (grid[1][y]) b++;
        if (grid[1][y + 1]) b++;
        if (grid[1][y - 1]) b++;
      }
    } else {
      if (x == 1) {
        if (grid[2][y]) b--;
        if (grid[2][y + 1]) b--;
        if (grid[2][y - 1]) b--;
      } else {
        if (grid[1][y]) b--;
        if (grid[1][y + 1]) b--;
        if (grid[1][y - 1]) b--;
      }
    }
    if (!b)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
