#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
void reloc() {
  freopen("/Users/admin/Desktop/cards.in", "r", stdin);
  freopen("/Users/admin/Desktop/cards.out", "w", stdout);
  return;
}
void getarr(int *a, int n) {
  if (n == 1) {
    a[1] = 1;
    return;
  }
  if (n == 2) {
    a[1] = 3;
    a[2] = 4;
    return;
  }
  if (n % 2) {
    a[1] = 2;
    for (int i = 1; i < n; i++) a[i] = 1;
    a[n] = (n + 1) / 2;
  } else {
    for (int i = 1; i < n; i++) a[i] = 1;
    a[n] = (n - 2) / 2;
  }
  return;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int a[maxn + 1], b[maxn + 1];
  getarr(a, n);
  getarr(b, m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d", a[i] * b[j]);
      if (j != m)
        printf(" ");
      else
        printf("\n");
    }
  }
  return 0;
}
