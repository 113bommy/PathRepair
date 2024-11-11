#include <bits/stdc++.h>
using namespace std;
int n;
const int MAXN = 1024;
unsigned long long num[4][MAXN][MAXN];
static int getp(int a, int b) { return ((a & 1) << 1) | (b & 1); }
void qadd(int x, int y, unsigned long long v) {
  int p = getp(x, y);
  for (int a = y; a < MAXN; a |= a + 1)
    for (int b = x; b < MAXN; b |= b + 1) {
      num[p][a][b] ^= v;
    }
}
unsigned long long qget(int x, int y) {
  unsigned long long ans = 0;
  int p = getp(x, y) ^ 3;
  for (int b = x; b >= 0; b = (b & (b + 1)) - 1)
    for (int a = y; a >= 0; a = (a & (a + 1)) - 1) {
      ans ^= num[p][a][b];
    }
  return ans;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int t, x0, y0, x1, y1;
    scanf("%d %d%d%d%d", &t, &x0, &y0, &x1, &y1);
    if (t == 1) {
      unsigned long long r = 0;
      r ^= qget(x1, y1);
      r ^= qget(x1, y0 - 1);
      r ^= qget(x0 - 1, y1);
      r ^= qget(x0 - 1, y0 - 1);
      printf("%lld\n", r);
    } else {
      unsigned long long v;
      scanf("%lld", &v);
      qadd(x1, y1, v);
      qadd(x1, y0 - 1, v);
      qadd(x0 - 1, y1, v);
      qadd(x0 - 1, y0 - 1, v);
    }
  }
  return 0;
}
