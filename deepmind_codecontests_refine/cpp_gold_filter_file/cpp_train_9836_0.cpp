#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m = -1, z = 0, x, t, c, b, k;
  long long sum = 0;
  int arr[200010];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &arr[i], &x);
    sum += arr[i];
    if (m <= x) {
      z = m;
      b = c;
      m = x;
      c = i;
    } else if (x >= z) {
      z = x;
      b = i;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i == c) {
      t = z;
      k = b;
    } else {
      t = m;
      k = c;
    }
    sum -= arr[i];
    printf("%I64d ", sum * t);
    sum += arr[i];
  }
  return 0;
}
