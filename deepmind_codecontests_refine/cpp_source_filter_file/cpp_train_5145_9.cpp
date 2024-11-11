#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 * 2 + 1;
int n, a[maxn], cnt;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  int l = n / 2 - 1, r = n - 1;
  while (l >= 0 && r >= l) {
    if (a[l] * 2 <= a[r]) {
      l--, r--, cnt++;
      continue;
    }
    l--;
  }
  printf("%d\n", n - cnt);
  return 0;
}
