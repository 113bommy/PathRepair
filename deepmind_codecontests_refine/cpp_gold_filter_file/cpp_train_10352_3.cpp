#include <bits/stdc++.h>
using namespace std;
const int N = 21;
int num[1 << N];
int a[1 << N];
int b[1 << N];
long long val[N];
long long all[N];
long long rev(int* num, int i) {
  if (i == 0) return 0;
  int m = 1 << (i - 1);
  long long ret = rev(num, i - 1) + rev(num + m, i - 1);
  memcpy(a, num, sizeof(int) * m);
  memcpy(b, num + m, sizeof(int) * m);
  int p = 0;
  for (int j = 0; j < m; j++) {
    while (p < m && a[p] <= b[j]) p++;
    ret += m - p;
  }
  p = 0;
  int q = 0;
  int j = 0;
  while (p < m && q < m) {
    if (a[p] <= b[q])
      num[j++] = a[p++];
    else
      num[j++] = b[q++];
  }
  while (p < m) num[j++] = a[p++];
  while (q < m) num[j++] = b[q++];
  for (int j = 0, k = 0; j < m * 2; j = k) {
    while (k < m * 2 && num[k] == num[j]) k++;
    int c = k - j;
    all[i] -= 1ll * c * (c - 1) / 2;
  }
  val[i] += ret;
  return ret;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (1 << n); i++) scanf("%d", num + i);
  for (int i = 1; i <= n; i++) all[i] = 1ll * (1 << n) * ((1 << i) - 1) / 2;
  rev(num, n);
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int q;
    scanf("%d", &q);
    long long d = all[q] - val[q] - val[q];
    for (int j = 1; j <= q; j++) val[j] = all[j] - val[j];
    for (int j = q + 1; j <= n; j++) val[j] = val[j] + d;
    printf("%I64d\n", val[n]);
  }
  return 0;
}
