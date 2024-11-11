#include <bits/stdc++.h>
using namespace std;
int a[200];
int main() {
  int n, m, two, four, one;
  while (scanf("%d %d", &n, &m) != EOF) {
    for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
    four = n;
    two = n * 2;
    for (int i = 1; i <= m; i++) {
      int tmp = min(four, a[i] / 4);
      four -= tmp;
      a[i] -= tmp * 4;
    }
    two += four;
    for (int i = 1; i <= m; i++) {
      int tmp = min(two, a[i] / 2);
      two -= tmp;
      a[i] -= 2 * two;
    }
    one = two + four;
    for (int i = 1; i <= m; i++) {
      one -= a[i];
    }
    if (one >= 0)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
