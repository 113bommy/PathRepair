#include <bits/stdc++.h>
using namespace std;
int m, n, a[10000001 + 100];
int main() {
  long long sum = 0;
  int i = 1, j;
  scanf("%d%d", &n, &m);
  for (; i * i < 10000001; i++)
    for (j = i * i; j <= 10000001; j += i * i) a[j] = i * i;
  for (i = n; i < n + m; i++) sum += i / a[i];
  printf("%I64d\n", sum);
}
