#include <bits/stdc++.h>
using namespace std;
int a[100020], p[100020], o[100020];
inline bool cmp(const int x, const int y) { return a[x] < a[y]; }
int main(void) {
  int n, m;
  int i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (i = 1; i <= n; i++) p[i] = i;
  sort(p + 1, p + n + 1, cmp);
  for (i = 1, m = 0; i <= n; i = j) {
    for (j = i; a[p[i]] == a[p[j]]; j++) o[p[i]] = max(m - p[i], 0) - 1;
    for (j = i; a[p[i]] == a[p[j]]; j++) m = max(m, p[i]);
  }
  for (i = 1; i <= n; i++) printf("%d ", o[i]);
  return 0;
}
