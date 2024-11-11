#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010000;
int n, m;
struct edge {
  int u, v, c;
} e[MAXN];
char s[MAXN];
int f[MAXN], book[MAXN], ans[MAXN];
void init() {
  for (int i = 1; i <= n; i++) f[i] = i;
}
int find(int x) {
  if (f[x] != x) f[x] = find(f[x]);
  return f[x];
}
int main() {
  scanf("%d%d", &n, &m);
  if (n % 2 == 0) {
    printf("-1");
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &e[i].u, &e[i].v);
    scanf("%s", s);
    if (s[0] == 'S')
      e[i].c = 0;
    else
      e[i].c = 1;
  }
  init();
  int cs = 0, cm = 0;
  for (int i = 1; i <= m; i++)
    if (e[i].c == 0)
      if (find(e[i].u) != find(e[i].v)) f[find(e[i].u)] = find(e[i].v), cs++;
  if (cs < (n - 1) / 2) {
    printf("-1");
    return 0;
  }
  for (int i = 1; i <= m; i++)
    if (e[i].c == 1)
      if (find(e[i].u) != find(e[i].v))
        f[find(e[i].u)] = find(e[i].v), cm++, book[i] = 1;
  if (cs + cm < n - 1) {
    printf("-1");
    return 0;
  }
  init();
  for (int i = 1; i <= m; i++)
    if (book[i] == 1)
      if (find(e[i].u) != find(e[i].v))
        f[find(e[i].u)] = find(e[i].v), ans[i] = 1;
  for (int i = 1; i <= m; i++)
    if (book[i] == 0 && e[i].c == 1)
      if (find(e[i].u) != find(e[i].v)) {
        f[find(e[i].u)] = find(e[i].v);
        cm++;
        ans[i] = 1;
        if (cm == (n - 1) / 2) break;
      }
  if (cm < (n - 1) / 2) {
    printf("-1");
    return 0;
  }
  for (int i = 1; i <= m; i++)
    if (e[i].c == 0)
      if (find(e[i].u) != find(e[i].v)) {
        f[find(e[i].u)] = find(e[i].v);
        ans[i] = 1;
      }
  printf("%d\n", n - 1);
  for (int i = 1; i <= m; i++)
    if (ans[i]) printf("%d ", i);
  return 0;
}
