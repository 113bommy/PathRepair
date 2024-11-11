#include <bits/stdc++.h>
using namespace std;
const int p = 1e9 + 7, iv = 5e8 + 4;
int f[3000002], n, s[3000002], c1[18][300002], c2[3000002], c3[3000002],
    ca[3000002];
int a[18][300002], ct[3000002], b[18][300002], c[3000002];
inline void fwt_or(int x[], int len, int mde) {
  for (int i = 2; i <= len; i <<= 1)
    for (int j = 0, stp = i >> 1; j < len; j += i)
      for (int k = j; k < j + stp; k++)
        (x[k + stp] += mde > 0 ? x[k] : (p - x[k])) %= p;
}
inline void fwt_and(int x[], int len, int mde) {
  for (int i = 2; i <= len; i <<= 1)
    for (int j = 0, stp = i >> 1; j < len; j += i)
      for (int k = j; k < j + stp; k++)
        (x[k] += mde > 0 ? x[k + stp] : (p - x[k + stp])) %= p;
}
inline void fwt_xor(int x[], int len, int mde) {
  for (int i = 2; i <= len; i <<= 1)
    for (int j = 0, stp = i >> 1; j < len; j += i)
      for (int k = j; k < j + stp; k++) {
        int t1 = x[k], t2 = x[k + stp];
        x[k] = (t1 + t2) % p, x[k + stp] = (t1 - t2 + p) % p;
        if (mde < 0)
          x[k] = 1ll * x[k] * iv % p, x[k + stp] = 1ll * x[k + stp] * iv % p;
      }
}
int main() {
  f[1] = 1;
  for (int i = 2; i <= 1000000; i++) f[i] = (f[i - 1] + f[i - 2]) % p;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
  for (int i = 1; i < (1 << 17); i++) ct[i] = ct[i >> 1] + (i & 1);
  for (int i = 1; i <= n; i++)
    c1[ct[s[i]]][s[i]]++, c3[s[i]]++, a[ct[s[i]]][s[i]]++, c[s[i]]++,
        (c2[s[i]] += f[s[i]]) %= p;
  for (int i = 0; i < 17; i++)
    fwt_or(c1[i], (1 << 17), 1), fwt_or(a[i], (1 << 17), 1);
  for (int i = 0; i < 17; i++)
    for (int j = 0; i + j < 17; j++)
      for (int ii = 0; ii < (1 << 17); ii++)
        (b[i + j][ii] += 1ll * c1[i][ii] * a[j][ii] % p) %= p;
  for (int i = 0; i < 17; i++) {
    for (int j = 0; j < (1 << 17); j++) c1[i][j] = b[i][j];
    fwt_or(c1[i], (1 << 17), -1);
  }
  fwt_xor(c, (1 << 17), 1), fwt_xor(c3, (1 << 17), 1);
  for (int ii = 0; ii < (1 << 17); ii++)
    c3[ii] = 1ll * c3[ii] * c[ii] % p, ca[ii] = c1[ct[ii]][ii];
  fwt_xor(c3, (1 << 17), -1);
  for (int i = 0; i < (1 << 17); i++)
    ca[i] = 1ll * ca[i] * f[i] % p, c3[i] = 1ll * c3[i] * f[i] % p;
  fwt_and(ca, (1 << 17), 1), fwt_and(c2, (1 << 17), 1),
      fwt_and(c3, (1 << 17), 1);
  for (int ii = 0; ii < (1 << 17); ii++)
    ca[ii] = 1ll * ca[ii] * c2[ii] % p * c3[ii] % p;
  fwt_and(ca, (1 << 17), -1);
  int ans = 0;
  for (int i = 0; i < 17; i++) ans = (ans + ca[1 << i]) % p;
  printf("%d\n", ans);
}
