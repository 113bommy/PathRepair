#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105];
int s = 0;
int test(int x) {
  int s0 = s;
  int t = n - 1;
  for (int i = n - x - 1; i >= 0; i--) {
    int d = min(a[t], (i / x + 1));
    t--;
    s0 -= d;
  }
  return s0 >= m;
}
int main() {
  scanf("%d%d", &n, &m);
  int l = 1, r = n + 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    s += a[i];
  }
  sort(a, a + n);
  while (l < r) {
    int mid = (l + r) / 2;
    if (test(mid))
      r = mid;
    else
      l = mid + 1;
  }
  if (l == n + 1)
    puts("-1");
  else
    printf("%d\n", l);
  return 0;
}
