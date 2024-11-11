#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int a[maxn], b[maxn];
char c[maxn];
int happya[maxn], happyb[maxn];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int A, B;
  scanf("%d", &A);
  int x;
  for (int i = 1; i <= A; ++i) scanf("%d", &x), happya[x] = 1;
  scanf("%d", &B);
  for (int i = 1; i <= B; ++i) scanf("%d", &x), happyb[x] = 1;
  int a0 = 0, b0 = 0;
  for (int i = 1; i <= n * m * 3; ++i) {
    if (happya[a0] || happyb[b0]) happya[a0] = happyb[b0] = 1;
    a0++;
    b0++;
    a0 %= n, b0 %= m;
  }
  bool ok = 1;
  for (int i = 0; i < n; ++i) ok &= happya[i];
  for (int i = 0; i < m; ++i) ok &= happyb[i];
  if (ok)
    puts("Yes");
  else
    puts("No");
}
