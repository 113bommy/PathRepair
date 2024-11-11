#include <bits/stdc++.h>
using namespace std;
const int X = 500010;
int a[X], n;
bool check(int k) {
  int i;
  for (i = 0; i < k; i++)
    if (a[i] * 2 > a[n - k + i]) return 0;
  return 1;
}
int main() {
  int i, j, m, k, as = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  int l = 0, r = n / 2 + 1, mid;
  while (l < r) {
    mid = l + r >> 1;
    if (check(mid))
      l = mid + 1;
    else
      r = mid;
  }
  printf("%d\n", n - r + 1);
  return 0;
}
