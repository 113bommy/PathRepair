#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int a[100005], b[100005], c[100005];
int main() {
  int n, m, i, j, sign;
  while (scanf("%d", &n) != EOF) {
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    sign = 0;
    for (i = 1; i <= n; i++) {
      if (a[i] != a[a[i]]) {
        sign = 1;
        break;
      }
    }
    if (sign == 1) {
      puts("-1");
      continue;
    }
    m = 0;
    mp.clear();
    for (i = 1; i <= n; i++) {
      if (mp[a[i]] == 0) {
        m++;
        c[m] = a[i];
        mp[a[i]] = m;
      }
      b[i] = mp[a[i]];
    }
    printf("%d\n", m);
    for (i = 1; i <= n; i++) {
      if (i != 1) printf(" ");
      printf("%d", b[i]);
    }
    printf("\n");
    for (i = 1; i <= m; i++) {
      if (i != 1) printf(" ");
      printf("%d", c[i]);
    }
    printf("\n");
  }
  return 0;
}
