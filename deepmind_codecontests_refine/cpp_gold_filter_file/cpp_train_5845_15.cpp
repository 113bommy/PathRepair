#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, a[N], b[N];
long long sum;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (m); i++)
    scanf("%d", &a[i]), b[i] = (b[i - 1] + a[i]) % n, sum += a[i];
  b[m] = n;
  sort(b + 1, b + 1 + m);
  for (int i = m; i; i--) b[i] = b[i] - b[i - 1];
  printf("%lld\n", (sum - 1) / n + 1);
  for (int i = (1); i <= (m); i++) printf("%d ", b[i]);
  puts("");
  int j = 1;
  for (int i = (1); i <= (m); i++) {
    int x = a[i];
    while (x > 0) {
      x -= b[j];
      printf("%d ", i);
      j++;
      if (j > m) puts(""), j = 1;
    }
  }
  while (j > 1 && j <= m) printf("1 "), j++;
  return 0;
}
