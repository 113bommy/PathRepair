#include <bits/stdc++.h>
using namespace std;
int n, a[500010], x, sz;
long long ans;
int main() {
  scanf("%d", &n);
  for (int step = 1; step <= n; step++) {
    scanf("%d", &x);
    while (a[sz - 1] >= a[sz] && a[sz] < x && sz >= 2) {
      ans += min(a[sz - 1], x);
      sz--;
    }
    a[++sz] = x;
  }
  sort(a + 1, a + sz + 1);
  for (int i = 1; i <= sz - 2; i++) ans += a[i];
  printf("%I64d", ans);
}
