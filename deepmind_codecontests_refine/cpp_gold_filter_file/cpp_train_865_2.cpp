#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, c;
  int a[1100], b[1100];
  scanf("%d%d%d", &n, &m, &c);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < m; i++) scanf("%d", &b[i]);
  for (int i = 0; i < n - m + 1; i++) {
    for (int j = 0; j < m; j++) {
      a[j + i] = (a[i + j] + b[j]) % c;
    }
  }
  for (int i = 0; i < n; i++) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
