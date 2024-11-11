#include <bits/stdc++.h>
using namespace std;
int a[1005];
long long solve(int t) {
  for (int i = 0; i <= t; i++) {
    for (int j = 0; j + i <= t; j++) {
      for (int k = 0; k + i + j <= t; k++) {
        a[i + j * 5 + k * 10 + (t - i - j - k) * 50] = 1;
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= 1000; i++) ans += a[i];
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  printf("%lld\n", solve(min(n, 20)) + max(0, n - 20) * 1ll * 49);
  return 0;
}
