#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
long long const inf = 1e18, linf = 2e9, mod = 1e9 + 7;
int const mxn = (1 << 20) + 10;
long long poww(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
int halat[15][5] = {{0, 1, 2},         {3, 4, 5, 6},      {7, 8, 9, 10},
                    {12, 13, 14, 15},  {16, 17, 18},      {7, 12, 16},
                    {3, 8, 13, 17},    {0, 4, 9, 14, 18}, {1, 5, 10, 15},
                    {2, 6, 11},        {0, 3, 7},         {1, 4, 8, 12},
                    {2, 5, 9, 13, 16}, {6, 10, 14, 17},   {11, 15, 18}};
int siz[15] = {3, 4, 5, 4, 3, 3, 4, 5, 4, 3, 3, 4, 5, 4, 3};
int mark[100], g[(1 << 19) + 10];
int mex() {
  for (int i = 0; i < 100; i++)
    if (!mark[i]) return i;
}
int okay(int a, int b, int c) {
  int now = 0;
  for (int i = 0 + c; i <= b + c; i++) now += (1 << halat[a][i]);
  return now;
}
char s[19];
int main() {
  g[0] = 0;
  int ans = 0;
  for (int i = 0; i < 19; i++) {
    cin >> s[i];
    if (s[i] == 'O') ans += (1 << i);
    g[(1 << i)] = 1;
  }
  for (int mask = 1; mask < (1 << 19); mask++) {
    memset(mark, 0, sizeof(mark));
    if (__builtin_popcount(mask) == 1) continue;
    for (int i = 0; i < 15; i++) {
      for (int j = 0; j < siz[i]; j++) {
        for (int k = 0; k < siz[i] - j; k++) {
          int now = okay(i, j, k);
          if ((mask & now) == now) mark[g[mask - now]] = 1;
        }
      }
    }
    g[mask] = mex();
  }
  if (g[ans] == 0)
    cout << "Lillebror";
  else
    cout << "Karlsson";
}
