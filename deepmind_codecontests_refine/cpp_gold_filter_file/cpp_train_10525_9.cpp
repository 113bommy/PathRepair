#include <bits/stdc++.h>
using namespace std;
struct s1 {
  long long a, b;
  int x;
} a[200002];
int n;
long long t;
bool ans = true;
bool cmp1(s1 x, s1 y) {
  if (x.x != y.x) return x.x < y.x;
  return x.a < y.a;
}
int main() {
  scanf("%d%I64d", &n, &t);
  for (int i = 1; i <= n; ++i) scanf("%I64d", &a[i].a);
  a[n + 1].a = 2e18;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i].x);
  for (int i = n; i >= 1; --i)
    if (a[i].x != a[i + 1].x)
      a[i].b = a[i + 1].a + t - 1;
    else
      a[i].b = a[i + 1].b - 1;
  for (int i = 1; i <= n; ++i)
    if (a[i].x < i || a[i].x < a[i - 1].x ||
        (a[i].x > i && a[i].b < a[i + 1].a + t))
      ans = false;
  if (ans) {
    printf("Yes\n");
    for (int i = 1; i <= n; ++i) {
      printf("%I64d", a[i].b);
      if (i != n) printf(" ");
    }
  } else
    printf("No\n");
  return 0;
}
