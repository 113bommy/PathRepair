#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[105];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  sort(a, a + n);
  for (int i = 1; i < n; ++i) a[i] += a[i - 1];
  for (int i = n - 2; i >= 0; --i)
    if (a[n - 1] > a[i] * 2) {
      printf("%d\n", n - 1 - i);
      return 0;
    }
  printf("%d\n", n);
}
