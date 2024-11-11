#include <bits/stdc++.h>
using namespace std;
char a[2010], b[2010], c[2010];
int aa[256], bb[256];
int n;
void _reverse(char *a, int l) {
  for (int i = 0; i < l; i++) c[i] = a[i];
  for (int i = 0; i < l; i++) a[i] = c[l - 1 - i];
}
void _rotate(char *a, int p) {
  for (int i = 0; i < p; i++) c[n - p + i] = a[i];
  for (int i = 0; i < n - p; i++) c[i] = a[p + i];
  for (int i = 0; i < n; i++) a[i] = c[i];
}
int main() {
  scanf("%d%s%s", &n, a, b);
  for (int i = 0; i < n; i++) {
    aa[a[i]]++;
    bb[b[i]]++;
  }
  for (int i = 0; i < 256; i++)
    if (aa[i] != bb[i]) {
      printf("-1\n");
      return 0;
    }
  printf("%d\n", 3 * n);
  for (int i = 0; i < n; i++) {
    int j;
    _reverse(a, n);
    for (j = 0; j < n; j++)
      if (a[j] == b[n - 1 - i]) break;
    printf("%d %d %d ", n, n - j - 1, 1);
    _reverse(a + j + 1, n - j - 1);
    _rotate(a, j + 1);
    _rotate(a, n - 1);
  }
}
