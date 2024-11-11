#include <bits/stdc++.h>
using namespace std;
int n, cnt[(1 << 21) + 10];
unsigned long long a[(1 << 21) + 10], b[(1 << 21) + 10], c[(1 << 21) + 10];
void getn(unsigned long long& x) {
  x = getchar();
  while (!isdigit(x)) x = getchar();
  x -= '0';
}
void FWT(unsigned long long* f, const int& n, const int& op) {
  for (int i = 2, tl = 1; i <= (1 << n); i <<= 1, tl <<= 1)
    for (int j = 0; j < (1 << n); j += i)
      for (int k = j; k < j + tl; ++k) f[k + tl] += f[k] * op;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < (1 << n); ++i)
    getn(a[i]), cnt[i] = cnt[i >> 1] + (i & 1), a[i] <<= (cnt[i] << 1);
  for (int i = 0; i < (1 << n); ++i) getn(b[i]), b[i] <<= (cnt[i] << 1);
  FWT(a, n, 1), FWT(b, n, 1);
  for (int i = 0; i < (1 << n); ++i) c[i] = a[i] * b[i];
  FWT(c, n, -1);
  for (int i = 0; i < (1 << n); ++i)
    printf("%d", (c[i] >> (cnt[i] << 1ll)) & 3);
  return 0;
}
