#include <bits/stdc++.h>
using namespace std;
bool isGeometrical(int *a, int n) {
  if (a[0] == 0) {
    for (int i = 0; i < n; i++)
      if (a[i] != 0) return false;
    return true;
  }
  for (int i = 0; i < n - 1; i++)
    if (a[i + 1] * a[0] != a[i] * a[1]) return false;
  return true;
}
int main() {
  int n;
  scanf("%d", &n);
  int a[100000], num0 = 0, pos0 = -1;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    if (a[i] == 0) {
      num0++;
      if (pos0 == -1) pos0 = i;
    }
  }
  if (n <= 2) {
    printf("%d\n", isGeometrical(a, n) ? 0 : 1);
    return 0;
  }
  if (n == 3) {
    int ans = 2;
    if (isGeometrical(a, n))
      ans = 0;
    else {
      int b[2];
      b[0] = a[0], b[1] = a[1];
      if (isGeometrical(b, 2)) ans = 1;
      b[0] = a[0], b[1] = a[2];
      if (isGeometrical(b, 2)) ans = 1;
      b[0] = a[1], b[1] = a[2];
      if (isGeometrical(b, 2)) ans = 1;
    }
    printf("%d\n", ans);
    return 0;
  }
  if (num0 >= 2) {
    int cnt = 0;
    for (int i = 1; i < n; i++)
      if (a[i] != 0) cnt++;
    printf("%d\n", min(cnt, 2));
    return 0;
  }
  if (num0 == 1) {
    for (int i = pos0; i < n - 1; i++) a[pos0] = a[pos0 + 1];
    printf("%d\n", isGeometrical(a, n - 1) ? 1 : 2);
    return 0;
  }
  if (isGeometrical(a, n)) {
    puts("0");
    return 0;
  }
  if (isGeometrical(a + 1, n - 1)) {
    puts("1");
    return 0;
  }
  swap(a[0], a[1]);
  if (isGeometrical(a + 1, n - 1)) {
    puts("1");
    return 0;
  }
  swap(a[0], a[1]);
  int cnt = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i + 1] * a[0] != a[i] * a[1]) {
      cnt++;
      a[i + 1] = a[i];
    }
    if (cnt == 2) break;
  }
  printf("%d\n", cnt);
  return 0;
}
