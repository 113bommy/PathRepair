#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, s1, s2, a[N];
bool check(int k) {
  int l = a[n] - k, r = a[n] + k;
  for (int i = n - 1; i; i--) {
    if (a[i] >= l && a[i] <= r)
      l = a[i] - k, r = a[i] + k;
    else
      l = max(l, a[i] - k), r = min(r, a[i] + k);
  }
  if ((l <= s1 && s1 <= r) || (l <= s2 && s2 <= r))
    return true;
  else
    return false;
}
int main() {
  scanf("%d%d%d", &n, &s1, &s2);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int l = abs(s1 - s2), r = 1e9;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", l);
  return 0;
}
