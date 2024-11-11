#include <bits/stdc++.h>
const int N = 2005;
using namespace std;
bitset<N> f[N];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int t;
      scanf("%d", &t);
      if (t > 0) f[i][j] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      if (f[i][j]) {
        f[i] |= f[j];
      }
  }
  for (int i = 1; i <= n; i++) {
    if (f[i].count() != n) {
      printf("NO");
      return 0;
    }
  }
  printf("YES");
  return 0;
}
