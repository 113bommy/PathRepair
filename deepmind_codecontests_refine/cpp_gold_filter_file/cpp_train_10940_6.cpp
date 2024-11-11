#include <bits/stdc++.h>
using namespace std;
inline int rd() {
  int x = 0, fl = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') fl = -fl;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * fl;
}
int num = 0, ans = 0, n, m, hd[1001000], a[1001000], ex[1001000];
struct star {
  int nt, to;
} e[1001000];
void add(int fm, int to) {
  e[++num].to = to;
  e[num].nt = hd[fm];
  hd[fm] = num;
}
int main() {
  n = rd();
  m = rd();
  int x, y;
  for (int i = 1; i <= m; i++) {
    x = rd();
    y = rd();
    add(x, y);
  }
  for (int i = 1; i <= n; i++)
    if (!a[i]) {
      for (int j = hd[i]; j; j = e[j].nt) a[e[j].to] = 1;
      a[i] = ex[i] = 1;
    }
  for (int i = n; i >= 1; i--)
    if (ex[i]) {
      for (int j = hd[i]; j; j = e[j].nt) ex[e[j].to] = 0;
    }
  for (int i = 1; i <= n; i++)
    if (ex[i]) ans++;
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++)
    if (ex[i]) printf("%d ", i);
  return 0;
}
