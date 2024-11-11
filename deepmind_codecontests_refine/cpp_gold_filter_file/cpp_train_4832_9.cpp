#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[2000001];
int main() {
  int minv = 2000000;
  int maxv = 0;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    int s;
    scanf("%d", &s);
    a[s]++;
    minv = min(minv, s);
    maxv = max(maxv, s);
  }
  for (int i = 1; i <= 2000000; ++i) {
    a[i] += a[i - 1];
  }
  if (minv <= k + 1) {
    printf("%d\n", minv);
  } else {
    for (int d = minv; d >= k + 1; --d) {
      int count = 0;
      for (int j = d; j <= maxv; j += d) {
        count += a[j + k] - a[j - 1];
      }
      if (count == n) {
        printf("%d\n", d);
        return 0;
      }
    }
    printf("1\n");
  }
  return 0;
}
