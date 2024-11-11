#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N], s[N], v[N];
int main() {
  int n, m, sum = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
    if (i < m) v[i] = sum % n;
  }
  printf("%d\n", (sum + n - 1) / n);
  v[0] = 0, v[m + 1] = n;
  sort(v, v + m + 2);
  for (int i = 1; i <= m; i++) s[i] = v[i] - v[i - 1], printf("%d ", s[i]);
  puts("");
  int pt = 0;
  for (int i = 1, p; i <= m; i++) {
    p = a[i];
    while (p > 0) {
      p -= s[++pt];
      printf("%d ", i);
      pt = pt == m ? puts(""), 0 : pt;
    }
  }
  if (pt)
    for (int i = pt; i < m; i++) printf("1 ");
}
