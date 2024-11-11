#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long r = 0, t = 1, c = getchar();
  while (c < '0' || c > '9') {
    t = c == '-' ? -1 : 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    r = (r << 3) + (r << 1) + (c ^ 48);
    c = getchar();
  }
  return r * t;
}
long long n, k, t[100 << 3], s;
int main() {
  n = read();
  k = read();
  int m = 0;
  for (int i = (0), _end_ = (62); i <= _end_; i++)
    if (n & (1ll << i)) {
      s++;
      m = i + 100;
      t[i + 100] = 1;
    }
  if (s > k) {
    printf("No\n");
    return 0;
  }
  s = k - s;
  int d = 0;
  while (s >= t[m]) {
    s -= t[m];
    t[m - 1] += t[m] << 1;
    t[m] = 0;
    m--;
  }
  for (int i = (0), _end_ = (m); i <= _end_; i++)
    if (t[i]) {
      t[i]--;
      d = i;
      break;
    }
  printf("Yes\n");
  for (int i = (m), _end_ = (0); i >= _end_; i--)
    for (int j = (1), _end_ = (t[i]); j <= _end_; j++) printf("%d ", i - 100);
  d--;
  if (!s) {
    printf("%d\n", d - 100 + 1);
    return 0;
  }
  while (s) {
    printf("%d ", d - 100);
    s--;
    if (!s) printf("%d\n", d - 100);
    d--;
  }
  return 0;
}
