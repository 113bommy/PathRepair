#include <bits/stdc++.h>
using namespace std;
int i, j, k, m, n, t, cc;
int b[302], c[302];
char a[302][302], s;
int find(int x) { return x == c[x] ? x : c[x] = find(c[x]); }
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) c[i] = i;
  for (i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
  }
  for (i = 1; i <= n; i++) {
    getchar();
    for (j = 1; j <= n; j++) {
      scanf("%c", &a[i][j]);
      if (a[i][j] == '1') {
        c[find(i)] = c[find(j)];
      }
    }
  }
  bool ok = 0;
  do {
    ok = 0;
    for (i = 1; i < n; i++) {
      for (j = i + 1; j <= n; j++) {
        if (b[i] > b[j] && (find(i) == find(j))) {
          swap(b[i], b[j]);
          ok = 1;
        }
      }
    }
  } while (ok == 1);
  for (i = 1; i <= n; i++) {
    if (i != n)
      printf("%d ", b[i]);
    else
      printf("%d\n", b[i]);
  }
  return 0;
}
