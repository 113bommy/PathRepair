#include <bits/stdc++.h>
using namespace std;
int sign[17];
int main() {
  int n, m, x;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    int f = 0;
    for (int j = 0; j < m; j++) {
      scanf("%d", &x);
      if (x) f |= (1 << j);
    }
    sign[f] = 1;
  }
  for (int i = 0; i < 16; i++) {
    for (int j = i; j < 16; j++) {
      if (!(i & j) && sign[i] && sign[j]) {
        printf("YES\n");
        return 0;
      }
    }
  }
  printf("NO\n");
  return 0;
}
