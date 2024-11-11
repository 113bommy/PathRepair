#include <bits/stdc++.h>
struct P {
  int x1, y1, x2, y2;
  void PRINT() { printf("%d %d %d %d\n", x1, y1, x2, y2); }
} ans[400];
int main() {
  long long n;
  scanf("%I64d\n", &n);
  int m = 0, k = 2, len = 2, a[30];
  for (; n; n /= 6) a[++m] = n % 6;
  ans[1] = (P){1, 2, 2, 2};
  ans[2] = (P){2, 1, 2, 2};
  for (int i = 1; i <= m; i++) {
    if (a[i] <= 2) ans[++k] = (P){len - 1, len + 1, len, len + 1};
    if (a[i] % 3 == 0) ans[++k] = (P){len - 1, len + 2, len, len + 2};
    ans[++k] = (P){len + 1, len - 1, len + 1, len};
    if (a[i] % 3 != 2) ans[++k] = (P){len + 2, len - 1, len + 2, len};
    len += 2;
    if (i == m) break;
    ans[++k] = (P){len - 2, len, len - 2, len + 1};
    ans[++k] = (P){len - 1, len, len - 1, len + 1};
    ans[++k] = (P){len - 2, len + 2, len - 1, len + 2};
    ans[++k] = (P){len, len - 2, len + 1, len - 2};
    ans[++k] = (P){len, len - 1, len + 1, len - 1};
    ans[++k] = (P){len + 2, len - 2, len + 2, len - 1};
    if (len <= 4) continue;
    ans[++k] = (P){len - 4, len + 1, len - 3, len + 1};
    ans[++k] = (P){len + 1, len - 4, len + 1, len - 3};
  }
  printf("%d %d\n%d\n", len, len, k);
  for (int i = 1; i <= k; i++) ans[i].PRINT();
}
