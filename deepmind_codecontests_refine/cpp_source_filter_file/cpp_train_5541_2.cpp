#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100000], b[100000];
map<string, int> f;
int main() {
  int nc, i, x, y;
  char s[100];
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; ++i) scanf("%d", &a[i]);
  nc = 0;
  f.clear();
  memset(b, 0, sizeof(b));
  for (i = 0; i < m; ++i) {
    scanf("%s", s);
    if (!f[s]) f[s] = ++nc;
    ++b[nc - 1];
  }
  m = nc;
  sort(a, a + n);
  sort(b, b + m);
  x = y = 0;
  for (i = 0; i < m; ++i) {
    x += a[i] * b[m - 1 - i];
    y += a[n - 1 - i] * b[m - 1 - i];
  }
  printf("%d %d\n", x, y);
  return 0;
}
