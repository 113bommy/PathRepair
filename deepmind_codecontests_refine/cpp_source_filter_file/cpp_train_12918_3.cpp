#include <bits/stdc++.h>
using namespace std;
struct b {
  int a1;
  int a2;
};
bool cmp(b x, b y) { return x.a1 > y.a1; }
int main() {
  int n, m;
  int sum = 0;
  struct b a[2000];
  int c[2000];
  int d[2000];
  scanf("%d%d", &n, &m);
  int i;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i].a1);
    a[i].a2 = i;
  }
  int j = 0;
  sort(a + 1, a + n + 1, cmp);
  for (i = 1; i <= m; i++) {
    sum += a[i].a1;
    c[++j] = a[i].a2;
  }
  printf("%d\n", sum);
  sort(c + 1, c + j + 1);
  c[0] = 0;
  for (i = 1; i <= m - 1; i++) {
    d[i] = c[i] - c[i - 1];
  }
  d[m] = n - d[m - 1];
  for (i = 1; i <= m - 1; i++) {
    printf("%d ", d[i]);
  }
  printf("%d", d[m]);
  return 0;
}
