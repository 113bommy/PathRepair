#include <bits/stdc++.h>
using namespace std;
long long a[505];
int main() {
  int n;
  scanf("%d", &n);
  long long value = 0;
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  if (n >= 3) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i == j) continue;
        for (int k = 1; k <= n; k++) {
          if (i == k || j == k) continue;
          if (value < ((a[i] | a[j]) | a[k])) value = (a[i] | a[j]) | a[k];
        }
      }
    }
    printf("%lld", value);
  } else {
    if (n == 1)
      printf("%lld\n", a[1]);
    else
      printf("%lld\n", a[1] | a[2]);
  }
}
