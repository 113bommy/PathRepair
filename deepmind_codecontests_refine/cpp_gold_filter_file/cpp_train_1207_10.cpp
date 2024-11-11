#include <bits/stdc++.h>
const int mod = 1000;
const double eps = 1e-6;
const double pi = acos(-1);
const int inf = 0x7fffffff;
using namespace std;
int a[1005];
int main() {
  int n;
  long long int k;
  scanf("%d%lld", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (2 * k >= a[i]) {
      if (a[i] > k) k = a[i];
      continue;
    }
    while (2 * k < a[i]) k = k * 2, ans++;
    if (a[i] > k) k = a[i];
  }
  printf("%d\n", ans);
  return 0;
}
