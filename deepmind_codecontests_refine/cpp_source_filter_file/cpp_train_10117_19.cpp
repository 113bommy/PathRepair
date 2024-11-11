#include <bits/stdc++.h>
using namespace std;
const int N = 810;
const int M = 500010;
long long s[N][N];
int a[M];
int main() {
  int q;
  scanf("%d", &q);
  int blk = sqrt(q);
  while (q--) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    if (x == 1) {
      a[y] += z;
      for (int i = 1; i <= blk; i++) s[i][y % i] += z;
    } else if (y > blk) {
      long long ans = 0;
      for (int i = z; i < N; i += y) ans += a[i];
      printf("%lld\n", ans);
    } else
      printf("%lld\n", s[y][z]);
  }
  return 0;
}
