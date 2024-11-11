#include <bits/stdc++.h>
using namespace std;
const int N = int(2e5) + 5;
const int inf = (int)1e9 + 9;
int n;
int a[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 2 * n; ++i) {
    scanf("%d", a + i);
  }
  sort(a + 1, a + 1 + 2 * n);
  long long ans = (a[n] - a[1]) * 1ll * (a[2 * n] - a[n + 1]);
  for (int i = 1; i + n < 2 * n; ++i) {
    ans = min(ans, (a[i + n] - a[i]) * 1ll * (a[2 * n] - a[1]));
  }
  printf("%lld", ans);
  return 0;
}
