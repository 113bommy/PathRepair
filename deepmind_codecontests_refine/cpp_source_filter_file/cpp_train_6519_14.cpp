#include <bits/stdc++.h>
using namespace std;
int n, x, y, l, r, i, j, lt, rt, mid;
int a[210000];
int check(int k) {
  lt = -0x3f3f3f3f;
  rt = 0x3f3f3f3f;
  for (int i = n; i >= 1; i--) {
    if (a[i] >= lt && a[i] <= rt)
      lt = a[i] - k, rt = a[i] + k;
    else
      lt = max(lt, a[i] - k), rt = max(rt, a[i] + k);
  }
  return (lt <= x && x <= rt) || (lt <= y && y <= rt);
}
int main() {
  cin >> n >> x >> y;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  l = abs(x - y);
  r = 0x3f3f3f3f;
  while (l < r) {
    mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << l;
  return 0;
}
