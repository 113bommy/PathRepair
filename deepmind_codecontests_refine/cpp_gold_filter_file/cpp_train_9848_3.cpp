#include <bits/stdc++.h>
using namespace std;
int a[2222];
int main() {
  int n, k, i, sum = 0;
  scanf("%d%d", &n, &k);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a, a + n + 1);
  for (i = 1; i <= k; i++) sum = sum + a[i];
  printf("%d", sum);
  return 0;
}
