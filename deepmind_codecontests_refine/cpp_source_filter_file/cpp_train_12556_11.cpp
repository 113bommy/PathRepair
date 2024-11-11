#include <bits/stdc++.h>
using namespace std;
const int MAX = (1 << 20) + 5, mod = 1e9 + 7, inv2 = 5e8 + 4;
int n, lim, ans;
int a[MAX];
char s[MAX];
void FWT(int *A, int tt = 1) {
  for (int i = 1; i < lim; i <<= 1)
    for (int l = i << 1, j = 0; j < lim; j += l)
      for (int k = 0, x, y; k < i; ++k) {
        x = A[j + k], y = A[i + j + k], A[j + k] = (x + y) % mod,
        A[i + j + k] = (x - y + mod) % mod;
        if (tt == -1)
          A[j + k] = 1ll * A[j + k] * inv2 % mod,
                A[i + j + k] = 1ll * A[i + j + k] * inv2 % mod;
      }
}
int GET_NUM(int x) {
  int num = 0;
  while (x) x &= x - 1, ++num;
  return num;
}
int main() {
  scanf("%d%s", &n, s), lim = 1 << n;
  for (int i = 0; i < lim; ++i) a[i] = s[i] - '0';
  FWT(a);
  for (int i = 0; i <= lim; ++i) a[i] = 1ll * a[i] * a[i] % mod;
  FWT(a, -1);
  for (int i = 0; i <= lim; ++i)
    if (a[i]) (ans += 1ll * a[i] * (1 << (n - GET_NUM(i)) % mod)) %= mod;
  return printf("%d", 1ll * ans * 3 % mod), 0;
}
