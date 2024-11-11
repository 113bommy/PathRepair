#include <bits/stdc++.h>
using namespace std;
const int mxn = 1010;
int n, a[mxn], h, k, t[mxn];
bool check(int m) {
  for (int i = 0; i < m; ++i) t[i] = a[i];
  sort(t, t + m);
  int H = 0;
  for (int i = m - 1; i >= 0; i -= 2) H += t[i];
  return H <= h;
}
int main() {
  scanf("%d%d", &n, &h);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  int l = 0, r = n;
  while (l <= r) {
    int m = l + r >> 1;
    if (check(m))
      k = m, l = m + 1;
    else
      r = m - 1;
  }
  printf("%d\n", k);
}
