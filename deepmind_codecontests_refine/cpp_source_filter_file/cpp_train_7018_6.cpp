#include <bits/stdc++.h>
const int maxn = 100010;
int val[maxn];
long long Left[maxn];
long long Copy[maxn];
int n;
int solve(long long x) {
  int l = 0, r = n - 1;
  while (l < r) {
    int m = (l + r) / 2 + 1;
    if (x >= Left[m])
      l = m;
    else
      r = m - 1;
  }
  if (!val[l])
    return solve((x - Left[l]) % Copy[l] + 1);
  else
    return val[l];
}
int main() {
  scanf("%d", &n);
  long long L = 1;
  for (int i = 0; i < n; i++) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int a;
      scanf("%d", &a);
      val[i] = a;
      Left[i] = L;
      L++;
    } else {
      int a, b;
      scanf("%d %d", &a, &b);
      val[i] = 0;
      Left[i] = L;
      Copy[i] = b;
      L += (long long)a * b;
    }
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    long long k;
    scanf("%I64d", &k);
    printf("%d\n", solve(k));
  }
  return 0;
}
