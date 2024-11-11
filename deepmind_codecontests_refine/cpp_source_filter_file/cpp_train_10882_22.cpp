#include <bits/stdc++.h>
using namespace std;
int m, n, nr, afis[100000], v[77500], ct;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &nr);
    if (nr < 77500) v[nr] = 1;
  }
  for (int i = 1; i <= 77500; ++i) {
    if (m - i < 0) break;
    if (v[i] == 0) {
      v[i] = 1;
      ++ct;
      afis[ct] = i;
      m -= i;
    }
  }
  printf("%d\n", ct);
  for (int i = 1; i <= ct; ++i) {
    printf("%d ", afis[i]);
  }
}
