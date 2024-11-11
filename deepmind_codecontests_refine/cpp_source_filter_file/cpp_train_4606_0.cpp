#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[11];
  memset(a, 0, sizeof(a));
  int n, sum = 1;
  scanf("%d", &n);
  while (n) {
    a[sum] = n % 2;
    sum++;
    n = n / 2;
  }
  int t;
  t = a[1];
  a[1] = a[5];
  a[5] = t;
  t = a[3];
  a[3] = a[4];
  a[4] = a[4];
  int qwq = 1, ans = 0;
  for (int i = 1; i <= 6; i++) {
    ans = ans + a[i] * qwq;
    qwq = qwq * 2;
  }
  printf("%d\n", ans);
  return 0;
}
