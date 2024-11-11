#include <bits/stdc++.h>
using namespace std;
int cmp_double(const double a, const double b, const double eps) {
  if (a + eps < b) return -1;
  if (a > b + eps) return 1;
  return 0;
}
int n, a[4096];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (n - i - 1); ++j) {
      if (a[j] > a[j + 1]) {
        ++ans;
        swap(a[j], a[j + 1]);
      }
    }
  }
  printf("%d\n", max(2 * ans - n % 2, 0));
  return 0;
}
