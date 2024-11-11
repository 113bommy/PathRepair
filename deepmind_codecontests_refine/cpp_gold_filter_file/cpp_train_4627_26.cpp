#include <bits/stdc++.h>
using namespace std;
int a[2001] = {0};
int main() {
  int n, b;
  scanf("%d%d", &n, &b);
  for (int i = 0; i < (n); i++) {
    scanf("%d", &a[i]);
  }
  int k1 = 0, k2 = 0, mn = 0;
  int res = 0;
  for (int i = 0; i < (n); i++)
    for (int j = i + 1; j < n; j++) {
      if (a[i] < a[j]) {
        res = max(res, (b / a[i]) * a[j] + b % a[i]);
      }
    }
  if (res == 0) {
    printf("%d", b);
  } else
    printf("%d", res);
  return 0;
}
