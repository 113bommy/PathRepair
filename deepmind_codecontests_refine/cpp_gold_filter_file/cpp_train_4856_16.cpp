#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::max;
using std::min;
int n, len, inv, cnt[140000], size[140000], fib[140000], A[18][140000],
    B[18][140000], C[140000], D[140000], E[140000], ans;
int cal(int x) {
  x -= x < 1000000007 ? 0 : 1000000007;
  return x;
}
class FWT {
 public:
  void dft(int *x, int f, int op) {
    for (int i = 1, a, b; i < len; i <<= 1)
      for (int j = 0; j < len; j += i << 1)
        for (int k = 0; k < i; k++) {
          a = x[j + k], b = x[i + j + k];
          if (op == 1)
            f > 0 ? x[i + j + k] = cal(b + a)
                  : x[i + j + k] = cal(b - a + 1000000007);
          if (op == 2)
            f > 0 ? x[j + k] = cal(a + b) : x[j + k] = cal(a - b + 1000000007);
          if (op == 3) {
            x[j + k] = cal(a + b), x[i + j + k] = cal(a - b + 1000000007);
            if (f < 0)
              x[j + k] = (long long)x[j + k] * inv % 1000000007,
                    x[i + j + k] = (long long)x[i + j + k] * inv % 1000000007;
          }
        }
  }
} fwt;
int main() {
  scanf("%d", &n), len = 1 << 17, inv = 1000000007 + 1 >> 1,
                   fib[1] = size[1] = 1;
  for (int i = 1, a; i <= n; i++) scanf("%d", &a), cnt[a]++;
  for (int i = 2; i < len; i++)
    fib[i] = cal(fib[i - 1] + fib[i - 2]), size[i] = size[i >> 1] + (i & 1);
  for (int i = 0; i < len; i++)
    A[size[i]][i] = E[i] = cnt[i],
    D[i] = (long long)cnt[i] * fib[i] % 1000000007;
  for (int i = 0; i < 18; i++) fwt.dft(A[i], 1, 1);
  for (int i = 0; i < 18; i++)
    for (int j = 0; i + j < 18; j++)
      for (int k = 0; k < len; k++)
        B[i + j][k] =
            cal(B[i + j][k] + (long long)A[i][k] * A[j][k] % 1000000007);
  for (int i = 0; i < 18; i++) fwt.dft(B[i], -1, 1);
  for (int i = 0; i < len; i++)
    C[i] = (long long)B[size[i]][i] * fib[i] % 1000000007;
  fwt.dft(E, 1, 3);
  for (int i = 0; i < len; i++) E[i] = (long long)E[i] * E[i] % 1000000007;
  fwt.dft(E, -1, 3);
  for (int i = 0; i < len; i++) E[i] = (long long)E[i] * fib[i] % 1000000007;
  fwt.dft(C, 1, 2), fwt.dft(D, 1, 2), fwt.dft(E, 1, 2);
  for (int i = 0; i < len; i++)
    C[i] = (long long)C[i] * D[i] % 1000000007 * E[i] % 1000000007;
  fwt.dft(C, -1, 2);
  for (int i = 0; i < 18; i++) ans = cal(ans + C[1 << i]);
  printf("%d\n", ans);
  return 0;
}
