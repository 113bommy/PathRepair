#include <bits/stdc++.h>
using namespace std;
int n, a[100000], now, Ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 0; i <= n - 1; i++) {
    if (a[i + 1] <= a[i])
      now += a[i] - a[i + 1];
    else {
      now += a[i] - a[i + 1];
      if (now < 0) {
        Ans -= now;
        now = 0;
      }
    }
  }
  printf("%d\n", Ans);
  return 0;
}
