#include <bits/stdc++.h>
using namespace std;
int a[100003], b[100003], s[100003], c[100003], ans[100003], sp, cp, ap;
int main() {
  int n, m, x;
  cin >> n >> m;
  for (int i = 0; i < n; i++) scanf("%d", &x), a[x]++;
  for (int i = 0; i < n; i++) scanf("%d", &x), b[m - 1 - x]++;
  for (int i = 0; i < m; i++) {
    while (a[i]--) s[sp++] = i;
    while (b[i]--) {
      if (sp)
        ans[ap++] = m - 1 - i + s[--sp];
      else
        c[cp++] = m - 1 - i;
    }
  }
  for (int i = 0; i < cp; i++) ans[ap++] = c[i] + s[--sp] - m;
  sort(ans, ans + ap);
  for (int i = ap - 1; i >= 0; i--) printf("%d ", ans[i]);
  return 0;
}
