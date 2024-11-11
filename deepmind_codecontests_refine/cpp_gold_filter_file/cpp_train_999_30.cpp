#include <bits/stdc++.h>
using namespace std;
int a[300005];
int main() {
  memset(a, 0, sizeof(a));
  int n = 0, total = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    total += a[i] / 1000;
  }
  int x = total * 10 / 11;
  x = min(x, total - a[n - 1] / 1000);
  bool ck = false;
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] == 1000) {
      ck = true;
      break;
    }
  }
  if (!ck && x % 2 == 1) {
    --x;
  }
  int res = total * 1000 - x * 100;
  printf("%d", res);
  return 0;
}
