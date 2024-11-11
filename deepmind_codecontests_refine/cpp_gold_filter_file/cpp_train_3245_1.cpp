#include <bits/stdc++.h>
using namespace std;
int a[1005] = {0};
int main() {
  int sum = 0, n, k, t = 0;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a[x]++;
  }
  for (int i = 1; i <= k; i++) {
    if (a[i]) {
      sum += a[i];
      if (a[i] % 2) t++;
    }
  }
  printf("%d\n", sum - t / 2);
  return 0;
}
