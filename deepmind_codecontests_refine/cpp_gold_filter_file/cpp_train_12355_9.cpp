#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int inf = 0x3f3f3f3f;
long long labs(long long x) { return x < 0 ? -x : x; }
int n, l, w, L[maxn], R[maxn], x, y;
int main() {
  while (~scanf("%d%d%d", &n, &l, &w)) {
    int top1 = 0, top2 = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &x, &y);
      if (y == 1) {
        L[++top1] = x;
      } else {
        R[++top2] = x;
      }
    }
    sort(L + 1, L + 1 + top1);
    sort(R + 1, R + 1 + top2);
    long long ans = 0;
    for (int i = 1, j = 1; i <= top1; i++) {
      while (j <= top2 &&
             (1ll * w * (R[j] - L[i] + l) <= labs((long long)L[i] + R[j] + l)))
        j++;
      ans += (top2 - j + 1);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
