#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, ans = 0, a[100001], b[100001], mat[100001];
int main() {
  scanf("%d%d%d%d", &n, &m, &x, &y);
  for (int i = (1); i <= (n); i++) scanf("%d", a + i);
  for (int i = (1); i <= (m); i++) scanf("%d", b + i);
  int p = 1;
  for (int i = (1); i <= (n); i++) {
    while (p <= m && b[p] < a[i] - x) ++p;
    if (p > m || b[p] > a[i] + y) continue;
    ++ans;
    mat[i] = p++;
  }
  printf("%d\n", ans);
  for (int i = (1); i <= (n); i++)
    if (mat[i]) printf("%d %d\n", i, mat[i]);
  return 0;
}
