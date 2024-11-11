#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, count;
  long long l, u;
  scanf("%d", &n);
  long long int a[n];
  long long int h[n];
  for (i = 0; i < n; ++i) {
    cin >> a[i] >> h[i];
  }
  l = a[0];
  h[n - 1] = 0;
  h[0] = 0;
  u = a[n - 1];
  if (n > 1) {
    count = 2;
    for (i = 1; i < n - 1; ++i) {
      if (a[i] - h[i] > l) {
        count++;
        l = a[i];
      } else {
        if (a[i] + h[i] < a[i + 1]) {
          l = a[i] + h[i];
          count++;
        }
        l = a[i];
      }
    }
  } else
    count = 1;
  printf("%d\n", count);
  return 0;
}
