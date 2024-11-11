#include <bits/stdc++.h>
using namespace std;
int a[105];
int num[105][105];
int n;
int change(int x) {
  int i, j;
  int k1, k2;
  int sum;
  sum = 0;
  for (i = 1; i <= n; i++) {
    k1 = k2 = 0;
    for (j = 1; j <= x; j++) {
      if (num[i][j] == a[j])
        k1++;
      else
        k2++;
    }
    sum += min(k1, k2);
  }
  return sum;
}
int main() {
  int i, j;
  int m, k;
  int sum1, sum2, sum;
  while (scanf("%d%d%d", &n, &m, &k) != EOF) {
    sum = 0;
    for (i = 1; i <= n; i++)
      for (j = 1; j <= m; j++) scanf("%d", &num[i][j]);
    a[1] = 0;
    for (i = 2; i <= m; i++) {
      a[i] = 0;
      sum1 = change(i);
      a[i] = 1;
      sum2 = change(i);
      if (sum1 <= sum2)
        a[i] = 0;
      else
        a[i] = 1;
      sum = min(sum1, sum2);
    }
    if (sum > k)
      printf("-1\n");
    else
      printf("%d\n", sum);
  }
}
