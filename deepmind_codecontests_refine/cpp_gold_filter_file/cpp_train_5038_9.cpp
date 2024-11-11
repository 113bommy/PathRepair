#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 10;
const int P = (int)1e9;
int n, q, a[N];
long long fib[N * 2], *f;
int ft[2][N];
void Update(int *ft, int i, int v) {
  while (i <= n) {
    ft[i] = (ft[i] + v) % P;
    i += i & -i;
  }
}
int Query(int *ft, int l, int r) {
  int ans = 0;
  l--;
  for (; l; l -= l & -l) ans = (ans + P - ft[l]) % P;
  for (; r; r -= r & -r) ans = (ans + ft[r]) % P;
  return ans;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  f = fib + n;
  f[0] = 0;
  f[1] = 1;
  for (int i = -1; i >= -n; --i) f[i] = (f[i + 2] - f[i + 1] + P) % P;
  for (int i = 2; i <= n + 1; ++i) f[i] = (f[i - 1] + f[i - 2]) % P;
  for (int i = 1; i <= n; ++i) Update(ft[0], i, a[i] * f[i + 1] % P);
  for (int i = 1; i <= n; ++i) Update(ft[1], i, a[i] * f[i] % P);
  while (q--) {
    int k;
    scanf("%d", &k);
    if (k == 1) {
      int i, v;
      scanf("%d%d", &i, &v);
      Update(ft[0], i, (v + P - a[i]) * f[i + 1] % P);
      Update(ft[1], i, (v + P - a[i]) * f[i] % P);
      a[i] = v;
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      int x = Query(ft[0], l, r);
      int y = Query(ft[1], l, r);
      printf("%d\n", (int)((x * f[1 - l] + y * f[-l]) % P));
    }
  }
  return 0;
}
