#include <bits/stdc++.h>
using namespace std;
int n, k, a[100010], mx = -1;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    mx = max(mx, a[i]);
  }
  int x = 2 * (n - k);
  for (int i = 0; i < (n - k); ++i) mx = max(mx, a[i] + a[x - i - 1]);
  printf("%d", mx);
  return 0;
}
