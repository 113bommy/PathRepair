#include <bits/stdc++.h>
using namespace std;
inline long long calc(int a, int b, int k) {
  long long ans = (long long)(k + 3 - a) * a * b - (long long)a * b * b;
  return ans;
}
int main() {
  int x, y, z, k;
  while (scanf("%d%d%d%d", &x, &y, &z, &k) != EOF) {
    if (x + y + z < k + 3) k = x + y + z - 3;
    long long ans = 0;
    for (int a = 1; a <= min(x, k + 3); ++a) {
      int le = max(1, k + 3 - a - z);
      int ri = min(k + 2 - a, y);
      if (le > ri) continue;
      int b = (k + 3 - a) / 2;
      if (b >= le && b <= ri) {
        ans = max(ans, calc(a, b, k));
      }
      b = (k + 3 - a + 1) / 2;
      if (b >= le && b <= ri) {
        ans = max(ans, calc(a, b, k));
      }
      ans = max(ans, calc(a, le, k));
      ans = max(ans, calc(a, ri, k));
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
