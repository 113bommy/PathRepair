#include <bits/stdc++.h>
using namespace std;
const int mm = 1e9 + 7;
const int N = (1 << 17);
const int inv2 = 500000004;
int n;
int A[N], B[N], C[N], s[N], c[N][18], d[18], f[N];
void fwtxor(int *a, int n, int op) {
  for (int d = 1; d < n; d <<= 1)
    for (int m = d << 1, i = 0; i < n; i += m)
      for (int j = 0; j < d; j++) {
        int x = a[i + j], y = a[i + j + d];
        if (op == 1)
          a[i + j] = 1ll * (x + y) % mm, a[i + j + d] = 1ll * (x - y + mm) % mm;
        else
          a[i + j] = 1ll * (x + y) * inv2 % mm,
                a[i + j + d] = 1ll * (x - y + mm) * inv2 % mm;
      }
}
void fwt(int n, int op) {
  for (int d = 1; d < n; d <<= 1)
    for (int m = d << 1, i = 0; i < n; i += m)
      for (int j = 0; j < d; j++)
        for (int o = 0; o <= 17; o++) {
          int x = c[i + j][o], y = c[i + j + d][o];
          if (op == 1)
            c[i + j + d][o] = 1ll * (x + y) % mm;
          else
            c[i + j + d][o] = 1ll * (y - x + mm) % mm;
        }
}
void fwtand(int *a, int n, int op) {
  for (int d = 1; d < n; d <<= 1)
    for (int m = d << 1, i = 0; i < n; i += m)
      for (int j = 0; j < d; j++) {
        int x = a[i + j], y = a[i + j + d];
        if (op == 1)
          a[i + j] = 1ll * (x + y) % mm;
        else
          a[i + j] = 1ll * (x - y + mm) % mm;
      }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    s[x]++;
  }
  memcpy(C, s, sizeof(s));
  fwtxor(C, N, 1);
  for (int i = 0; i <= N - 1; i++) C[i] = 1ll * C[i] * C[i] % mm;
  fwtxor(C, N, -1);
  for (int i = 0; i <= N - 1; i++) c[i][__builtin_popcount(i)] = s[i];
  fwt(N, 1);
  for (int i = 0; i < N; i++) {
    memset(d, 0x00, sizeof d);
    for (int j = 0; j <= 17; j++)
      for (int k = 0; k <= 17 - j; k++)
        d[j + k] = (d[j + k] + 1ll * c[i][j] * c[i][k]) % mm;
    memcpy(c[i], d, sizeof d);
  }
  fwt(N, -1);
  for (int i = 0; i <= N - 1; i++) B[i] = c[i][__builtin_popcount(i)];
  memcpy(A, s, sizeof(s));
  f[0] = 0, f[1] = 1;
  for (int i = 2; i <= N - 1; i++) f[i] = 1ll * (f[i - 1] + f[i - 2]) % mm;
  for (int i = 0; i <= N - 1; i++)
    A[i] = 1ll * A[i] * f[i] % mm, B[i] = 1ll * B[i] * f[i] % mm,
    C[i] = 1ll * C[i] * f[i] % mm;
  fwtand(A, N, 1);
  fwtand(B, N, 1);
  fwtand(C, N, 1);
  for (int i = 0; i <= N - 1; i++) A[i] = 1ll * A[i] * B[i] % mm * C[i] % mm;
  fwtand(A, N, -1);
  int ans = 0;
  for (int i = 0; i <= 16; i++) ans = 1ll * (ans + A[1 << i]) % mm;
  cout << ans << endl;
  return 0;
}
