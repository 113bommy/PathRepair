#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int maxn = 2e6 + 10;
int n, a[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  long long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      ans += a[i] - a[i + 1];
      a[i + 1] = a[i];
    }
  }
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] + 1 < a[i + 1]) {
      ans += a[i + 1] - a[i] - 1;
      a[i] = a[i + 1] - 1;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
