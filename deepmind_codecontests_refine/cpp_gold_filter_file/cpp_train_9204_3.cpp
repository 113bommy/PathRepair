#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[1005], n, k, ans1 = 0, ans2 = 0, t, s, l = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &k);
    t = k / 2;
    for (int j = 1; j <= t; j++) {
      scanf("%d", &s);
      ans1 += s;
    }
    if (k % 2 != 0) {
      scanf("%d", &s);
      l++;
      a[l] = s;
    }
    for (int j = 1; j <= t; j++) {
      scanf("%d", &s);
      ans2 += s;
    }
  }
  sort(a + 1, a + l + 1);
  for (int i = l; i >= 1; i--) {
    if ((l - i + 1) % 2 == 1)
      ans1 += a[i];
    else
      ans2 += a[i];
  }
  printf("%d %d\n", ans1, ans2);
  return 0;
}
