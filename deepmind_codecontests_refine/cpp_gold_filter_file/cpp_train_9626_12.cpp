#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n, m, j, re0 = -N, re1 = N;
int a[N], b[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  re0 = 2 * n;
  re1 = 2 * m;
  for (int i = 1; i <= n; i++) {
    int v = a[i] - 1;
    while (j <= m && b[j] <= v) j++;
    int p1 = (i - 1) * 2 + (n - i + 1) * 3;
    int p2 = (j - 1) * 2 + (m - j + 1) * 3;
    if (p1 - p2 > re0 - re1)
      re0 = p1, re1 = p2;
    else if (p1 - p2 == re0 - re1 && p1 > re0)
      re0 = p1, re1 = p2;
  }
  printf("%d:%d\n", re0, re1);
  return 0;
}
