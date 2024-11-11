#include <bits/stdc++.h>
using namespace std;
int a[8][8], b[8][8];
long long get() {
  char c = getchar();
  long long x = 0LL;
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') {
    x *= 10LL;
    x += (c - '0');
    c = getchar();
  }
  return x;
}
int main() {
  char c;
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) {
      cin >> c;
      if (c == 'B') a[i][j] = 1;
    }
  int ans = 16;
  for (int i = 0; i < (1 << 8); i++)
    for (int j = 0; j < (1 << 8); j++) {
      for (int x = 0; x < 8; x++)
        for (int y = 0; y < 8; y++) {
          if (i & (1 << x) || j & (1 << y))
            b[x][y] = 1;
          else
            b[x][y] = 0;
        }
      bool f = true;
      for (int x = 0; x < 8; x++)
        for (int y = 0; y < 8; y++)
          if (b[x][y] != a[x][y]) f = false;
      if (f) {
        ans = min(ans, __builtin_popcount(i) + __builtin_popcount(j));
      }
    }
  cout << ans;
  return 0;
}
