#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a[100000], b[100000] = {}, min = 1e9, ans = 0;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[i % k] += a[i];
  }
  for (int i = 0; i < k; i++) {
    if (min > b[i]) {
      min = b[i];
      ans = i;
    }
  }
  printf("%d", ans + 1);
  return 0;
}
