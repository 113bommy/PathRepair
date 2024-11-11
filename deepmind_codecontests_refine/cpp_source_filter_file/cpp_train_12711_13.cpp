#include <bits/stdc++.h>
const int N = 1 << 21;
long long a[N], b[N];
char c;
int n, x, p[N];
void fwt(long long a[], int f) {
  for (int mid = 1; mid < n; mid <<= 1)
    for (int i = 0; i < n; i += mid << 1)
      for (int j = 0; j < mid; j++) a[i + j + mid] += a[i + j] * f;
}
int main() {
  scanf("%d", &n);
  n = 1 << n;
  for (int i = 0; i < n; i++)
    if (i & 1)
      p[i] = p[i >> 1] + 1;
    else
      p[i] = p[i >> 1];
  for (int i = 0; i < n; i++) p[i] *= 2;
  for (int i = 0; i < n; i++) scanf(" %c", &c), a[i] = 1ll * (c - '0') << p[i];
  for (int i = 0; i < n; i++) scanf(" %c", &c), b[i] = 1ll * (c - '0') << p[i];
  fwt(a, 1), fwt(b, 1);
  for (int i = 0; i < n; i++) a[i] *= b[i];
  fwt(a, -1);
  for (int i = 0; i < n; i++) printf("%d", (a[i] >> p[i]) % 4);
}
