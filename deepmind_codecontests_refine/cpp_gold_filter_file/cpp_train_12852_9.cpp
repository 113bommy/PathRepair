#include <bits/stdc++.h>
using namespace std;
struct node {
  int a;
  int num;
} p[2010];
bool cmp(node aa, node bb) { return aa.a < bb.a; }
int main() {
  int n, k, a[2010], i, q, m = 1, sum = 0;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  if (n <= k) {
    sort(a, a + n);
    printf("%d", 2 * a[n - 1] - 2);
    return 0;
  }
  sort(a, a + n);
  p[0].a = 1;
  for (i = 0; i < n; i++) {
    p[i].num = 1;
  }
  for (i = 0; i < n - 1; i++) {
    p[m].a = a[i];
    if (a[i] == a[i + 1]) {
      p[m].num++;
    } else {
      m++;
      p[m].a = a[i + 1];
    }
  }
  sort(p + 1, p + m + 1, cmp);
  for (i = 1; i <= m; i++) {
    if (n % k == 0) {
      q = 2 * (n / k) - 1;
    } else {
      q = 2 * (n / k) + 1;
    }
    sum += (p[i].a - p[i - 1].a) * q;
    n -= p[i].num;
  }
  sum += p[m].a - 1;
  printf("%d", sum);
  return 0;
}
