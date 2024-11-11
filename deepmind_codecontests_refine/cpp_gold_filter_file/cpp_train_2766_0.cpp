#include <bits/stdc++.h>
using std::swap;
const int mu = 998244353;
const int inv = 332748118;
int n, m, l, limit = 1, r[1 << 21];
int ans[3][1 << 21], t1[3][1 << 21], wn[1 << 21], t2[3][1 << 21], k;
int ksm(int x, int y, int ans = 1) {
  for (; y; y >>= 1, x = 1ll * x * x % mu)
    if (y & 1) ans = 1ll * ans * x % mu;
  return ans;
}
inline void reduce(int &x) { x += x >> 31 & mu; }
void fft(int *a, int flag) {
  for (int i = 0; i < limit; i++)
    if (i < r[i]) {
      swap(a[i], a[r[i]]);
    }
  for (int mid = 1; mid < limit; mid <<= 1) {
    int w = ksm(flag == 1 ? 3 : inv, (mu - 1) / (mid << 1));
    wn[0] = 1;
    for (int i = 1; i < mid; ++i) wn[i] = 1ll * wn[i - 1] * w % mu;
    for (int r = mid << 1, j = 0; j < limit; j += r) {
      for (int k = 0; k < mid; k++) {
        int x = a[k + j], y = 1ll * wn[k] * a[k + mid + j] % mu;
        reduce(a[k + j] += y - mu);
        reduce(a[k + mid + j] = x - y);
      }
    }
  }
  if (flag == -1) {
    int Inv = ksm(limit, mu - 2);
    for (int i = 0; i < limit; i++) a[i] = 1ll * a[i] * Inv % mu;
  }
}
void mul() {
  for (int i = 0; i <= 2; i++) fft(ans[i], 1);
  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j < limit; j++) {
      t1[i][j] = 1ll * ans[i / 2][j] * ans[i - i / 2][j] % mu;
      t2[i][j] = 1ll * ans[i / 2 + 1][j] * ans[i - i / 2 + 1][j] % mu;
    }
  }
  for (int i = 0; i <= 2; i++) {
    fft(t1[i], -1), fft(t2[i], -1);
    ans[i][0] = t1[i][0];
    for (int j = 1; j <= k; j++)
      reduce(ans[i][j] = t1[i][j] + t2[i][j - 1] - mu);
    for (int j = k + 1; j < limit; j++) ans[i][j] = 0;
  }
}
void add() {
  for (int i = 2; i >= 1; i--)
    for (int j = 0; j <= k; j++) ans[i][j] = ans[i - 1][j];
  ans[0][0] = 1;
  for (int i = 1; i <= k; i++) {
    reduce(ans[0][i] = ans[1][i] + ans[1][i - 1] - mu);
    reduce(ans[0][i] += ans[2][i - 1] - mu);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  ans[0][0] = 1;
  while (limit <= k * 2) limit <<= 1, l++;
  for (int i = 0; i < limit; i++)
    r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
  int f = 0;
  for (int i = 1 << 30; i; i >>= 1) {
    if (f) mul();
    if (n & i) add(), f = 1;
  }
  for (int i = 1; i <= k; i++) printf("%d ", ans[0][i]);
}
