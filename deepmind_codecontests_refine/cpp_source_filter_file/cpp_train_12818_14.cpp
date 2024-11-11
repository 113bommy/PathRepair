#include <bits/stdc++.h>
using namespace std;
int arr[105];
int main() {
  int n, x, y, ans = 0;
  scanf("%d%d%d", &n, &x, &y);
  for (int i = 1; i <= n; ++i) scanf("%d", &arr[i]);
  if (x > y) {
    printf("%d\n", n);
    return 0;
  } else if (x <= y) {
    if (n == 1) {
      if (arr[1] <= x) {
        printf("1\n");
        return 0;
      } else {
        printf("0\n");
        return 0;
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (arr[i] <= y) ans++;
    }
    printf("%d\n", ans / 2 + (ans & 1));
  }
  return 0;
}
