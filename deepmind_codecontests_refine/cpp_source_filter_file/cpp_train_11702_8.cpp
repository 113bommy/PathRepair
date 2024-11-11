#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 10;
int a[N], n;
int main() {
  fill(a, a + N, N);
  a[0] = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int k;
    scanf("%d", &k);
    int l = 0, r = n, mid = (l + r) / 2;
    while (r - l > 1) {
      if (a[i] < k)
        l = mid;
      else
        r = mid;
      mid = (l + r) / 2;
    }
    if (a[r] < k)
      mid = r;
    else
      mid = l;
    if (k < a[mid + 1]) a[mid + 1] = k;
  }
  int ans = 1;
  while (a[ans] != N) ans++;
  printf("%d\n", ans - 1);
  return 0;
}
