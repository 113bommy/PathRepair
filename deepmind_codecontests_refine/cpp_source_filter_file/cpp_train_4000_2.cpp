#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main() {
  int n, m, x;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x, &a[i]);
  }
  sort(a, a + m);
  int ans = 1;
  for (int i = 2; i <= min(n, m); i++) {
    int t = (i - 1) / 2;
    if ((i - 1) % 2) {
      if ((long long)(t + 1) * m <= n) ans = i;
    } else {
      if ((long long)t * m + 1 <= n) ans = i;
    }
  }
  long long sum = 0;
  for (int i = 0; i < ans; i++) {
    sum += a[m - 1 - i];
  }
  printf("%I64d\n", sum);
}
