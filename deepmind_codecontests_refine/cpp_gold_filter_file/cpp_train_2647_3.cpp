#include <bits/stdc++.h>
const int MAXN = 110;
bool b[MAXN], c[MAXN];
int main() {
  int n;
  scanf("%d", &n);
  int cntx = 0, cnty = 0;
  memset(b, false, sizeof(b));
  memset(c, false, sizeof(c));
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (!b[x]) {
      b[x] = true;
      cntx++;
    }
    if (!c[y]) {
      c[y] = true;
      cnty++;
    }
  }
  if (cntx <= cnty)
    printf("%d\n", cntx);
  else
    printf("%d\n", cnty);
  return 0;
}
