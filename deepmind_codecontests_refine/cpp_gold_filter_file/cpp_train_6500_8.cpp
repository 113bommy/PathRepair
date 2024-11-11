#include <bits/stdc++.h>
using namespace std;
int a[100001], b[100001];
long long sum_a[100001], sum_b[100001];
int main() {
  int i, j, t, n, m;
  int typ, l, r;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    b[i] = a[i];
    sum_a[i] = a[i];
    sum_a[i] += sum_a[i - 1];
  }
  sort(b + 1, b + n + 1);
  for (i = 1; i <= n; ++i) {
    sum_b[i] = b[i];
    sum_b[i] += sum_b[i - 1];
  }
  scanf("%d", &m);
  while (m--) {
    scanf("%d%d%d", &typ, &l, &r);
    if (typ == 1) {
      printf("%I64d\n", sum_a[r] - sum_a[l - 1]);
    } else {
      printf("%I64d\n", sum_b[r] - sum_b[l - 1]);
    }
  }
  getchar();
  getchar();
  return 0;
}
