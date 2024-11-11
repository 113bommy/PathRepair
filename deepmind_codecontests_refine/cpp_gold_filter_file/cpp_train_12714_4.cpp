#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m;
int a[100], p10[20], p1[20], b[100000];
inline int cal(int x) { return b[x / 100000] + b[x % 100000]; }
inline int xia(int x) {
  int A = x % 10;
  if (A < 3 || A == 5 || A == 8) return x + 1;
  if (A == 3 || A == 6) return x + 2;
  if (A == 4) return x + 3;
  int s = 0;
  for (; x % 10 == 7; x /= 10) s++;
  if (x % 10 == 4) return (x + 3) * p10[s] + p1[s] * 4;
  int s1 = cal(x);
  int y = x + 1;
  if (s1 == cal(y)) return y * p10[s] + p1[s] * 4;
  if (s1 == cal(y) + 1) return y * p10[s] + p1[s + 1] * 4;
  if (s1 == cal(y) - 1) {
    if (s)
      return y * p10[s] + p1[s - 1] * 4;
    else {
      for (; y % 10 == 0;) y /= 10, s++;
      return (y + 1) * p10[s];
    }
  }
}
int dfs(int x, int y) {
  if (y == 1) return xia(x);
  int an = dfs(x / 10, (x + y - 1) / 10 - x / 10 + 1) * 10 + x % 10;
  if (y >= 10)
    return an;
  else {
    int i, k;
    for (i = 1; i <= y; i++) a[i] = cal(x + i - 1);
    for (k = xia(x); k < an; k = xia(k)) {
      int F = 0;
      for (i = 1; i <= y; i++)
        if (a[i] != cal(k + i - 1)) {
          F = 1;
          break;
        }
      if (!F) return k;
    }
    return an;
  }
}
int main() {
  for (i = 0; i <= 100000 - 1; i++) {
    int A = i % 10;
    b[i] = b[i / 10] + (A == 4 || A == 7);
  }
  p10[0] = 1;
  for (i = 1; i <= 19; i++) p10[i] = p10[i - 1] * 10;
  for (i = 1; i <= 19; i++) p1[i] = p1[i - 1] * 10 + 1;
  scanf("%d%d", &n, &m);
  printf("%d\n", dfs(n, m));
  return 0;
}
