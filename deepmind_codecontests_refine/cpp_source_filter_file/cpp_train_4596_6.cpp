#include <bits/stdc++.h>
using namespace std;
const int mo = 992844353;
const int N = 265000;
int n, k, m, A, B, C, S;
int a[N], b[N], c[N];
int cnt[N], v1[N], v2[N], v3[N];
int tmp1[N], tmp2[N];
int power(int x, int y) {
  int s = 1;
  for (; y; y /= 2, x = 1ll * x * x % mo)
    if (y & 1) s = 1ll * s * x % mo;
  return s;
}
void solve(int *a, int *b) {
  for (int d = 1; d <= m; d <<= 1)
    for (int i = 0; i < m; i += (d << 1))
      for (int j = i; j < i + d; j++) {
        int x = a[j], y = a[j + d];
        a[j] = x + y, a[j + d] = x - y;
      }
  for (int i = (int)(0); i <= (int)(m); i++) b[i] = (n + a[i]) / 2;
}
void IFWT(int *a) {
  for (int d = 1; d <= m; d <<= 1)
    for (int i = 0; i < m; i += (d << 1))
      for (int j = i; j < i + d; j++) {
        int x = a[j], y = a[j + d];
        a[j] = 1ll * (x + y) * (mo + 1) / 2 % mo;
        a[j + d] = 1ll * (x - y) * (mo + 1) / 2 % mo;
      }
}
int main() {
  scanf("%d%d%d%d%d", &n, &k, &A, &B, &C);
  m = (1 << k) - 1;
  for (int i = (int)(1); i <= (int)(n); i++) {
    scanf("%d%d%d", &a[i], &b[i], &c[i]);
    S ^= a[i];
    b[i] ^= a[i];
    c[i] ^= a[i];
  }
  for (int i = (int)(0); i <= (int)(m); i++) cnt[i] = 0;
  for (int i = (int)(1); i <= (int)(n); i++) ++cnt[b[i]];
  solve(cnt, v1);
  for (int i = (int)(0); i <= (int)(m); i++) cnt[i] = 0;
  for (int i = (int)(1); i <= (int)(n); i++) ++cnt[c[i]];
  solve(cnt, v2);
  for (int i = (int)(0); i <= (int)(m); i++) cnt[i] = 0;
  for (int i = (int)(1); i <= (int)(n); i++) ++cnt[b[i] ^ c[i]];
  solve(cnt, v3);
  for (int i = (int)(0); i <= (int)(m); i++) {
    int V00 = (v1[i] + v2[i] + v3[i] - n) / 2;
    int V01 = v1[i] - V00;
    int V10 = v2[i] - V00;
    int V11 = v3[i] - V00;
    a[i] = 1ll * power((1LL * A + B + C) % mo, V00) *
           power((1LL * A + B - C) % mo, V01) % mo *
           power((1LL * A - B + C) % mo, V10) % mo *
           power((1LL * A - B - C) % mo, V11) % mo;
  }
  IFWT(a);
  for (int i = (int)(0); i <= (int)(m); i++)
    printf("%d ", (a[i ^ S] % mo + mo) % mo);
}
