#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  int c;
  bool f = 0;
  while (c = getchar(), c < '0' || c > '9') c == '-' ? f = 1 : 0;
  for (x = 0; c >= '0' && c <= '9'; c = getchar())
    x = (x << 1) + (x << 3) + c - '0';
  f ? x = -x : 0;
}
template <typename First, typename... Rest>
inline void read(First &first, Rest &...rest) {
  read(first), read(rest...);
}
const int n = 8;
char c[n][n];
int w[n][n];
int b[n][n];
int main() {
  register int aa, bb;
  aa = bb = 2e9;
  for (int i = 0; i < n; ++i) scanf("%s", c[i]);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      w[i][j] = (c[i][j] != '.');
      if (i) w[i][j] += w[i - 1][j];
    }
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < n; ++j) {
      b[i][j] = (c[i][j] != '.');
      if (i < n - 1) b[i][j] += b[i + 1][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (c[i][j] == 'W') {
        if (!w[i - 1][j]) {
          aa = min(aa, i);
        }
      } else if (c[i][j] == 'B') {
        if (!b[i + 1][j]) {
          bb = min(bb, n - i - 1);
        }
      }
    }
  }
  if (aa <= bb)
    puts("A");
  else
    puts("B");
  return 0;
}
