#include <bits/stdc++.h>
using namespace std;
struct cmp {
  char a[110];
  char b[110];
} t[1001];
struct bnm {
  char c[110];
  char q[110];
  char f[110];
} p[1001];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s%s", &t[i].a, &t[i].b);
  for (int i = 0; i < m; i++) scanf("%s%s", &p[i].c, &p[i].q);
  for (int i = 0; i < m; i++) {
    int t = 0;
    for (int j = 0; p[i].q[j] != '\0'; j++)
      if (p[i].q[j] != ';') p[i].f[t++] = p[i].q[j];
    p[i].f[t] = '\0';
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++)
      if (strcmp(p[i].f, t[j].b) == 0)
        printf("%d %s #%s\n", p[i].c, p[i].q, t[j].a);
  }
  return 0;
}
