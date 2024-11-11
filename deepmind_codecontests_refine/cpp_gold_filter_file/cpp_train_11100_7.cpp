#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long k;
  scanf("%d", &n);
  scanf("%I64d", &k);
  int a;
  scanf("%d", &a);
  int ans = a;
  int count = 0;
  if (k > n - 2) {
    for (int i = 1; i < n; ++i) {
      scanf("%d", &a);
      if (a > ans) ans = a;
    }
  } else {
    for (int i = 1; i < n; ++i) {
      scanf("%d", &a);
      if (count == k) break;
      if (ans > a)
        count++;
      else {
        count = 1;
        ans = a;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
