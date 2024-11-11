#include <bits/stdc++.h>
using namespace std;
int a[55], b[55], s[55];
int main() {
  int t;
  scanf("%d", &t);
  for (int i = 2; i <= t; i++) {
    scanf("%d", &a[i]);
    a[i] += a[i - 1];
  }
  for (int i = 1; i < t; i++) scanf("%d", &b[i]);
  for (int i = t - 2; i >= 1; i--) b[i] += b[i + 1];
  for (int i = 1; i <= t; i++) scanf("%d", &s[i]);
  int res = 50050;
  for (int i = 1; i <= t; i++) {
    for (int j = 1; j <= t; j++) {
      if (i == j) continue;
      int sum = a[i] + b[i] + s[i];
      sum += a[j] + b[j] + s[j];
      res = min(res, sum);
    }
  }
  printf("%d\n", res);
  return 0;
}
