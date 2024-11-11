#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010];
int cmp(int x, int y) { return x > y; }
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
  sort(a, a + n, cmp);
  sort(b, b + m, cmp);
  int sa = 0, sb = 0;
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (a[i] > b[j])
      sa++, i++;
    else if (a[i] < b[j])
      sb++, j++;
    else
      i++, j++;
    if (sa > sb) break;
  }
  if (n > m || sa > sb)
    puts("YES");
  else
    puts("NO");
  return 0;
}
