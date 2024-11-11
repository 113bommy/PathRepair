#include <bits/stdc++.h>
using namespace std;
long long int MAX(long long int x, long long int y) {
  if (x > y) return x;
  return y;
}
int main() {
  int n, m;
  cin >> n >> m;
  long long int a[n][2], b[m][2];
  long long int c[1000000 + 1] = {0};
  for (int i = 0; i < n; ++i) cin >> a[i][0] >> a[i][1];
  for (int i = 0; i < m; ++i) cin >> b[i][0] >> b[i][1];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (b[j][0] >= a[i][0]) {
        c[b[j][0] - a[i][0]] = MAX(c[b[j][0] - a[i][0]], b[j][1] - a[i][1] + 1);
      }
    }
  }
  long long int max = c[1000000];
  for (int i = 1000000; i > -1; --i) {
    if (max < c[i]) max = c[i];
    c[i] = max;
  }
  long long int min = 10000000000000;
  for (int i = 0; i < 1000000 + 1; ++i) {
    if (c[i] + i < min) min = c[i] + i;
  }
  printf("%lld\n", min);
}
