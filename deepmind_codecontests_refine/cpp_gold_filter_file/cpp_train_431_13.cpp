#include <bits/stdc++.h>
using namespace std;
const int N = 500005 * 3;
int match[N], ans[N];
int main() {
  int ncase, n, m;
  scanf("%d", &ncase);
  while (ncase--) {
    scanf("%d%d", &n, &m);
    int nn = 3 * n;
    for (int i = 1; i <= nn; i++) match[i] = 0;
    int nmatch = 0;
    for (int i = 1, x, y; i <= m; i++) {
      scanf("%d%d", &x, &y);
      if (!match[x] && !match[y]) {
        nmatch++;
        match[x] = y;
        match[y] = x;
        ans[nmatch] = i;
      }
    }
    if (nmatch >= n) {
      printf("Matching\n");
      for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
    } else {
      printf("IndSet\n");
      for (int i = 1, j = 0; i <= nn && j < n; i++)
        if (!match[i]) {
          ++j;
          printf("%d%c", i, " \n"[j == n]);
        }
    }
  }
  return 0;
}
