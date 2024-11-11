#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const int maxn = 200010;
int n;
int x[maxn], f[maxn], q[maxn];
int main() {
  int Case, k;
  scanf("%d", &Case);
  while (Case--) {
    scanf("%d%d", &n, &k);
    int y;
    for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &y);
    sort(x + 1, x + n + 1);
    if (2 * k >= x[n] - x[1])
      printf("%d\n", n);
    else {
      int H = 1, T = 0;
      int ans = 0;
      for (int i = 1; i <= n; i++) {
        q[++T] = i;
        while (x[q[H]] < x[q[T]] - k) H++;
        f[i] = max(f[i - 1], T - H + 1);
        int l = i, r = n;
        while (l < r - 1) {
          int mid = (l + r) >> 1;
          if (x[mid] > x[i] + k)
            r = mid;
          else
            l = mid;
        }
        if (x[r] <= x[i] + k) l = r;
        ans = max(ans, f[i - 1] + l - i + 1);
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
