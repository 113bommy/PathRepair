#include <bits/stdc++.h>
using namespace std;
inline void read(long long& n) {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
  n = x * f;
}
int outputarray[20];
inline void write(long long k) {
  long long num = 0;
  if (k < 0) putchar('-'), k = -k;
  do {
    outputarray[++num] = k % 10, k /= 10;
  } while (k);
  while (num) putchar(outputarray[num--] + '0');
  puts("");
}
long long a[200100], f[200100], sum[200100], c[200100], mmxx;
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) read(a[n - i + 1]);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
  for (int i = 1; i < n; i++)
    f[i] = mmxx + sum[n], mmxx = max(mmxx, -f[i] - sum[i]);
  f[n] = sum[n];
  for (int j = 1; j < n - 1; j++) f[n] = max(f[n], -f[j] + sum[n] - sum[j]);
  write(f[n]);
}
