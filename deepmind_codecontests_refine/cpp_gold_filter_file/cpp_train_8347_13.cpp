#include <bits/stdc++.h>
using namespace std;
int n, a[500500], prv[500500], mx[500500], nx[500500];
long long ans;
inline void update(int k, int v) {
  if (nx[k] >= v) return;
  nx[k] = v;
  if (v > mx[k]) swap(nx[k], mx[k]);
}
int solve(int y) {
  int up = (500500 - 1) / y + 1;
  long long cnt = 0, rlt = 0;
  mx[up] = nx[up] = -1;
  for (int k = up - 1; ~k; k--) {
    cnt += 1ll * k * (a[k * y] - a[min(500500 - 1, (k + 1) * y)]);
    int p = prv[min(500500, (k + 1) * y) - 1];
    mx[k] = mx[k + 1], nx[k] = nx[k + 1];
    if (p < k * y) continue;
    update(k, p - k * y);
    if (a[p] > a[p + 1] + 1)
      update(k, p - k * y);
    else if (p)
      update(k, prv[p - 1] - k * y);
  }
  for (int k = 0; k < up; k++) {
    if (mx[k] >= 0) rlt = max(rlt, min(cnt - k, 1ll * k * y + mx[k] >> 1));
    if (nx[k] >= 0) rlt = max(rlt, min(cnt - 2 * k, 1ll * k * y + nx[k]));
    long long x = 1ll * k * y + mx[k];
    if (mx[k] >= 0 && a[x] > 1) rlt = max(rlt, min(cnt - 2 * k - 1, x));
  }
  if (rlt < 2) rlt = 0;
  return rlt;
}
int main() {
  scanf("%d", &n);
  for (int i = 0, x; i < n; i++) scanf("%d", &x), a[x]++, prv[x] = x;
  for (int i = 1; i < 500500; i++)
    if (!prv[i]) prv[i] = prv[i - 1];
  for (int i = 500500 - 2; ~i; i--) a[i] += a[i + 1];
  for (int y = 2; y < 500500; y++) ans = max(ans, 1ll * solve(y) * y);
  printf("%I64d\n", ans);
}
