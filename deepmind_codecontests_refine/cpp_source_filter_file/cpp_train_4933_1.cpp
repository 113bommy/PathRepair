#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010];
long long sum;
int main() {
  int i, j, n, m, k, s, t;
  scanf("%d%d%d", &n, &s, &t);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  if (s == t) {
    puts("0");
    return 0;
  };
  for (i = 1; i <= n; i++) {
    if (b[s] || s == t) break;
    b[s] = 1;
    s = b[s];
  }
  if (s == t)
    printf("%d\n", i + 1);
  else
    printf("%d\n", -1);
  return 0;
}
