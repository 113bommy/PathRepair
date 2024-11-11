#include <bits/stdc++.h>
using namespace std;
int a[111111];
int b[111111];
int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  sort(a, a + n);
  sort(b, b + n);
  reverse(b, b + n);
  int ia = 0, ib = 0;
  int w = 0;
  while (ia < n && ib < n) {
    if (a[ib] >= x) {
      ib++;
      w++;
      continue;
    }
    if (a[ib] + a[ia] >= x) {
      ib++;
      ia++;
      w++;
      continue;
    }
    ia++;
  }
  cout << 1 << " " << w;
  return 0;
}
