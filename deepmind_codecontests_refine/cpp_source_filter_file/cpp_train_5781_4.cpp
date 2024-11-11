#include <bits/stdc++.h>
using namespace std;
const int N = 2000 + 5;
const int mod = 1e9 + 7;
int n, m, d;
char a[N], b[N];
int dp[N][N][2][2];
inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline bool can(int x, int i, bool f1, bool f2) {
  return (f1 or i >= a[x] - '0') and (f2 or i <= b[x] - '0');
}
int f(int x, int md, bool f1, bool f2) {
  if (x > n) return !md;
  int &r = dp[x][md][f1][f2];
  if (r != -1) return r;
  r = 0;
  if ((~x & 1) and can(x, d, f1, f2))
    r = f(x + 1, (md * 10 + d) % m, f1 or d > a[x] - '0', f2 or d < b[x] - '0');
  if (x & 1) {
    for (int i = (x == 1); i <= 9; i++) {
      if (i != d and can(x, i, f1, f2))
        r = add(r, f(x + 1, (md * 10 + i) % m, f1 or i > a[x] - '0',
                     f2 or i < b[x]));
    }
  }
  return r;
}
int main() {
  scanf("%d %d", &m, &d);
  scanf("%s %s", a + 1, b + 1);
  n = strlen(a + 1);
  memset(dp, -1, sizeof(dp));
  printf("%d\n", f(1, 0, 0, 0));
  return 0;
}
