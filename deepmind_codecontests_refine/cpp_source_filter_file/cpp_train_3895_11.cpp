#include <bits/stdc++.h>
using namespace std;
int T, a, n, p, h, i, j, k, ans;
int cal(int x, int y, int z) {
  if (!y) return x;
  if ((long long)x * y < z) {
    if (z == p)
      return x;
    else
      return max(x, z - x * y);
  }
  int tmp = (long long)x * y / z + ((long long)x * y % z != 0);
  if ((long long)x * y % z + x <= z / x * x) --tmp;
  return cal(x - z % x, tmp - 1, x);
}
int main() {
  scanf("%d", &T);
  for (; T; --T) {
    scanf("%d%d%d%d", &a, &n, &p, &h);
    if (cal(a % p, n, p) <= h)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
