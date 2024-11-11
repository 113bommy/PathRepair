#include <bits/stdc++.h>
using namespace std;
int n, a, b, v[105], s = 0;
int main() {
  cin >> n >> a >> b;
  if (n == 1) {
    printf("1\n");
    return 0;
  }
  if (b == 0 && a == 0) {
    for (int i = 1; i <= n; i++) printf("1 ");
    return 0;
  }
  if (b == 0) {
    if (a > n - 2) {
      printf("-1");
      return 0;
    }
    v[1] = 1;
    v[2] = 1;
    for (int i = 3; i <= a + 3; i++) v[i] = v[i - 1] + 1;
    for (int i = a + 3; i <= n; i++) v[i] = 1;
    for (int i = 1; i <= n; i++) printf("%d ", v[i]);
    return 0;
  }
  v[1] = 1;
  s = v[1];
  int i = 2;
  while (i <= b + 1) {
    v[i] = s + 1;
    s += v[i];
    ++i;
  }
  if (a != 0) {
    while (i <= a + b + 1) {
      v[i] = v[i - 1] + 1;
      ++i;
    }
    while (i <= n) {
      v[i] = 1;
      ++i;
    }
  }
  while (i <= n) {
    v[i] = 1;
    ++i;
  }
  for (int i = 1; i <= n; i++) printf("%d ", v[i]);
  return 0;
}
