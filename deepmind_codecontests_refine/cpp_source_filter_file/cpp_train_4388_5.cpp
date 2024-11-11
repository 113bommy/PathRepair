#include <bits/stdc++.h>
using namespace std;
const int maxN = 100000 + 5;
int a[2 * maxN];
int sum1[maxN];
int sum2[maxN];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = n; i >= 1; i--) {
    sum1[i] = sum1[i + 1];
    sum2[i] = sum2[i + 1];
    if (i % 2)
      sum1[i] += a[i];
    else
      sum2[i] += a[i];
  }
  int k1 = 0;
  int k2 = 0;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int t1, t2;
    t1 = k1 + sum2[i + 1];
    t2 = k2 + sum1[i + 1];
    if (t1 == t2) ans++;
    if (i % 2)
      k1 += a[i];
    else
      k2 += a[i];
  }
  printf("%d\n", ans);
  return 0;
}
