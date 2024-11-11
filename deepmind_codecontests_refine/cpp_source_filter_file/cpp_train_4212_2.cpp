#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long double a[100], ans = 0, cur, temp;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%Lf", &a[i]);
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    cur = 0;
    for (int j = i; j < n; j++) {
      temp = 1;
      for (int k = i; k < n; k++)
        if (k == j)
          temp *= a[k];
        else
          temp *= (1 - a[k]);
      cur += temp;
    }
    ans = max(ans, cur);
  }
  printf("%.10Lf", ans);
}
