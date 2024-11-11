#include <bits/stdc++.h>
using namespace std;
int sum[5];
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    char a[3009][15], b[3009][15], s[15];
    int c[3009];
    for (int i = 0; i < m; i++) {
      scanf("%s%s", a[i], b[i]);
      int lena = strlen(a[i]);
      int lenb = strlen(b[i]);
      c[i] = lena - lenb;
    }
    for (int i = 0; i < n; i++) {
      scanf("%s", s);
      for (int j = 0; j < m; j++) {
        int k = strcmp(s, a[j]);
        int k1 = strcmp(s, b[j]);
        if (k == 0 || k1 == 0) {
          if (i != 0) printf(" ");
          if (c[i] <= 0)
            printf("%s", a[j]);
          else
            printf("%s", b[j]);
          break;
        }
      }
    }
    printf("\n");
  }
  return 0;
}
