#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[300000] = {0}, i, sum = 0, ans = 0, s1, s2, b[300000];
  int temp;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  temp = sum % n;
  for (i = 0; i < n; i++) {
    if (i >= n - temp)
      b[i] = (sum / n) + 1;
    else
      b[i] = sum / n;
  }
  sort(a, a + n);
  for (i = 0; i < n; i++) {
    ans += abs(b[i] - a[i]);
  }
  printf("%d\n", ans / 2);
  return 0;
}
