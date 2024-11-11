#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[5005];
int main() {
  scanf("%d %d", &n, &m);
  long long sum = 0;
  int k = -1;
  for (int i = 1; i <= n; i++)
    if (sum + (i - 1) / 2 <= m) sum += (i - 1) / 2, k = i;
  if (k == n && sum < m) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= k; i++) a[i] = i;
  if (k + 1 <= n) a[k + 1] = 2 * k + 1 - 2 * (m - sum);
  for (int i = k + 2; i <= n; i++) a[i] = 100000000 + 1000 * i;
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
