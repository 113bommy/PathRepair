#include <bits/stdc++.h>
using namespace std;
int a[100005], b[100005], p[100005], s[100005], n, m;
bool cmp(const int i, const int j) { return s[i] < s[j]; }
int main() {
  scanf("%d", &n), m = (n + 2) / 3, puts("YES");
  for (int i = 0; i < n; i++) scanf("%d", s + i), p[i] = i;
  sort(p, p + n, cmp);
  for (int i = 0; i < m; i++) a[p[i]] = i, b[p[i]] = s[p[i]] - a[p[i]];
  for (int i = m; i < m + m; i++) b[p[i]] = i, a[p[i]] = s[p[i]] - b[p[i]];
  for (int i = m + m; i < n; i++)
    b[p[i]] = n - i - 1, a[p[i]] = s[p[i]] - b[p[i]];
  for (int i = 0; i < n; i++) printf("%d%s", a[i], i < n - 1 ? " " : "\n");
  for (int i = 0; i < n; i++) printf("%d%s", b[i], i < n - 1 ? " " : "\n");
  return 0;
}
