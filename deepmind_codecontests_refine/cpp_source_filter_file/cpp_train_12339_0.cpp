#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
int n;
int a[MAXN][MAXN];
bitset<MAXN> h[MAXN], l[MAXN];
int Read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x * 10) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
void Put1(int x) {
  if (x > 9) Put1(x / 10);
  putchar(x % 10 ^ 48);
}
void Put(int x, char c = -1) {
  if (x < 0) putchar('-'), x = -x;
  Put1(x);
  if (c >= 0) putchar(c);
}
template <typename T>
T Max(T x, T y) {
  return x > y ? x : y;
}
template <typename T>
T Min(T x, T y) {
  return x < y ? x : y;
}
template <typename T>
T Abs(T x) {
  return x < 0 ? -x : x;
}
struct node {
  int x, y, val;
  node() {}
  node(int x1, int y1, int val1) {
    x = x1;
    y = y1;
    val = val1;
  }
  bool operator<(const node &px) const { return val < px.val; }
} s[MAXN * MAXN];
int main() {
  n = Read();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) s[(i - 1) * n + j] = node(i, j, Read());
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) {
      if (s[(i - 1) * n + j].val != s[(j - 1) * n + i].val ||
          (i == j && s[(i - 1) * n + j].val)) {
        printf("NOT MAGIC");
        return 0;
      }
      l[j][i] = h[i][j] = 0;
    }
  sort(s + 1, s + n * n + 1);
  s[0].val = -1;
  for (int i = 1; i <= n * n; ++i) {
    if (s[i].val != s[i - 1].val) {
      for (int j = i - 1; j >= 1; --j) {
        h[s[j].x][s[j].y] = l[s[j].y][s[j].x] = 1;
        if (s[j].val != s[j - 1].val) break;
      }
    }
    if ((h[s[i].x] & l[s[i].y]).any()) {
      printf("NOT MAGIC");
      return 0;
    }
  }
  printf("MAGIC");
  return 0;
}
