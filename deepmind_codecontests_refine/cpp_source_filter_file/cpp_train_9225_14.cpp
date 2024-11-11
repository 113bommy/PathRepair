#include <bits/stdc++.h>
using namespace std;
long long n, k, m, ans;
int a[(100000 + 100)], f[(100000 + 100)], t[(100000 + 100)], top;
int L, R;
void readxx() {
  scanf("%lld%lld%lld", &n, &k, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
}
void work() {
  for (int i = 1; i <= n; i++) {
    t[++top] = a[i];
    if (top == 1 || t[top] != t[top - 1])
      f[top] = 1;
    else
      f[top] = f[top - 1] + 1;
    if (f[top] == k) top -= k;
  }
  R = top;
  while (L < R && t[L] == t[R]) {
    int l = L, r = R, cnt = 0;
    while (l < r && t[l] == t[L] && cnt < k) ++cnt, ++l;
    while (l < r && t[r] == t[R] && cnt < k) ++cnt, --r;
    if (cnt == k)
      ans += k, L = l, R = r;
    else
      break;
  }
}
void findAns() {
  bool fg = true;
  for (int i = L + 1; i <= R; i++) {
    if (t[i] != t[i - 1]) {
      fg = false;
      break;
    }
  }
  if (fg)
    printf("%lld",
           (1ll * (R - L + 1) * m % k) ? (1ll * (R - L + 1) * m % k + ans) : 0);
  else
    printf("%lld", 1ll * (R - L + 1) * m + ans);
}
int main() {
  readxx();
  work();
  findAns();
  return 0;
}
