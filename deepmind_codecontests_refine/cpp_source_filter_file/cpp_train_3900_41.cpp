#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  scanf("%lld", &n);
  long long int a[n][n];
  map<long long int, long long int> dial, diar;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < n; j++) {
      scanf("%lld", &a[i][j]);
      dial[i - j] += a[i][j];
      diar[i + j] += a[i][j];
    }
  }
  long long int ma = 0;
  long long int x = -1, y = -1;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < n; j++) {
      if (ma < (dial[i - j] + diar[i + j] - a[i][j])) {
        ma = (dial[i - j] + diar[i + j] - a[i][j]);
        x = i;
        y = j;
      }
    }
  }
  long long int ma2 = 0;
  long long int x1 = -1, y1 = -1;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < n; j++) {
      if (ma2 < (dial[i - j] + diar[i + j] - a[i][j]) && (i != x || j != y) &&
          ((i + j) % 2 != (x + y) % 2) && ((i - j) % 2 != (x - y) % 2)) {
        ma2 = (dial[i - j] + diar[i + j] - a[i][j]);
        x1 = i;
        y1 = j;
      }
    }
  }
  if (x1 == -1 || y1 == -1) {
    x1 = x;
    y1 = y + 1;
  }
  printf("%lld\n%lld %lld %lld %lld", ma2 + ma, x + 1, y + 1, x1 + 1, y1 + 1);
  return 0;
}
