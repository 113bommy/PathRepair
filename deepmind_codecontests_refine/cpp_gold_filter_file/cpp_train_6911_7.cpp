#include <bits/stdc++.h>
using namespace std;
int a[32], b[32];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int v;
  for (int i = 0; i < n; i++) {
    scanf("%d", &v);
    for (int j = 0; j < 32; j++) {
      if (v & (1 << j)) a[j]++;
    }
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &v);
    b[v]++;
  }
  int i = 0, c = 0;
  while (1) {
    i = 0;
    while (i < 32 && !b[i]) i++;
    b[i]--;
    while (i < 32 && !a[i]) {
      a[i]++;
      i++;
    }
    if (i == 32) break;
    a[i]--;
    c++;
  }
  printf("%d\n", c);
  return 0;
}
