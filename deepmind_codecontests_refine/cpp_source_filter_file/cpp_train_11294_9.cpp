#include <bits/stdc++.h>
using namespace std;
int gint() {
  char c;
  int f = 1;
  while (c = getchar(), c < 48 || c > 57)
    if (c == '-') f = -1;
  int x = 0;
  for (; c > 47 && c < 58; c = getchar()) {
    x = x * 10 + c - 48;
  }
  return x * f;
}
int n, a[200005], b[200005];
int main() {
  n = gint();
  for (int i = n; i; --i) a[i] = gint() - i;
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; ++i) b[i] = a[n - i + 1] + i;
  bool flag = 0;
  for (int i = 1; i <= n; ++i)
    if (b[i] < 0 || (i > 1 && b[i] > b[i - 1])) {
      flag = 1;
      break;
    }
  if (flag)
    puts(":(");
  else {
    for (int i = 1; i <= n; ++i) printf("%d ", b[i]);
    puts("");
  }
  return 0;
}
