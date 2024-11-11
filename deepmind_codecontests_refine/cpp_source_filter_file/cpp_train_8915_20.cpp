#include <bits/stdc++.h>
const int N = 400005;
int n, a[N], c[N], b[N], x, cnt;
int dp0[N], dp1[N];
int lowbit(int x) { return x & (-x); }
struct BIT {
  int s[N];
  void upd(int x, int y) {
    while (x <= cnt) {
      s[x] = std::max(s[x], y);
      x += lowbit(x);
    }
  }
  int getsum(int x) {
    int ret = 0;
    while (x) {
      ret = std::max(ret, s[x]);
      x -= lowbit(x);
    }
    return ret;
  }
} T1, T2, T3;
bool chk() {
  for (int i = 1; i < n; i++)
    if (a[i] > a[i + 1]) return 0;
  return 1;
}
int main() {
  scanf("%d", &n);
  n++;
  for (int i = 1; i <= n; i++) {
    if (i < n)
      scanf("%d", &a[i]);
    else
      a[i] = 1000000005;
    c[++cnt] = a[i] - i;
    c[++cnt] = a[i] - (i - 1);
  }
  if (chk()) return puts("0"), 0;
  std::sort(c + 1, c + cnt + 1);
  cnt = std::unique(c + 1, c + cnt + 1) - c - 1;
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    a[i] = std::lower_bound(c + 1, c + cnt + 1, x - i) - c;
    b[i] = std::lower_bound(c + 1, c + cnt + 1, x - (i - 1)) - c;
  }
  dp0[1] = 1;
  T1.upd(a[1], 1);
  for (int i = 2; i <= n; i++) {
    dp0[i] = T1.getsum(a[i]) + 1;
    dp1[i] = std::max(T2.getsum(b[i]), T3.getsum(b[i])) + 1;
    T1.upd(a[i], dp0[i]);
    T2.upd(b[i], dp1[i]);
    T3.upd(a[i - 1], dp0[i - 1]);
  }
  printf("%d\n", n - dp1[n] - 1);
}
